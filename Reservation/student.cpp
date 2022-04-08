/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
 * @Time : 2022/4/7 20:45
 * @Project_Name : Reservation 
 * @File : student.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/7.
//

#include <iostream>
#include "student.h"
#include "globalFile.h"
#include <fstream>
#include "orderFile.h"

using namespace std;

Student::Student() {

}

Student::Student(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;

    ifstream ifs(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "��ʼ�������б�ʧ��" << endl;
        ifs.close();
        return;
    }
    ComputerRoom cr;

    while (ifs >> cr.m_ComId && ifs >> cr.m_MaxNum) {
        vCom.push_back(cr);
    }
    ifs.close();


}

Student::~Student() {

}

void Student::showMenu() {
    cout << "ѧ�� " << this->m_Name << " ,���~" << endl;
    cout << "1. ����ԤԼ" << endl;
    cout << "2. �鿴�ҵ�ԤԼ" << endl;
    cout << "3. �鿴����ԤԼ" << endl;
    cout << "4. ȡ��ԤԼ" << endl;
    cout << "0. ע����¼" << endl;
    cout << "��ѡ��: ";
}

void Student::applyOrder() {
    cout << "��������ʱ��Ϊ��һ������" << endl;
    cout << "1. ��һ" << endl;
    cout << "2. �ܶ�" << endl;
    cout << "3. ����" << endl;
    cout << "4. ����" << endl;
    cout << "5. ����" << endl;
    cout << "��ѡ��: ";

    int date;
    int interval;
    int room;

    while (true) {
        cin >> date;
        if (date > 0 && date < 6) {
            break;
        }
        cout << "�������, ����������: ";
    }
    cout << "1. ����" << endl;
    cout << "2. ����" << endl;
    cout << "��ѡ��ԤԼʱ���:";
    while (true) {
        cin >> interval;
        if (interval > 0 && interval < 3) {
            break;
        }
        cout << "�������, ����������: ";
    }
    cout << "1�Ż�������" << vCom[0].m_MaxNum << endl;
    cout << "2�Ż�������" << vCom[1].m_MaxNum << endl;
    cout << "3�Ż�������" << vCom[2].m_MaxNum << endl;
    cout << "��ѡ�����: ";
    while (true) {
        cin >> room;
        if (room > 0 && room < 4) {
            break;
        }
        cout << "�������, ����������: ";
    }
    cout << "ԤԼ�������ύ, ��ȴ����" << endl;

    ofstream ofs(ORDER_FILE, ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuId:" << this->m_Id << " ";
    ofs << "stuName:" << this->m_Name << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << endl;
    ofs.close();
    system("pause");
}

void Student::showMyOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "��ԤԼ��¼" << endl;
        system("pause");
        return;
    }
    bool flag = true;
    for (int i = 0; i < of.m_Size; ++i) {
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
            flag = false;
            cout << "ԤԼ��¼Id: " << i;
            cout << " ԤԼ����: ��" << of.m_orderData[i]["date"];
            cout << " ʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
            cout << " ����: " << of.m_orderData[i]["roomId"];
            string status = " ״̬: ";
            // 0 ԤԼȡ��   1 �����   2 ��ԤԼ   -1 ԤԼʧ��
            if (of.m_orderData[i]["status"] == "1") {
                status += "�����";
            } else if (of.m_orderData[i]["status"] == "2") {
                status += "ԤԼ�ɹ�";
            } else if (of.m_orderData[i]["status"] == "-1") {
                status += "���δͨ��, ԤԼʧ��";
            } else {
                status += "ԤԼ��ȡ��";
            }
            cout << status << endl;
        }
    }
    if (flag) {
        cout << "����ԤԼ��Ϣ" << endl;
    }

}

void Student::showAllOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "��ԤԼ��¼" << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < of.m_Size; ++i) {
        cout << "ԤԼ��¼Id: " << i;
        cout << " ԤԼ����: ��" << of.m_orderData[i]["date"];
        cout << " ʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
        cout << " ѧ��: " << of.m_orderData[i]["stuId"];
        cout << " ����: " << of.m_orderData[i]["stuName"];
        cout << " ����: " << of.m_orderData[i]["roomId"];
        string status = " ״̬: ";
        // 0 ԤԼȡ��   1 �����   2 ԤԼ�ɹ�   -1 ԤԼʧ��
        if (of.m_orderData[i]["status"] == "1") {
            status += "�����";
        } else if (of.m_orderData[i]["status"] == "2") {
            status += "ԤԼ�ɹ�";
        } else if (of.m_orderData[i]["status"] == "-1") {
            status += "���δͨ��, ԤԼʧ��";
        } else {
            status += "ԤԼ��ȡ��";
        }
        cout << status << endl;
    }
    system("pause");
}

void Student::cancelOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "��ԤԼ��¼" << endl;
        system("pause");
        return;
    }
    bool flag = true;
    vector<int> v; // �洢ԤԼ��¼Id
    int index = 0;
    for (int i = 0; i < of.m_Size; ++i) {
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
                flag = false;
                v.push_back(i);
                cout << ++index << ".";
                cout << " ԤԼ����: ��" << of.m_orderData[i]["date"];
                cout << " ʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
                cout << " ����: " << of.m_orderData[i]["roomId"];
                string status = " ״̬: ";
                // 0 ԤԼȡ��   1 �����   2 ��ԤԼ   -1 ԤԼʧ��
                if (of.m_orderData[i]["status"] == "1") {
                    status += "�����";
                } else {
                    status += "ԤԼ�ɹ�";
                }
                cout << status << endl;
            }

        }
    }
    if (flag) {
        cout << "����ԤԼ��Ϣ" << endl;
    }
    cout << "������Ҫȡ����ԤԼ, 0������: ";
    int select;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                cout << "ȡ������" << endl;
                break;
            }
            of.m_orderData[v[select - 1]]["status"] = "0";
            of.updateOrder();
            cout << "��ȡ��ԤԼ" << endl;
            break;
        }
        cout << "��������, ����������: ";
    }
    system("pause");
}




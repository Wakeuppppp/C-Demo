/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
 * @Time : 2022/4/7 20:46
 * @Project_Name : Reservation 
 * @File : teacher.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/7.
//

#include <iostream>
#include "teacher.h"
#include "orderFile.h"
#include <vector>

using namespace std;

Teacher::Teacher() {

}

Teacher::Teacher(int id, string name, string pwd) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_Pwd = pwd;
}

Teacher::~Teacher() {

}

void Teacher::showMenu() {
    cout << "��ְ�� " << this->m_Name << " ,���~" << endl;
    cout << "1. ��ʾ����ԤԼ" << endl;
    cout << "2. ԤԼ���" << endl;
    cout << "0. ע����¼" << endl;
    cout << "��ѡ��: ";
}

void Teacher::showAllOrder() {
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
}

void Teacher::auditOrder() {
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
        if (of.m_orderData[i]["status"] == "1") {
            flag = false;
            v.push_back(i);
            cout << ++index << ".";
            cout << " ԤԼ����: ��" << of.m_orderData[i]["date"];
            cout << " ʱ��: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
            cout << " ѧ��: " << of.m_orderData[i]["stuId"];
            cout << " ����: " << of.m_orderData[i]["stuName"];
            cout << " ����: " << of.m_orderData[i]["roomId"];
            cout << " ״̬: �����" << endl;
        }
    }

    if (flag) {
        cout << "����ԤԼ��Ϣ" << endl;
    }
    cout << "������ҪҪ��˵�ԤԼ��¼, 0����ȡ��: ";
    int select;
    int ret;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                cout << "ȡ������" << endl;
                break;
            }
            cout << endl;
            cout << "---------------�����---------------" << endl;
            cout << " ԤԼ����: ��" << of.m_orderData[v[select - 1]]["date"];
            cout << " ʱ��: " << (of.m_orderData[v[select - 1]]["interval"] == "1" ? "����" : "����");
            cout << " ѧ��: " << of.m_orderData[v[select - 1]]["stuId"];
            cout << " ����: " << of.m_orderData[v[select - 1]]["stuName"];
            cout << " ����: " << of.m_orderData[v[select - 1]]["roomId"];
            cout << " ״̬: �����" << endl;
            cout << "1. ͨ��" << endl;
            cout << "2. ��ͨ��" << endl;
            cout << "��������˽��, 0����ȡ��: " << endl;
            cin >> ret;
            if (ret == 1) {
                of.m_orderData[v[select - 1]]["status"] = "2";
                cout << "��ͬ���ԤԼ" << endl;
                break;
            } else if (ret == 2) {
                of.m_orderData[v[select - 1]]["status"] = "-1";
                cout << "�Ѿܾ���ԤԼ" << endl;
                break;
            } else {
                cout << "ȡ������" << endl;
                break;
            }
        }
        cout << "��������, ����������: ";
    }
    of.updateOrder();
}

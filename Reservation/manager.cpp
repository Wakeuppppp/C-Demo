/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
 * @Time : 2022/4/7 20:47
 * @Project_Name : Reservation 
 * @File : manager.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/7.
//

#include <iostream>
#include "manager.h"
#include <fstream>
#include "globalFile.h"

using namespace std;

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
    this->m_Name = name;
    this->m_Pwd = pwd;
    this->initVector();
    ifstream ifs(COMPUTER_FILE, ios::in);
    if (!ifs.is_open()) {
        cout << "��ȡ�����ļ�ʧ��" << endl;
        ifs.close();
        return;
    }
    ComputerRoom cr;
    while (ifs >> cr.m_ComId && ifs >> cr.m_MaxNum) {
        vCom.push_back(cr);
    }
//    cout << "��ǰ��������: " << vCom.size() << endl;
    ifs.close();
}

Manager::~Manager() {

}

void Manager::showMenu() {
    cout << "������Ա " << this->m_Name << " ,���~" << endl;
    cout << "1 ����û�" << endl;
    cout << "2 �鿴�˺�" << endl;
    cout << "3 �鿴����" << endl;
    cout << "4 ���ԤԼ" << endl;
    cout << "0 ע����¼" << endl;
    cout << "��ѡ��:";
}

void Manager::addAccount() {

    cout << "1�����ѧ��" << endl;
    cout << "2����ӽ�ְ��" << endl;
    cout << "����������˺ŵ�����: ";
    int select = 0;
    cin >> select;

    int id;
    string name;
    string pwd;

    if (select == 1) {
        cout << "������Ҫ��ӵ�ѧ����Ϣ:" << endl;
        cout << "�˺�:";
        cin >> id;
        // ��֤id�Ƿ��Ѿ�����
        for (auto it = this->vStu.begin(); it != this->vStu.end(); ++it) {
            if (it->m_Id == id) {
                cout << "ѧ���˺��Ѵ���, ���ʧ��" << endl;
                system("pause");
                return;
            }
        }
        cout << "����:";
        cin >> name;
        cout << "����:";
        cin >> pwd;

        ofstream ofs(STUDENT_FILE, ios::app);
        ofs << id << " " << name << " " << pwd << endl;
        Student stu(id, name, pwd);
        this->vStu.push_back(stu);
        cout << "ѧ����ӳɹ�" << endl;
        system("pause");


    } else if (select == 2) {
        cout << "������Ҫ��ӵĽ�ְ����Ϣ:" << endl;
        cout << "�˺�:";
        cin >> id;
        // ��֤id�Ƿ��Ѿ�����
        for (auto it = this->vTea.begin(); it != this->vTea.end(); ++it) {
            if (it->m_Id == id) {
                cout << "�ý�ְ���˺��Ѵ���, ���ʧ��" << endl;
                system("pause");
                return;
            }
        }
        cout << "����:";
        cin >> name;
        cout << "����:";
        cin >> pwd;

        ofstream ofs(TEACHER_FILE, ios::app);
        ofs << id << " " << name << " " << pwd << endl;
        Teacher tea(id, name, pwd);
        this->vTea.push_back(tea);
        cout << "��ְ����ӳɹ�" << endl;
        system("pause");

    } else {
        cout << "�������" << endl;
        system("pause");
    }
}

void Manager::showAccount() {
    cout << "1. �鿴����ѧ��" << endl;
    cout << "2. �鿴���н�ְ��" << endl;
    cout << "��ѡ��: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "ѧ���˺���Ϣ����: " << endl;
        for (auto it = this->vStu.begin(); it != this->vStu.end(); ++it) {
            cout << "ѧ��ѧ��: " << it->m_Id << "\t����: " << it->m_Name << "\t����: " << it->m_Pwd << endl;
        }
        cout << endl;
    } else if (choice == 2) {
        cout << "��ʦ�˺���Ϣ����: " << endl;
        for (auto it = this->vTea.begin(); it != this->vTea.end(); ++it) {
            cout << "��ְ����: " << it->m_Id << "\t����: " << it->m_Name << "\t����: " << it->m_Pwd << endl;
        }
        cout << endl;
    } else {
        cout << "�������" << endl;
        return;
    }
    system("pause");
}

void Manager::showInfo() {
    cout << "������Ϣ����:" << endl;
    for (auto it = vCom.begin(); it != vCom.end(); ++it) {
        cout << "�������: " << it->m_ComId << "\t�������: " << it->m_MaxNum << endl;
    }
    cout << endl;
    system("pause");
}

void Manager::cleanFile() {
    cout << "�Ƿ�Ҫ�������ԤԼ��Ϣ?(Y/N): ";
    string choice;
    cin >> choice;
    if (choice != "Y" && choice != "y") {
        cout << "ȡ������" << endl;
        return;
    }
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "������" << endl;
    system("pause");
}

void Manager::initVector() {
    ifstream ifsS(STUDENT_FILE, ios::in);
    if (!ifsS.is_open()) {
        cout << "��ʼ��ѧ���˺�ʧ��" << endl;
        ifsS.close();
        return;
    }
    vStu.clear();
    Student s;
    while (ifsS >> s.m_Id && ifsS >> s.m_Name && ifsS >> s.m_Pwd) {
        vStu.push_back(s);
    }
//    cout << "��ǰѧ���˺�����: " << vStu.size() << endl;
    ifsS.close();

    ifstream ifsT(TEACHER_FILE, ios::in);
    if (!ifsT.is_open()) {
        cout << "��ʼ����ʦ�˺�ʧ��" << endl;
        ifsT.close();
        return;
    }
    vTea.clear();
    Teacher t;
    while (ifsT >> t.m_Id && ifsT >> t.m_Name && ifsT >> t.m_Pwd) {
        vTea.push_back(t);
    }
//    cout << "��ǰ��ʦ�˺�����: " << vTea.size() << endl;
    ifsT.close();

}

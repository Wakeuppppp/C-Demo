/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
 * @Time : 2022/4/6 12:30
 * @Project_Name : Staff-Manager-System
 * @File : workerMgr.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#include <iostream>
#include "workerMgr.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

WorkerMgr::WorkerMgr() {
    this->m_EmpNum = 0;
    this->m_EmpArray = nullptr;
}

WorkerMgr::~WorkerMgr() {

}

void WorkerMgr::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "*************  0.�˳��������  *************" << endl;
    cout << "*************  1.����ְ����Ϣ  *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
    cout << "*************  3.ɾ����ְְ��  *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
    cout << "*************  5.����ְ����Ϣ  *************" << endl;
    cout << "*************  6.���ձ������  *************" << endl;
    cout << "*************  7.��������ĵ�  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerMgr::add_Emp() {
    cout << "������Ҫ��ӵ�ְ������: ";

    int addNum = 0;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->m_EmpNum + addNum;
        Worker **newSpace = new Worker *[newSize];
        if (this->m_EmpArray != nullptr) {
            for (int i = 0; i < this->m_EmpNum; ++i) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }


        for (int i = 0; i < addNum; i++) {
            int id = 0;
            cout << "�������" << i + 1 << "��ְ�����: ";
            cin >> id;
            string name;
            cout << "�������" << i + 1 << "��ְ������: ";
            cin >> name;
            int dId;
            cout << "��ѡ���" << i + 1 << "��ְ��ְλ: " << endl;
            cout << "1 ��ְͨ�� " << endl;
            cout << "2 ���� " << endl;
            cout << "3 �ϰ� " << endl;
            cin >> dId;
            Worker *worker;
            switch (dId) {
                case 1: {
                    worker = new Employee(id, name, dId);
                    break;
                }
                case 2: {
                    worker = new Manager(id, name, dId);
                    break;
                }
                case 3: {
                    worker = new Boss(id, name, dId);
                    break;
                }
                default:
                    cout << "ְ��ְλ����" << endl;
                    break;
            }
            newSpace[this->m_EmpNum + i] = worker;
            cout << "��" << i + 1 << "λְ����Ϣ������" << endl;

        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        cout << "�ɹ����" << addNum << "λְ��" << endl;
    } else {
        cout << "�������" << endl;
    }
    system("pause");
}

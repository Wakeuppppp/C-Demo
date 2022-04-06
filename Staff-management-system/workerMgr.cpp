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
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    // �ļ�������
    if (!ifs.is_open()) {
//        cout << "�ļ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;

    // �ļ����ڵ�������
    if (ifs.eof()) {
//        cout << "�ļ����ڵ�������" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    string str;
    int n = 0;
    while (getline(ifs, str, '\n')) {
        n++;
    }
    this->m_EmpNum = n;
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    this->m_FileIsEmpty = false;
    init_Emp();
}

WorkerMgr::~WorkerMgr() {
    if (this->m_EmpArray != nullptr) {
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
    }
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
        this->m_FileIsEmpty = false;
        this->save();
        cout << "�ɹ����" << addNum << "λְ��" << endl;
    } else {
        cout << "�������" << endl;
    }
}

void WorkerMgr::save() {
    ofstream out;
    out.open("test.txt", ios::out);
    for (int i = 0; i < this->m_EmpNum; ++i) {
        out << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    out.close();
}

void WorkerMgr::init_Emp() {
    ifstream ifs;
    ifs.open("test.txt", ios::in);

    int id = 0;
    string name = "";
    int dId = 0;
    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        Worker *worker;
        switch (dId) {
            case 1:
                worker = new Employee(id, name, dId);
                break;
            case 2:
                worker = new Manager(id, name, dId);
                break;
            case 3:
                worker = new Boss(id, name, dId);
                break;
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

}

void WorkerMgr::show_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ�����Ϊ��!" << endl;
    } else {
        cout << "----------�� " << this->m_EmpNum << "������----------" << endl;
        for (int i = 0; i < this->m_EmpNum; ++i) {
            cout << "Ա�����: " << this->m_EmpArray[i]->m_Id << "\t"
                 << "����: " << this->m_EmpArray[i]->m_Name << "\t"
                 << "ְλ: " << this->m_EmpArray[i]->getDeptName() << endl;
        }
    }
}

void WorkerMgr::del_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }
    cout << "������Ҫɾ����ְ��ID" << endl;
    int id;
    cin >> id;
    id = this->isExist(id);
    if (id == -1) {
        cout << "δ�ҵ���ְ��" << endl;
        return;
    } else {
        // ɾ��
        for (int i = id; i < this->m_EmpNum - 1; ++i) {
            this->m_EmpArray[i] = this->m_EmpArray[i + 1];
        }
        this->m_EmpNum--;

        this->save();
    }

}

int WorkerMgr::isExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void WorkerMgr::search() {
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ�����Ϊ��!" << endl;
        return;
    }
    cout << "������Ҫ���ҵ�Ա�����: ";
    int id;
    cin >> id;
    id = this->isExist(id);
    if (id == -1) {
        cout << "��Ա��������" << endl;
        return;
    }
    cout << "----------�ҵ���Ա��----------" << endl;
    cout << "Ա�����: " << this->m_EmpArray[id]->m_Id << "\t"
         << "����: " << this->m_EmpArray[id]->m_Name << "\t"
         << "ְλ: " << this->m_EmpArray[id]->getDeptName() << endl;
}

void WorkerMgr::modify() {
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }
    cout << "�������޸�ְ���ı�ţ�" << endl;
    int id;
    cin >> id;
    id = this->isExist(id);
    if (id == -1) {
        cout << "�޸�ʧ�ܣ����޴���" << endl;
        return;
    }
    delete this->m_EmpArray[id];

    int newId = 0;
    string newName = "";
    int dSelect = 0;

    cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
    cin >> newId;

    cout << "�������������� " << endl;
    cin >> newName;

    cout << "�������λ�� " << endl;
    cout << "1����ְͨ��" << endl;
    cout << "2������" << endl;
    cout << "3���ϰ�" << endl;
    cin >> dSelect;

    Worker *worker = NULL;
    switch (dSelect) {
        case 1:
            worker = new Employee(newId, newName, dSelect);
            break;
        case 2:
            worker = new Manager(newId, newName, dSelect);
            break;
        case 3:
            worker = new Boss(newId, newName, dSelect);
            break;
        default:
            break;
    }

    this->m_EmpArray[id] = worker;
    this->save();
    cout << "�޸ĳɹ�" << endl;
}

void WorkerMgr::sort_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }
    cout << "��ѡ������ʽ�� " << endl;
    cout << "1����ְ���Ž�������" << endl;
    cout << "2����ְ���Ž��н���" << endl;

    int select = 0;
    cin >> select;
    for (int i = this->m_EmpNum; i > 0; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if(select == 1){
                if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id) {
                    auto temp = this->m_EmpArray[j];
                    this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                    this->m_EmpArray[j + 1] = temp;
                }
            } else{
                if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id) {
                    auto temp = this->m_EmpArray[j];
                    this->m_EmpArray[j] = this->m_EmpArray[j + 1];
                    this->m_EmpArray[j + 1] = temp;
                }
            }
        }
    }
    cout << "�������" << endl;
    this->save();
    this->show_Emp();

}

void WorkerMgr::clean_File() {
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;
    if (select == 2) {
        cout << "ȡ������" << endl;
        return;
    }
    ofstream ofs("test.txt", ios::trunc);
    ofs.close();
    if (this->m_EmpArray != nullptr) {
        for (int i = 0; i < this->m_EmpNum; ++i) {
            if (this->m_EmpArray[i] != nullptr) {
                delete this->m_EmpArray[i];
            }
        }
        this->m_EmpNum = 0;
        delete[] this->m_EmpArray;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
    }
    cout << "��ճɹ�" << endl;
}


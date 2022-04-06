/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
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

    // 文件不存在
    if (!ifs.is_open()) {
//        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;

    // 文件存在但无数据
    if (ifs.eof()) {
//        cout << "文件存在但无数据" << endl;
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
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerMgr::add_Emp() {
    cout << "请输入要添加的职工数量: ";
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
            cout << "请输入第" << i + 1 << "个职工编号: ";
            cin >> id;
            string name;
            cout << "请输入第" << i + 1 << "个职工姓名: ";
            cin >> name;
            int dId;
            cout << "请选择第" << i + 1 << "个职工职位: " << endl;
            cout << "1 普通职工 " << endl;
            cout << "2 经理 " << endl;
            cout << "3 老板 " << endl;
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
                    cout << "职工职位错误" << endl;
                    break;
            }
            newSpace[this->m_EmpNum + i] = worker;
            cout << "第" << i + 1 << "位职工信息添加完成" << endl;

        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false;
        this->save();
        cout << "成功添加" << addNum << "位职工" << endl;
    } else {
        cout << "输入错误" << endl;
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
        cout << "文件不存在或数据为空!" << endl;
    } else {
        cout << "----------共 " << this->m_EmpNum << "条数据----------" << endl;
        for (int i = 0; i < this->m_EmpNum; ++i) {
            cout << "员工编号: " << this->m_EmpArray[i]->m_Id << "\t"
                 << "名字: " << this->m_EmpArray[i]->m_Name << "\t"
                 << "职位: " << this->m_EmpArray[i]->getDeptName() << endl;
        }
    }
}

void WorkerMgr::del_Emp() {

    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }
    cout << "请输入要删除的职工ID" << endl;
    int id;
    cin >> id;
    id = this->isExist(id);
    if (id == -1) {
        cout << "未找到该职工" << endl;
        return;
    } else {
        // 删除
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
        cout << "文件不存在或数据为空!" << endl;
        return;
    }
    cout << "请输入要查找的员工编号: ";
    int id;
    cin >> id;
    id = this->isExist(id);
    if (id == -1) {
        cout << "该员工不存在" << endl;
        return;
    }
    cout << "----------找到该员工----------" << endl;
    cout << "员工编号: " << this->m_EmpArray[id]->m_Id << "\t"
         << "名字: " << this->m_EmpArray[id]->m_Name << "\t"
         << "职位: " << this->m_EmpArray[id]->getDeptName() << endl;
}

void WorkerMgr::modify() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }
    cout << "请输入修改职工的编号：" << endl;
    int id;
    cin >> id;
    id = this->isExist(id);
    if (id == -1) {
        cout << "修改失败，查无此人" << endl;
        return;
    }
    delete this->m_EmpArray[id];

    int newId = 0;
    string newName = "";
    int dSelect = 0;

    cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
    cin >> newId;

    cout << "请输入新姓名： " << endl;
    cin >> newName;

    cout << "请输入岗位： " << endl;
    cout << "1、普通职工" << endl;
    cout << "2、经理" << endl;
    cout << "3、老板" << endl;
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
    cout << "修改成功" << endl;
}

void WorkerMgr::sort_Emp() {
    if (this->m_FileIsEmpty) {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }
    cout << "请选择排序方式： " << endl;
    cout << "1、按职工号进行升序" << endl;
    cout << "2、按职工号进行降序" << endl;

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
    cout << "排序完成" << endl;
    this->save();
    this->show_Emp();

}

void WorkerMgr::clean_File() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;
    if (select == 2) {
        cout << "取消操作" << endl;
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
    cout << "清空成功" << endl;
}


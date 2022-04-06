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
    this->m_EmpNum = 0;
    this->m_EmpArray = nullptr;
}

WorkerMgr::~WorkerMgr() {

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
        cout << "成功添加" << addNum << "位职工" << endl;
    } else {
        cout << "输入错误" << endl;
    }
    system("pause");
}

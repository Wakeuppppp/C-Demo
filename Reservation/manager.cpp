/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
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
        cout << "读取机房文件失败" << endl;
        ifs.close();
        return;
    }
    ComputerRoom cr;
    while (ifs >> cr.m_ComId && ifs >> cr.m_MaxNum) {
        vCom.push_back(cr);
    }
//    cout << "当前机房数量: " << vCom.size() << endl;
    ifs.close();
}

Manager::~Manager() {

}

void Manager::showMenu() {
    cout << "管理人员 " << this->m_Name << " ,你好~" << endl;
    cout << "1 添加用户" << endl;
    cout << "2 查看账号" << endl;
    cout << "3 查看机房" << endl;
    cout << "4 清空预约" << endl;
    cout << "0 注销登录" << endl;
    cout << "请选择:";
}

void Manager::addAccount() {

    cout << "1、添加学生" << endl;
    cout << "2、添加教职工" << endl;
    cout << "请输入添加账号的类型: ";
    int select = 0;
    cin >> select;

    int id;
    string name;
    string pwd;

    if (select == 1) {
        cout << "请输入要添加的学生信息:" << endl;
        cout << "账号:";
        cin >> id;
        // 验证id是否已经存在
        for (auto it = this->vStu.begin(); it != this->vStu.end(); ++it) {
            if (it->m_Id == id) {
                cout << "学生账号已存在, 添加失败" << endl;
                system("pause");
                return;
            }
        }
        cout << "姓名:";
        cin >> name;
        cout << "密码:";
        cin >> pwd;

        ofstream ofs(STUDENT_FILE, ios::app);
        ofs << id << " " << name << " " << pwd << endl;
        Student stu(id, name, pwd);
        this->vStu.push_back(stu);
        cout << "学生添加成功" << endl;
        system("pause");


    } else if (select == 2) {
        cout << "请输入要添加的教职工信息:" << endl;
        cout << "账号:";
        cin >> id;
        // 验证id是否已经存在
        for (auto it = this->vTea.begin(); it != this->vTea.end(); ++it) {
            if (it->m_Id == id) {
                cout << "该教职工账号已存在, 添加失败" << endl;
                system("pause");
                return;
            }
        }
        cout << "姓名:";
        cin >> name;
        cout << "密码:";
        cin >> pwd;

        ofstream ofs(TEACHER_FILE, ios::app);
        ofs << id << " " << name << " " << pwd << endl;
        Teacher tea(id, name, pwd);
        this->vTea.push_back(tea);
        cout << "教职工添加成功" << endl;
        system("pause");

    } else {
        cout << "输入错误" << endl;
        system("pause");
    }
}

void Manager::showAccount() {
    cout << "1. 查看所有学生" << endl;
    cout << "2. 查看所有教职工" << endl;
    cout << "请选择: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        cout << "学生账号信息如下: " << endl;
        for (auto it = this->vStu.begin(); it != this->vStu.end(); ++it) {
            cout << "学生学号: " << it->m_Id << "\t姓名: " << it->m_Name << "\t密码: " << it->m_Pwd << endl;
        }
        cout << endl;
    } else if (choice == 2) {
        cout << "教师账号信息如下: " << endl;
        for (auto it = this->vTea.begin(); it != this->vTea.end(); ++it) {
            cout << "教职工号: " << it->m_Id << "\t姓名: " << it->m_Name << "\t密码: " << it->m_Pwd << endl;
        }
        cout << endl;
    } else {
        cout << "输入错误" << endl;
        return;
    }
    system("pause");
}

void Manager::showInfo() {
    cout << "机房信息如下:" << endl;
    for (auto it = vCom.begin(); it != vCom.end(); ++it) {
        cout << "机房编号: " << it->m_ComId << "\t最大容量: " << it->m_MaxNum << endl;
    }
    cout << endl;
    system("pause");
}

void Manager::cleanFile() {
    cout << "是否要清空所有预约信息?(Y/N): ";
    string choice;
    cin >> choice;
    if (choice != "Y" && choice != "y") {
        cout << "取消操作" << endl;
        return;
    }
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "清空完成" << endl;
    system("pause");
}

void Manager::initVector() {
    ifstream ifsS(STUDENT_FILE, ios::in);
    if (!ifsS.is_open()) {
        cout << "初始化学生账号失败" << endl;
        ifsS.close();
        return;
    }
    vStu.clear();
    Student s;
    while (ifsS >> s.m_Id && ifsS >> s.m_Name && ifsS >> s.m_Pwd) {
        vStu.push_back(s);
    }
//    cout << "当前学生账号数量: " << vStu.size() << endl;
    ifsS.close();

    ifstream ifsT(TEACHER_FILE, ios::in);
    if (!ifsT.is_open()) {
        cout << "初始化教师账号失败" << endl;
        ifsT.close();
        return;
    }
    vTea.clear();
    Teacher t;
    while (ifsT >> t.m_Id && ifsT >> t.m_Name && ifsT >> t.m_Pwd) {
        vTea.push_back(t);
    }
//    cout << "当前教师账号数量: " << vTea.size() << endl;
    ifsT.close();

}

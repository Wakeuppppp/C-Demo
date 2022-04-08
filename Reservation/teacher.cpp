/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
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
    cout << "教职工 " << this->m_Name << " ,你好~" << endl;
    cout << "1. 显示所有预约" << endl;
    cout << "2. 预约审核" << endl;
    cout << "0. 注销登录" << endl;
    cout << "请选择: ";
}

void Teacher::showAllOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "无预约记录" << endl;
        system("pause");
        return;
    }
    for (int i = 0; i < of.m_Size; ++i) {
        cout << "预约记录Id: " << i;
        cout << " 预约日期: 周" << of.m_orderData[i]["date"];
        cout << " 时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
        cout << " 学号: " << of.m_orderData[i]["stuId"];
        cout << " 姓名: " << of.m_orderData[i]["stuName"];
        cout << " 机房: " << of.m_orderData[i]["roomId"];
        string status = " 状态: ";
        // 0 预约取消   1 审核中   2 预约成功   -1 预约失败
        if (of.m_orderData[i]["status"] == "1") {
            status += "审核中";
        } else if (of.m_orderData[i]["status"] == "2") {
            status += "预约成功";
        } else if (of.m_orderData[i]["status"] == "-1") {
            status += "审核未通过, 预约失败";
        } else {
            status += "预约已取消";
        }
        cout << status << endl;
    }
}

void Teacher::auditOrder() {
    OrderFile of;
    if (of.m_Size == 0) {
        cout << "无预约记录" << endl;
        system("pause");
        return;
    }
    bool flag = true;
    vector<int> v; // 存储预约记录Id
    int index = 0;
    for (int i = 0; i < of.m_Size; ++i) {
        if (of.m_orderData[i]["status"] == "1") {
            flag = false;
            v.push_back(i);
            cout << ++index << ".";
            cout << " 预约日期: 周" << of.m_orderData[i]["date"];
            cout << " 时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 学号: " << of.m_orderData[i]["stuId"];
            cout << " 姓名: " << of.m_orderData[i]["stuName"];
            cout << " 机房: " << of.m_orderData[i]["roomId"];
            cout << " 状态: 审核中" << endl;
        }
    }

    if (flag) {
        cout << "暂无预约信息" << endl;
    }
    cout << "请输入要要审核的预约记录, 0代表取消: ";
    int select;
    int ret;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                cout << "取消操作" << endl;
                break;
            }
            cout << endl;
            cout << "---------------审核中---------------" << endl;
            cout << " 预约日期: 周" << of.m_orderData[v[select - 1]]["date"];
            cout << " 时段: " << (of.m_orderData[v[select - 1]]["interval"] == "1" ? "上午" : "下午");
            cout << " 学号: " << of.m_orderData[v[select - 1]]["stuId"];
            cout << " 姓名: " << of.m_orderData[v[select - 1]]["stuName"];
            cout << " 机房: " << of.m_orderData[v[select - 1]]["roomId"];
            cout << " 状态: 审核中" << endl;
            cout << "1. 通过" << endl;
            cout << "2. 不通过" << endl;
            cout << "请输入审核结果, 0代表取消: " << endl;
            cin >> ret;
            if (ret == 1) {
                of.m_orderData[v[select - 1]]["status"] = "2";
                cout << "已同意该预约" << endl;
                break;
            } else if (ret == 2) {
                of.m_orderData[v[select - 1]]["status"] = "-1";
                cout << "已拒绝该预约" << endl;
                break;
            } else {
                cout << "取消操作" << endl;
                break;
            }
        }
        cout << "输入有误, 请重新输入: ";
    }
    of.updateOrder();
}

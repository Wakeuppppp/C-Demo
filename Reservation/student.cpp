/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
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
        cout << "初始化订单列表失败" << endl;
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
    cout << "学生 " << this->m_Name << " ,你好~" << endl;
    cout << "1. 申请预约" << endl;
    cout << "2. 查看我的预约" << endl;
    cout << "3. 查看所有预约" << endl;
    cout << "4. 取消预约" << endl;
    cout << "0. 注销登录" << endl;
    cout << "请选择: ";
}

void Student::applyOrder() {
    cout << "机房开放时间为周一至周五" << endl;
    cout << "1. 周一" << endl;
    cout << "2. 周二" << endl;
    cout << "3. 周三" << endl;
    cout << "4. 周四" << endl;
    cout << "5. 周五" << endl;
    cout << "请选择: ";

    int date;
    int interval;
    int room;

    while (true) {
        cin >> date;
        if (date > 0 && date < 6) {
            break;
        }
        cout << "输入错误, 请重新输入: ";
    }
    cout << "1. 上午" << endl;
    cout << "2. 下午" << endl;
    cout << "请选择预约时间段:";
    while (true) {
        cin >> interval;
        if (interval > 0 && interval < 3) {
            break;
        }
        cout << "输入错误, 请重新输入: ";
    }
    cout << "1号机房容量" << vCom[0].m_MaxNum << endl;
    cout << "2号机房容量" << vCom[1].m_MaxNum << endl;
    cout << "3号机房容量" << vCom[2].m_MaxNum << endl;
    cout << "请选择机房: ";
    while (true) {
        cin >> room;
        if (room > 0 && room < 4) {
            break;
        }
        cout << "输入错误, 请重新输入: ";
    }
    cout << "预约申请已提交, 请等待审核" << endl;

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
        cout << "无预约记录" << endl;
        system("pause");
        return;
    }
    bool flag = true;
    for (int i = 0; i < of.m_Size; ++i) {
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
            flag = false;
            cout << "预约记录Id: " << i;
            cout << " 预约日期: 周" << of.m_orderData[i]["date"];
            cout << " 时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
            cout << " 机房: " << of.m_orderData[i]["roomId"];
            string status = " 状态: ";
            // 0 预约取消   1 审核中   2 已预约   -1 预约失败
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
    if (flag) {
        cout << "暂无预约信息" << endl;
    }

}

void Student::showAllOrder() {
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
    system("pause");
}

void Student::cancelOrder() {
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
        if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
            if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
                flag = false;
                v.push_back(i);
                cout << ++index << ".";
                cout << " 预约日期: 周" << of.m_orderData[i]["date"];
                cout << " 时段: " << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
                cout << " 机房: " << of.m_orderData[i]["roomId"];
                string status = " 状态: ";
                // 0 预约取消   1 审核中   2 已预约   -1 预约失败
                if (of.m_orderData[i]["status"] == "1") {
                    status += "审核中";
                } else {
                    status += "预约成功";
                }
                cout << status << endl;
            }

        }
    }
    if (flag) {
        cout << "暂无预约信息" << endl;
    }
    cout << "请输入要取消的预约, 0代表返回: ";
    int select;
    while (true) {
        cin >> select;
        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                cout << "取消操作" << endl;
                break;
            }
            of.m_orderData[v[select - 1]]["status"] = "0";
            of.updateOrder();
            cout << "已取消预约" << endl;
            break;
        }
        cout << "输入有误, 请重新输入: ";
    }
    system("pause");
}




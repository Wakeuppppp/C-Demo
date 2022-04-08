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

#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "identity.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Manager : public Identity {
public:
    Manager();

    Manager(string name, string pwd);

    ~Manager();

    virtual void showMenu(); // 管理员菜单

    void addAccount(); // 添加用户

    void showAccount(); // 查看用户

    void showInfo(); // 查看机房信息

    void cleanFile(); // 清除记录

    void initVector();

    vector<Student> vStu; // 保存从本地读取到的所有学生账号信息
    vector<Teacher> vTea; // 保存从本地读取到的所有教职工信息
    vector<ComputerRoom> vCom; // 保存从本地读取到的机房信息
};


#endif //RESERVATION_MANAGER_H


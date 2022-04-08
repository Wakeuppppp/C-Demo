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

#ifndef RESERVATION_STUDENT_H
#define RESERVATION_STUDENT_H

#include "identity.h"
#include <vector>
#include "computerRoom.h"

class Student : public Identity {
public:
    Student();

    Student(int id, string name, string pwd);

    ~Student();

    virtual void showMenu(); // 学生菜单

    void applyOrder(); // 预约申请

    void showMyOrder(); // 查看我的预约

    void showAllOrder(); // 查看所有预约

    void cancelOrder(); // 取消预约

    int m_Id; // 学生学号
    vector<ComputerRoom> vCom;

};


#endif //RESERVATION_STUDENT_H


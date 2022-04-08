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

#ifndef RESERVATION_TEACHER_H
#define RESERVATION_TEACHER_H
#include "identity.h"

class Teacher :public Identity{
public:
    Teacher();
    Teacher(int id, string name, string pwd);
    ~Teacher();


    virtual void showMenu(); // 教师菜单

    void showAllOrder(); // 显示所有预约

    void auditOrder(); // 预约审核

    int m_Id; // 教师编号

};


#endif //RESERVATION_TEACHER_H


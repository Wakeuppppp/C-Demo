/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
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


    virtual void showMenu(); // ��ʦ�˵�

    void showAllOrder(); // ��ʾ����ԤԼ

    void auditOrder(); // ԤԼ���

    int m_Id; // ��ʦ���

};


#endif //RESERVATION_TEACHER_H


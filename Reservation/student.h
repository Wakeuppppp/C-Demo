/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
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

    virtual void showMenu(); // ѧ���˵�

    void applyOrder(); // ԤԼ����

    void showMyOrder(); // �鿴�ҵ�ԤԼ

    void showAllOrder(); // �鿴����ԤԼ

    void cancelOrder(); // ȡ��ԤԼ

    int m_Id; // ѧ��ѧ��
    vector<ComputerRoom> vCom;

};


#endif //RESERVATION_STUDENT_H


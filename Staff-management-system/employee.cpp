/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
 * @Time : 2022/4/6 12:42
 * @Project_Name : Staff-Manager-System
 * @File : employee.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#include <iostream>
#include "employee.h"

using namespace std;

Employee::Employee(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo() {
    cout << "Ա�����: " << this->m_Id << "\t����: " << this->m_Name << "\t����: " << this->getDeptName() << endl;
}

string Employee::getDeptName() {
    return "��ͨԱ��";
}
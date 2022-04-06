/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
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
    cout << "员工编号: " << this->m_Id << "\t名字: " << this->m_Name << "\t部门: " << this->getDeptName() << endl;
}

string Employee::getDeptName() {
    return "普通员工";
}
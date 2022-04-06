/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
 * @Time : 2022/4/6 12:49
 * @Project_Name : Staff-Manager-System
 * @File : manager.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//


#include <iostream>
#include "manager.h"

using namespace std;

Manager::Manager(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showInfo() {
    cout << "Id:" << this->m_Id << "\tName:" << this->m_Name << "\t部门:" << this->getDeptName() << endl;
}

string Manager::getDeptName() {
    return "经理";
}
using namespace std;


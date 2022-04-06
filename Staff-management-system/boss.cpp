/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
 * @Time : 2022/4/6 12:49
 * @Project_Name : Staff-Manager-System
 * @File : boss.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#include <iostream>
#include "boss.h"

using namespace std;

Boss::Boss(int id, string name, int dId) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo() {
    cout << "Id:" << this->m_Id << "\tName:" << this->m_Name << "\t部门:" << this->getDeptName() << endl;
}

string Boss::getDeptName() {
    return "老板";
}



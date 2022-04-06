/*
 * -*- coding = utf-8 -*-
 * Author: _¹È°² 
 * @Time : 2022/4/6 12:42
 * @Project_Name : Staff-Manager-System
 * @File : employee.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#ifndef TESTPROJECT_EMPLOYEE_H
#define TESTPROJECT_EMPLOYEE_H

#include <iostream>
#include "worker.h"


class Employee : public Worker {
public:
    Employee(int id, string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //TESTPROJECT_EMPLOYEE_H


/*
 * -*- coding = utf-8 -*-
 * Author: _¹È°² 
 * @Time : 2022/4/6 12:49
 * @Project_Name : Staff-Manager-System
 * @File : manager.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#ifndef TESTPROJECT_MANAGER_H
#define TESTPROJECT_MANAGER_H


#include <iostream>
#include "worker.h"

using namespace std;

class Manager : public Worker {
public:
    Manager(int id, string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //TESTPROJECT_MANAGER_H


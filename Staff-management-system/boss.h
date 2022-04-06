/*
 * -*- coding = utf-8 -*-
 * Author: _¹È°² 
 * @Time : 2022/4/6 12:49
 * @Project_Name : Staff-Manager-System
 * @File : boss.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#ifndef TESTPROJECT_BOSS_H
#define TESTPROJECT_BOSS_H

#include <iostream>
#include "worker.h"

using namespace std;

class Boss : public Worker {
public:
    Boss(int id, string name, int dId);

    virtual void showInfo();

    virtual string getDeptName();
};


#endif //TESTPROJECT_BOSS_H


/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
 * @Time : 2022/4/6 12:30
 * @Project_Name : Staff-Manager-System
 * @File : workerMgr.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#ifndef TESTPROJECT_WORKERMGR_H
#define TESTPROJECT_WORKERMGR_H

#include "worker.h"

class WorkerMgr {
public:
    WorkerMgr();

    ~WorkerMgr();

    void showMenu();

    void add_Emp();

    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker **m_EmpArray;


};


#endif //TESTPROJECT_WORKERMGR_H

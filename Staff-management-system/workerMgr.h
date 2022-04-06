/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
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

    // ��¼ְ������
    int m_EmpNum;

    // ְ������ָ��
    Worker **m_EmpArray;


};


#endif //TESTPROJECT_WORKERMGR_H

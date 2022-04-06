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

#include "workerMgr.h"
#include <iostream>

using namespace std;

WorkerMgr::WorkerMgr() {

}

WorkerMgr::~WorkerMgr() {

}

void WorkerMgr::showMenu() {
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}
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
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerMgr {
public:
    WorkerMgr();

    ~WorkerMgr();

    void showMenu();

    void add_Emp(); // 增加数据

    void save(); // 保存数据到文件

    void init_Emp(); // 初始化职工数组

    void show_Emp(); // 显示数据

    void del_Emp(); // 删除指定职工

    int isExist(int id); // 判断职工是否存在

    void modify(); // 修改

    void search(); // 查找并显示

    void sort_Emp(); // 排序

    void clean_File(); // 清空文件

    // 标志文件是否为空
    bool m_FileIsEmpty;

    // 记录职工人数
    int m_EmpNum;

    // 职工数组指针
    Worker **m_EmpArray;


};


#endif //TESTPROJECT_WORKERMGR_H

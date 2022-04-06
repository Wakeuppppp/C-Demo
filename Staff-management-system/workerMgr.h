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
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerMgr {
public:
    WorkerMgr();

    ~WorkerMgr();

    void showMenu();

    void add_Emp(); // ��������

    void save(); // �������ݵ��ļ�

    void init_Emp(); // ��ʼ��ְ������

    void show_Emp(); // ��ʾ����

    void del_Emp(); // ɾ��ָ��ְ��

    int isExist(int id); // �ж�ְ���Ƿ����

    void modify(); // �޸�

    void search(); // ���Ҳ���ʾ

    void sort_Emp(); // ����

    void clean_File(); // ����ļ�

    // ��־�ļ��Ƿ�Ϊ��
    bool m_FileIsEmpty;

    // ��¼ְ������
    int m_EmpNum;

    // ְ������ָ��
    Worker **m_EmpArray;


};


#endif //TESTPROJECT_WORKERMGR_H

//
// Created by awake on 2022/4/6.
//

#ifndef TESTPROJECT_WORKER_H
#define TESTPROJECT_WORKER_H
#include <iostream>
using namespace std;

class Worker{
public:
    virtual void showInfo() = 0;
    virtual string getDeptName() = 0;

    int m_Id;
    string m_Name;
    int m_DeptId;
};


#endif //TESTPROJECT_WORKER_H

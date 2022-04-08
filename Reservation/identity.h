/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
 * @Time : 2022/4/7 20:44
 * @Project_Name : Reservation 
 * @File : identity.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/7.
//

#pragma once

#include <iostream>

using namespace std;

class Identity {
public:
    virtual void showMenu() = 0;

    string m_Name;
    string m_Pwd;
};



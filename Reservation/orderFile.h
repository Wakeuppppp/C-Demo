/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
 * @Time : 2022/4/8 15:28
 * @Project_Name : Reservation 
 * @File : orderFile.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/8.
//

#ifndef RESERVATION_ORDERFILE_H
#define RESERVATION_ORDERFILE_H

#include <map>

using namespace std;

class OrderFile {
public:
    OrderFile();

    void updateOrder(); // 更新预约记录

    // key 第几条记录    value 具体预约记录(键值对方式存储)
    map<int, map<string, string>> m_orderData;

    int m_Size; // 预约记录条数
};


#endif //RESERVATION_ORDERFILE_H


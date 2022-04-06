/*
 * -*- coding = utf-8 -*-
 * Author: _谷安 
 * @Time : 2022/4/6 23:02
 * @Project_Name : SpeechContestSystem 
 * @File : speechMgr.cpp
 * @Software :CLion
 */

//
// Created by awake on 2022/4/6.
//

#include <iostream>
#include "speechMgr.h"
#include <windows.h>
#include <algorithm>

using namespace std;

SpeechMgr::SpeechMgr() {
    this->init();
    this->createSpeaker();
}

SpeechMgr::~SpeechMgr() {

}

void SpeechMgr::showMenu() {
    cout << "********************************************" << endl;
    cout << "*************  欢迎参加演讲比赛 ************" << endl;
    cout << "*************  1.开始演讲比赛  *************" << endl;
    cout << "*************  2.查看往届记录  *************" << endl;
    cout << "*************  3.清空比赛记录  *************" << endl;
    cout << "*************  0.退出比赛程序  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void SpeechMgr::init() {
    this->v1.clear();
    this->v2.clear();
    this->Victory.clear();
    this->m_Speaker.clear();
    this->index = 1;
}

void SpeechMgr::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); ++i) {
        string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.m_Name = name;
        sp.m_Score[0] = 0;
        sp.m_Score[1] = 0;


        this->v1.push_back(i + 10001);
        this->m_Speaker.insert(make_pair(i + 10001, sp));
    }
}

void SpeechMgr::startSpeech() {
    // 第一轮 抽签
    speechDraw();
    // 比赛
    speechContest();
    // 显示晋级结果

    // 第二轮 抽签

    // 比赛

    // 显示最终结果

    // 保存分数
}

void SpeechMgr::speechDraw() {
    cout << "第" << this->index << "轮比赛正在抽签" << endl;
    for (int i = 3; i >= 0; --i) {
        cout << "倒计时: " << i << endl;
        Sleep(1000);
    }
    cout << "----------抽签结果如下----------" << endl;
    if (this->index == 1) {
        random_shuffle(v1.begin(), v1.end());
        for (auto it = v1.begin(); it != v1.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    } else {
        random_shuffle(v2.begin(), v2.end());
        for (auto it = v2.begin(); it != v2.end(); ++it) {
            cout << *it << " ";
        }
    }
}

void SpeechMgr::speechContest() {
    cout << "----------第 " << this->index << " 轮比赛正式开始----------" << endl;

}

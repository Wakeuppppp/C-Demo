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

#ifndef SPEECHCONTESTSYSTEM_SPEECHMGR_H
#define SPEECHCONTESTSYSTEM_SPEECHMGR_H

#include <vector>
#include <map>
#include "speaker.h"
using namespace std;
class SpeechMgr {
public:
    SpeechMgr();
    ~SpeechMgr();

    void showMenu();

    void init(); // 初始化

    void createSpeaker(); // 创建参赛者

    void startSpeech(); // 开始比赛

    void speechDraw(); // 抽签

    void speechContest(); // 比赛

    void showScore(); // 显示分数

    void saveRecord(); // 保存记录到本地

    void loadRecord(); // 读取本地记录

    void showRecord(); // 显示记录

    void clean_File(); // 清空记录

    bool fileEmpty;
    int m_Index; // 比赛轮次
    vector<int> v1; // 第一轮12人
    vector<int> v2; // 第二轮6人
    vector<int> Victory; // 前三名
    map<int, Speaker> m_Speaker; // 存放编号、选手
    map<int, vector<string>> m_Record; // 往届记录
};


#endif //SPEECHCONTESTSYSTEM_SPEECHMGR_H


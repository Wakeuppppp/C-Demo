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
#include <deque>
#include<numeric>
#include <fstream>

using namespace std;

SpeechMgr::SpeechMgr() {
    this->init();

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
    this->m_Index = 1;
    this->m_Record.clear();
    this->createSpeaker();
    this->loadRecord();
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
    showScore();
    this->m_Index++;
    // 第二轮 抽签
    speechDraw();
    // 比赛
    speechContest();
    // 显示最终结果
    showScore();
//    this->m_Index = 1;
    // 保存分数
    saveRecord();
    this->fileEmpty = false;
}

void SpeechMgr::speechDraw() {
    cout << "第 " << this->m_Index << " 轮比赛正在抽签..." << endl;
    Sleep(1000);

    cout << endl;
    cout << "---------- 演讲顺序如下 ----------" << endl;
    cout << endl;
    if (this->m_Index == 1) {
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
        cout << endl;
    }
    system("pause");
}

void SpeechMgr::speechContest() {
    cout << endl;
    cout << "----------第 " << this->m_Index << " 轮比赛正式开始----------" << endl;

    vector<int> vSrc; // 存放比赛选手
    if (this->m_Index == 1) {
        vSrc = this->v1;
    } else {
        vSrc = this->v2;
    }
    cout << endl;

    int num = 0; // 记录人员数 六人一组
    multimap<double, int, greater<int>> groupScore; // 临时降序存放分数 选手编号

    srand((unsigned) time(0));
    // 遍历所有参赛选手
    for (auto it = vSrc.begin(); it != vSrc.end(); ++it) {
        num++;
        deque<double> d; // 记录评委的分数
        for (int i = 0; i < 10; ++i) {
            double score = (rand() % 401 + 600) / 10.f;
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<double>()); // 降序排列
        d.pop_back(); // 去掉最低分
        d.pop_front(); // 去掉最高分

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double) d.size();

        this->m_Speaker[*it].m_Score[m_Index - 1] = avg;

        groupScore.insert(make_pair(avg, *it)); // 将成绩+编号存进去 降序
        if (num % 6 == 0) {
            cout << "第" << num / 6 << "小组比赛名次:" << endl;
            for (auto it = groupScore.begin(); it != groupScore.end(); ++it) {
                cout << "\t编号: " << it->second << "\t姓名: " << this->m_Speaker[it->second].m_Name << "\t分数: "
                     << it->first << endl;
            }
            int count = 0;
            // 取前三
            for (auto it = groupScore.begin(); it != groupScore.end(); ++it) {
                if (this->m_Index == 1) {
                    v2.push_back((*it).second); // 存放选手编号
                } else {
                    Victory.push_back((*it).second);
                }
                count++;
                if (count == 3) {
                    break;
                }
            }
            groupScore.clear();
            cout << endl;
        }
    }
    cout << "----------第 " << this->m_Index << " 轮比赛结束----------" << endl;
    system("pause");
}

void SpeechMgr::showScore() {
    cout << endl;
    vector<int> v;
    if (this->m_Index == 1) {
        cout << "---------- 第 " << this->m_Index << " 轮晋级选手信息如下----------" << endl;
        v = v2;
    } else {
        cout << "--------- 恭喜以下选手获胜 ----------" << endl;
        v = Victory;
    }
    cout << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << "选手编号: " << *it << "\t姓名: " << this->m_Speaker[*it].m_Name
             << "\t得分: " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
    system("pause");
}

void SpeechMgr::saveRecord() {
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);
    for (auto it = Victory.begin(); it != Victory.end(); ++it) {
        ofs << *it << "," << this->m_Speaker[*it].m_Name << ","
            << this->m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "记录已保存" << endl;
}

void SpeechMgr::loadRecord() {
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open()) { // 文件不存在
        cout << "file not exist" << endl;
        this->fileEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) { // 文件为空
        cout << "file is empty" << endl;
        this->fileEmpty = true;
        ifs.close();
        return;
    }
    this->fileEmpty = false;
    ifs.putback(ch);

    string data;
    int index = 0;
    while (ifs >> data) {
        vector<string> v;
        int pos = -1;
        int start = 0;
        while (true) {
            pos = data.find(",", start);
            if (pos == -1) {
                break;
            }
            string temp = data.substr(start, pos - start);
            start = pos + 1;
            v.push_back(temp);
        }
        this->m_Record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}

void SpeechMgr::showRecord() {
    if (this->fileEmpty) {
        cout << "文件不存在或记录为空" << endl;
        return;
    }
    for (int i = 0; i < this->m_Record.size(); ++i) {
        cout << "第" << i + 1 << "届演讲比赛获胜者\n" <<
             "冠军: " << "参赛编号: " << this->m_Record[i][0] <<
             "\t选手姓名: " << this->m_Record[i][1] <<
             "\t得分: " << this->m_Record[i][2] <<
             "\n亚军: " << "参赛编号: " << this->m_Record[i][3] <<
             "\t选手姓名: " << this->m_Record[i][4] <<
             "\t得分: " << this->m_Record[i][5] <<
             "\n季军: " << "参赛编号: " << this->m_Record[i][6] <<
             "\t选手姓名: " << this->m_Record[i][7] <<
             "\t得分: " << this->m_Record[i][8] << endl;
        cout << endl;
    }
}

void SpeechMgr::clean_File() {
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;
    if (select == 2) {
        cout << "取消操作" << endl;
        return;
    }
    ofstream ofs("speech.csv", ios::trunc);
    ofs.close();

    this->init();
    cout << "清空完成" << endl;
}

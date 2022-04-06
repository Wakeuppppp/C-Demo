/*
 * -*- coding = utf-8 -*-
 * Author: _�Ȱ� 
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

    void init(); // ��ʼ��

    void createSpeaker(); // ����������

    void startSpeech(); // ��ʼ����

    void speechDraw(); // ��ǩ

    void speechContest(); // ����

    int index; // �����ִ�
    vector<int> v1; // ��һ��12��
    vector<int> v2; // �ڶ���6��
    vector<int> Victory; // ǰ����
    map<int, Speaker> m_Speaker; // ��ű�š�ѡ��
};


#endif //SPEECHCONTESTSYSTEM_SPEECHMGR_H


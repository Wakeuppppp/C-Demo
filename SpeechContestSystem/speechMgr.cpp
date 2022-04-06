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
    cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
    cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
    cout << "*************  2.�鿴�����¼  *************" << endl;
    cout << "*************  3.��ձ�����¼  *************" << endl;
    cout << "*************  0.�˳���������  *************" << endl;
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
        string name = "ѡ��";
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
    // ��һ�� ��ǩ
    speechDraw();
    // ����
    speechContest();
    // ��ʾ�������

    // �ڶ��� ��ǩ

    // ����

    // ��ʾ���ս��

    // �������
}

void SpeechMgr::speechDraw() {
    cout << "��" << this->index << "�ֱ������ڳ�ǩ" << endl;
    for (int i = 3; i >= 0; --i) {
        cout << "����ʱ: " << i << endl;
        Sleep(1000);
    }
    cout << "----------��ǩ�������----------" << endl;
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
    cout << "----------�� " << this->index << " �ֱ�����ʽ��ʼ----------" << endl;

}

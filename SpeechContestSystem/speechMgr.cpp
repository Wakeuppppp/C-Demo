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
    this->m_Index = 1;
    this->m_Record.clear();
    this->createSpeaker();
    this->loadRecord();
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
    showScore();
    this->m_Index++;
    // �ڶ��� ��ǩ
    speechDraw();
    // ����
    speechContest();
    // ��ʾ���ս��
    showScore();
//    this->m_Index = 1;
    // �������
    saveRecord();
    this->fileEmpty = false;
}

void SpeechMgr::speechDraw() {
    cout << "�� " << this->m_Index << " �ֱ������ڳ�ǩ..." << endl;
    Sleep(1000);

    cout << endl;
    cout << "---------- �ݽ�˳������ ----------" << endl;
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
    cout << "----------�� " << this->m_Index << " �ֱ�����ʽ��ʼ----------" << endl;

    vector<int> vSrc; // ��ű���ѡ��
    if (this->m_Index == 1) {
        vSrc = this->v1;
    } else {
        vSrc = this->v2;
    }
    cout << endl;

    int num = 0; // ��¼��Ա�� ����һ��
    multimap<double, int, greater<int>> groupScore; // ��ʱ�����ŷ��� ѡ�ֱ��

    srand((unsigned) time(0));
    // �������в���ѡ��
    for (auto it = vSrc.begin(); it != vSrc.end(); ++it) {
        num++;
        deque<double> d; // ��¼��ί�ķ���
        for (int i = 0; i < 10; ++i) {
            double score = (rand() % 401 + 600) / 10.f;
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<double>()); // ��������
        d.pop_back(); // ȥ����ͷ�
        d.pop_front(); // ȥ����߷�

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double) d.size();

        this->m_Speaker[*it].m_Score[m_Index - 1] = avg;

        groupScore.insert(make_pair(avg, *it)); // ���ɼ�+��Ŵ��ȥ ����
        if (num % 6 == 0) {
            cout << "��" << num / 6 << "С���������:" << endl;
            for (auto it = groupScore.begin(); it != groupScore.end(); ++it) {
                cout << "\t���: " << it->second << "\t����: " << this->m_Speaker[it->second].m_Name << "\t����: "
                     << it->first << endl;
            }
            int count = 0;
            // ȡǰ��
            for (auto it = groupScore.begin(); it != groupScore.end(); ++it) {
                if (this->m_Index == 1) {
                    v2.push_back((*it).second); // ���ѡ�ֱ��
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
    cout << "----------�� " << this->m_Index << " �ֱ�������----------" << endl;
    system("pause");
}

void SpeechMgr::showScore() {
    cout << endl;
    vector<int> v;
    if (this->m_Index == 1) {
        cout << "---------- �� " << this->m_Index << " �ֽ���ѡ����Ϣ����----------" << endl;
        v = v2;
    } else {
        cout << "--------- ��ϲ����ѡ�ֻ�ʤ ----------" << endl;
        v = Victory;
    }
    cout << endl;
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << "ѡ�ֱ��: " << *it << "\t����: " << this->m_Speaker[*it].m_Name
             << "\t�÷�: " << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
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
    cout << "��¼�ѱ���" << endl;
}

void SpeechMgr::loadRecord() {
    ifstream ifs("speech.csv", ios::in);
    if (!ifs.is_open()) { // �ļ�������
        cout << "file not exist" << endl;
        this->fileEmpty = true;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof()) { // �ļ�Ϊ��
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
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
        return;
    }
    for (int i = 0; i < this->m_Record.size(); ++i) {
        cout << "��" << i + 1 << "���ݽ�������ʤ��\n" <<
             "�ھ�: " << "�������: " << this->m_Record[i][0] <<
             "\tѡ������: " << this->m_Record[i][1] <<
             "\t�÷�: " << this->m_Record[i][2] <<
             "\n�Ǿ�: " << "�������: " << this->m_Record[i][3] <<
             "\tѡ������: " << this->m_Record[i][4] <<
             "\t�÷�: " << this->m_Record[i][5] <<
             "\n����: " << "�������: " << this->m_Record[i][6] <<
             "\tѡ������: " << this->m_Record[i][7] <<
             "\t�÷�: " << this->m_Record[i][8] << endl;
        cout << endl;
    }
}

void SpeechMgr::clean_File() {
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

    int select = 0;
    cin >> select;
    if (select == 2) {
        cout << "ȡ������" << endl;
        return;
    }
    ofstream ofs("speech.csv", ios::trunc);
    ofs.close();

    this->init();
    cout << "������" << endl;
}

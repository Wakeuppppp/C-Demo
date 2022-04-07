#include <iostream>
#include "speechMgr.h"

using namespace std;

void menu() {
    int choice;
    while (true) {
        SpeechMgr sm;
        sm.showMenu();
        cout << "��ѡ��:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "��ӭ�´�ʹ��" << endl;
                return;
            case 1: {
                sm.startSpeech();
                system("pause");
                break;
            }
            case 2:
                sm.showRecord();
                system("pause");
                break;
            case 3:
                sm.clean_File();
                system("pause");
                break;
            default:
                cout << "�������, ����������" << endl;
                break;
        }
    }
}

int main() {


    menu();

    return 0;
}

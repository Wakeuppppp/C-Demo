#include <iostream>
#include "speechMgr.h"

using namespace std;

void menu() {
    int choice;
    while (true) {
        SpeechMgr sm;
        sm.showMenu();
        cout << "请选择:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "欢迎下次使用" << endl;
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
                cout << "输入错误, 请重新输入" << endl;
                break;
        }
    }
}

int main() {


    menu();

    return 0;
}

#include <iostream>
#include "speechMgr.h"

using namespace std;

void menu() {
    SpeechMgr sm;
    int choice;
    while (true) {
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
//                sm.show_Emp();
                system("pause");
                break;
            case 3:
//                sm.del_Emp();
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

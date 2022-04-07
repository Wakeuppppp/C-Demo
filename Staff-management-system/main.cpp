#include <iostream>
#include "workerMgr.h"

using namespace std;

void start() {
    WorkerMgr wm;
    int choice = 0;
    while (true) {
        wm.showMenu();
        cout << "��ѡ��:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "��ӭ�´�ʹ��" << endl;
                return;
            case 1: {
                wm.add_Emp();
                system("pause");
                break;
            }
            case 2:
                wm.show_Emp();
                system("pause");
                break;
            case 3:
                wm.del_Emp();
                system("pause");
                break;
            case 4:
                wm.modify();
                system("pause");
                break;
            case 5:
                wm.search();
                system("pause");
                break;
            case 6:
                wm.sort_Emp();
                system("pause");
                break;
            case 7:
                wm.clean_File();
                system("pause");
                break;
            default:
                cout << "�������, ����������" << endl;
                break;
        }
    }
}


int main() {
    start();
    return 0;
}



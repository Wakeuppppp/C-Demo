#include <iostream>
#include "workerMgr.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

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
                break;
            }
            case 2:
                cout << "��ʾ" << endl;
                break;
            case 3:
                cout << "ɾ��" << endl;
                break;
            case 4:
                cout << "�޸�" << endl;
                break;
            case 5:
                cout << "����" << endl;
                break;
            case 6:
                cout << "����" << endl;
                break;
            case 7:
                cout << "���" << endl;
                break;
            default:
                cout << "�������, ����������" << endl;
                system("cls");
                break;
        }
    }
}

int main() {
    start();

    return 0;
}

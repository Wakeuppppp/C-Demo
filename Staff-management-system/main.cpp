#include <iostream>
#include "workerMgr.h"
#include "worker.h"
#include "employee.h"

using namespace std;

int main() {
    WorkerMgr wm;
    int choice = 0;
    while (true) {
        wm.showMenu();
        cout << "��ѡ��:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "��ӭ�´�ʹ��" << endl;
                return 0;
            case 1: {
                cout << "����" << endl;
                Worker *worker = NULL;
                worker = new Employee(1, "Jack", 2);
                worker->showInfo();
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
    return 0;
}

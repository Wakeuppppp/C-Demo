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
        cout << "请选择:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "欢迎下次使用" << endl;
                return;
            case 1: {
                wm.add_Emp();
                break;
            }
            case 2:
                cout << "显示" << endl;
                break;
            case 3:
                cout << "删除" << endl;
                break;
            case 4:
                cout << "修改" << endl;
                break;
            case 5:
                cout << "查找" << endl;
                break;
            case 6:
                cout << "排序" << endl;
                break;
            case 7:
                cout << "清空" << endl;
                break;
            default:
                cout << "输入错误, 请重新输入" << endl;
                system("cls");
                break;
        }
    }
}

int main() {
    start();

    return 0;
}

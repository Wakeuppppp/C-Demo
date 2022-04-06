#include <iostream>
#include "workerMgr.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

int main() {
    WorkerMgr wm;
    int choice = 0;
    while (true) {
        wm.showMenu();
        cout << "请选择:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "欢迎下次使用" << endl;
                return 0;
            case 1: {
                cout << "增加" << endl;
                Worker *worker;
                worker = new Employee(1, "Jack", 2);
                worker->showInfo();
                delete worker;

                worker = new Manager(2, "Dany", 3);
                worker->showInfo();
                delete worker;

                worker = new Boss(3, "Marine", 4);
                worker->showInfo();
                delete worker;
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

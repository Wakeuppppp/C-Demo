#include <iostream>
#include <string>
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include <fstream>
#include "globalFile.h"

using namespace std;

void studentMenu(Identity *&student) {
    while (true) {
        student->showMenu();
        Student *man = (Student *) student;
        int select = 0;
        cin >> select;
        switch (select) {
            case 1:
                man->applyOrder();
                break;
            case 2:
                man->showMyOrder();
                system("pause");
                break;
            case 3:
                man->showAllOrder();
                break;
            case 4:
                man->cancelOrder();
                break;
            case 0: {
                delete student;
                cout << "注销成功" << endl;
                system("pause");
                return;
            }
            default: {
                cout << "wrong!" << endl;
                system("pause");
                break;
            }
        }
    }
}

void teacherMenu(Identity *&teacher) {
    while (true) {
        teacher->showMenu();
        Teacher *man = (Teacher *) teacher;
        int select = 0;
        cin >> select;
        switch (select) {
            case 1:
                man->showAllOrder();
                system("pause");
                break;
            case 2:
                man->auditOrder();
                system("pause");
                break;
            case 0: {
                delete teacher;
                cout << "注销成功" << endl;
                system("pause");
                return;
            }
            default: {
                cout << "wrong!" << endl;
                system("pause");
                break;
            }
        }
    }
}

void managerMenu(Identity *&manager) {
    while (true) {
        manager->showMenu();
        Manager *man = (Manager *) manager;
        int select = 0;
        cin >> select;
        switch (select) {
            case 1:
                man->addAccount();
                break;
            case 2:
                man->showAccount();
                break;
            case 3:
                man->showInfo();
                break;
            case 4:
                man->cleanFile();
                break;
            case 0: {
                delete manager;
                cout << "注销成功" << endl;
                system("pause");
                return;
            }
            default: {
                cout << "wrong!" << endl;
                system("pause");
                break;
            }
        }
    }
}

void login(string fileName, int type) {
    Identity *person;
    ifstream ifs;
    ifs.open(fileName, ios::in);
    if (!ifs.is_open()) {
        cout << "文件不存在" << endl;
        ifs.close();
        return;
    }
    int id = 0;
    int fId = 0;
    string fName;
    string name;
    string fPwd;
    string pwd;

    bool flag = false;

    switch (type) {
        case 1: {
            cout << "请输入学号: ";
            cin >> id;
            cout << "请输入密码: ";
            cin >> pwd;
            while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
                if (id == fId && pwd == fPwd) {
                    flag = true;
                    name = fName;
                    cout << "登陆成功, 欢迎学生 " << fName << " 进入系统" << endl;
                    person = new Student(id, name, pwd);
                    studentMenu(person);
                }
            }
            if (!flag) {
                cout << "登陆失败" << endl;
                system("pause");
            }
            break;
        }
        case 2: {
            cout << "请输入职工号: ";
            cin >> id;
            cout << "请输入密码: ";
            cin >> pwd;
            while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
                if (id == fId && pwd == fPwd) {
                    flag = true;
                    name = fName;
                    cout << "登陆成功, 欢迎教职工 " << fName << " 进入系统" << endl;
                    person = new Teacher(id, name, pwd);
                    teacherMenu(person);
                }
            }
            if (!flag) {
                cout << "登陆失败" << endl;
                system("pause");
            }
            break;
        }
        case 3: {
            cout << "请输入管理员名: ";
            cin >> name;
            cout << "请输入密码: ";
            cin >> pwd;
            while (ifs >> fName && ifs >> fPwd) {
                if (name == fName && pwd == fPwd) {
                    flag = true;
                    cout << "登陆成功, 欢迎管理人员 " << fName << " 登陆" << endl;
                    person = new Manager(name, pwd);
                    managerMenu(person);
                }
            }
            if (!flag) {
                cout << "登陆失败" << endl;
                system("pause");
            }
            break;
        }
        default:
            cout << "错误" << endl;
            break;
    }
}

void menu() {
    int choice = 0;
    Identity *person;
    while (1) {
        cout << "======================  欢迎来到机房预约系统  =====================" << endl;
        cout << endl << "请输入您的身份" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.学生代表             |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.老    师            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.管 理 员            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.退    出            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "输入您的选择: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                login(STUDENT_FILE, 1);
                break;
            }

            case 2: {
                login(TEACHER_FILE, 2);
                break;
            }
            case 3: {
                login(ADMIN_FILE, 3);
                break;
            }
            case 0: {
                cout << "欢迎下次使用" << endl;
                system("pause");
                return;
            }
            default: {
                cout << "输入有误 请重新输入" << endl;
                system("pause");
                break;
            }
        }
    }
}

int main() {
    menu();
    return 0;
}

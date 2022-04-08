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
                cout << "ע���ɹ�" << endl;
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
                cout << "ע���ɹ�" << endl;
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
                cout << "ע���ɹ�" << endl;
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
        cout << "�ļ�������" << endl;
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
            cout << "������ѧ��: ";
            cin >> id;
            cout << "����������: ";
            cin >> pwd;
            while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
                if (id == fId && pwd == fPwd) {
                    flag = true;
                    name = fName;
                    cout << "��½�ɹ�, ��ӭѧ�� " << fName << " ����ϵͳ" << endl;
                    person = new Student(id, name, pwd);
                    studentMenu(person);
                }
            }
            if (!flag) {
                cout << "��½ʧ��" << endl;
                system("pause");
            }
            break;
        }
        case 2: {
            cout << "������ְ����: ";
            cin >> id;
            cout << "����������: ";
            cin >> pwd;
            while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
                if (id == fId && pwd == fPwd) {
                    flag = true;
                    name = fName;
                    cout << "��½�ɹ�, ��ӭ��ְ�� " << fName << " ����ϵͳ" << endl;
                    person = new Teacher(id, name, pwd);
                    teacherMenu(person);
                }
            }
            if (!flag) {
                cout << "��½ʧ��" << endl;
                system("pause");
            }
            break;
        }
        case 3: {
            cout << "���������Ա��: ";
            cin >> name;
            cout << "����������: ";
            cin >> pwd;
            while (ifs >> fName && ifs >> fPwd) {
                if (name == fName && pwd == fPwd) {
                    flag = true;
                    cout << "��½�ɹ�, ��ӭ������Ա " << fName << " ��½" << endl;
                    person = new Manager(name, pwd);
                    managerMenu(person);
                }
            }
            if (!flag) {
                cout << "��½ʧ��" << endl;
                system("pause");
            }
            break;
        }
        default:
            cout << "����" << endl;
            break;
    }
}

void menu() {
    int choice = 0;
    Identity *person;
    while (1) {
        cout << "======================  ��ӭ��������ԤԼϵͳ  =====================" << endl;
        cout << endl << "�������������" << endl;
        cout << "\t\t -------------------------------\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          1.ѧ������             |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          2.��    ʦ            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          3.�� �� Ա            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t|          0.��    ��            |\n";
        cout << "\t\t|                               |\n";
        cout << "\t\t -------------------------------\n";
        cout << "��������ѡ��: ";
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
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return;
            }
            default: {
                cout << "�������� ����������" << endl;
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

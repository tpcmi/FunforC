#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class student
{
};

void intro();
void result();       //结果查询页面
void class_result(); //班级结果查询
void student_result(int);  //学生结果查询
void edit();

int main()
{

    char op;
    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t01. RESULT MENU";
        cout << "\n\n\t02. EDIT MENU";
        cout << "\n\n\t03. EXIT";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> op;
        switch (op)
        {
        case '1':
            result();
            break;
        case '2':
            edit();
            break;
        case '3':
            break;
        default:
            cout << "Invalid option! Press any key... ";
            cin.ignore();
            cin.get();
        }

    } while (op != '3');
    cout << "\n\n\tThanks for using the system!\n"
         << endl;
    return 0;
}

void intro()
{
    cout << "#####################################";
    cout << "\n#                                   #";
    cout << "\n#      BANK MANAGEMENT SYSTEM       #";
    cout << "\n#                                   #";
    cout << "\n#           MADE BY BRYCE           #";
    cout << "\n#                                   #";
    cout << "\n#          COMPANY : TPCMI          #";
    cout << "\n#                                   #";
    cout << "\n#####################################";

    cout << "\n\nPress Enter To Continue.";
    cin.get();
}

void result()
{
    char op;
    int num;
    do
    {
        system("cls");
        cout << "\n\n\n\tRESULT MENU";
        cout << "\n\n\n\t1. Class Result";
        cout << "\n\n\t2. Student Report Card";
        cout << "\n\n\t3. Back to Main Menu";
        cout << "\n\n\n\tEnter Choice (1/2/3)? ";
        cin >> op;
        system("cls");

        switch (op)
        {
        case '1':
            class_result();
            break;
        case '2':
            cout << "\n\n\tEnter the ID of student : ";
            cin >> num;
            student_result(num);
            break;
        case '3':
            break;
        default:
            cout << "Invalid option! Press any key...";
            cin.ignore();
            cin.get();
        }
    } while (op!='3');
    
}

void class_result()
{

}

void student_result(int num)
{

}

void edit()
{
}

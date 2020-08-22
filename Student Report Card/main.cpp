#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class student
{
private:
    int id;
    char name[50];
    int pMarks, cMarks, mMarks, eMarks, csMarks;
    double per;
    char grade;
    void calculate();   //计算学生grade
public:
    void getdata(); //接收学生数据
    void showdata() const;    //显示学生成绩
    void showdatatab() const;   //以表格显示学生数据
    int return_id() const { return id; }; //返回学生id
};

void student::calculate()
{
    per = (pMarks + cMarks + mMarks + eMarks + csMarks) / 5.0;
    if(per>=60)
        grade = 'A';
    else if(per>=50)
        grade = 'B';
    else if(per>=33)
        grade = 'C';
    else
        grade = 'F';
}

//检查id是否已经存在，输入的成绩是否符合数值范围
void student::getdata() 
{
    cout<<"\nEnter the id of student :";
    cin >> id;
    cout << "\nEnter the name of student :";
    cin.ignore();
    cin.getline(name,50);
    cout << "\nEnter the mark of Physics (0-100) :";
    cin >> pMarks;
    cout << "\nEnter the mark of Chemistry (0-100) :";
    cin >> cMarks;
    cout << "\nEnter the mark of Math (0-100) :";
    cin >> mMarks;
    cout << "\nEnter the mark of English (0-100) :";
    cin >> eMarks;
    cout << "\nEnter the mark of Computer Science (0-100) :";
    cin >> csMarks;
    calculate();
}

void student::showdata() const
{
    cout<<"\nId of student : "<<id;
	cout<<"\nName of student : "<<name;
	cout<<"\nMarks in Physics : "<<pMarks;
	cout<<"\nMarks in Chemistry : "<<cMarks;
	cout<<"\nMarks in Maths : "<<mMarks;
	cout<<"\nMarks in English : "<<eMarks;
	cout<<"\nMarks in Computer Science :"<<csMarks;
	cout<<"\nPercentage of student is  :"<<per;
	cout<<"\nGrade of student is :"<<grade;
}

void student::showdatatab() const
{
    cout<<id<<setw(6)<<" "<<name<<setw(10)<<pMarks<<setw(4)<<cMarks<<setw(4)<<mMarks<<setw(4)<<eMarks<<setw(4)<<csMarks<<setw(8)<<per<<setw(6)<<grade<<endl;
}

void intro();
void result();       //结果查询页面
void class_result(); //班级结果查询
void student_result(int);  //学生结果查询
void edit();
void create_student_record();
void display_all_students();
void modify_record(int);
void delete_record(int);

int main()
{

    char op;
    intro();
    do
    {
        system("clear");
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
        system("clear");
        cout << "\n\n\n\tRESULT MENU";
        cout << "\n\n\n\t1. Class Result";
        cout << "\n\n\t2. Student Report Card";
        cout << "\n\n\t3. Back to Main Menu";
        cout << "\n\n\n\tEnter Choice (1/2/3)? ";
        cin >> op;
        system("clear");

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
    student st;
    ifstream file;
    file.open("student.dat", ios::binary);
    if(!file)
    {
        cout << "File could not open! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\tALL STUDENT RESULT\n\n";
    cout << "==========================================================\n";
    cout << " ID       Name        P   C   M   E   CS    Per   Grade" << endl;
    cout << "==========================================================\n";
    while(file.read(reinterpret_cast<char *>(&st),sizeof(student)))
        st.showdatatab();
    cout << "\n\tPress any key...";
    cin.ignore();
    cin.get();
    file.close();
}

void student_result(int num)
{
    student st;
    ifstream file;
    bool found = false;
    file.open("student.dat",ios::binary);
    if(!file)
    {
        cout << "File could not open! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(file.read(reinterpret_cast<char *>(&st),sizeof(student)))
    {
        if(st.return_id()==num)
        {
            st.showdata();
            found = true;
        }
    }
    file.close();
    if(found==false)
        cout << "\n\nRecord not exit!";
    cin.ignore();
    cin.get();
}

void edit()
{
    char op;
    int num;
    system("cls");
    cout<<"\n\n\n\tEDIT MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout<<"\n\n\t3.SEARCH STUDENT RECORD ";
	cout<<"\n\n\t4.MODIFY STUDENT RECORD";
	cout<<"\n\n\t5.DELETE STUDENT RECORD";
	cout<<"\n\n\t6.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
    cin >> op;
    system("cls");
    switch(op)
    {
        case '1':
            create_student_record();
            break;
        case '2':
            display_all_students();
            break;
        case '3':
            cout << "\n\n\tEnter the student id: ";
            cin >> num;
            student_result(num);
            break;
        case '4':
            cout << "\n\n\tEnter the student id: ";
            cin >> num;
            modify_record(num);
            break;
        case '5':
            cout << "\n\n\tEnter the student id: ";
            cin >> num;
            delete_record(num);
            break;
        case '6':
            break;
        default:
            cout << "Invalid option! Choose again!";
            edit();
    }
}

void create_student_record()
{
    student st;
    ofstream file;
    file.open("student.dat", ios::binary | ios::app);
    st.getdata();
    file.write(reinterpret_cast<char *>(&st), sizeof(student));
    file.close();
    cout << "\n\nStudent record has been created ";
    cin.ignore();
    cin.get();
}

void display_all_students()
{
    student st;
    ifstream file;
    file.open("student.dat", ios::binary);
    if(!file)
    {
        cout << "File could not open! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\n\t\tDISPLAY ALL STUDENT\n\n";
    while(file.read(reinterpret_cast<char*>(&st),sizeof(student)))
    {
        st.showdata();
        cout << "\n\n============================================\n";
    }
    cout << "Press any key...";
    file.close();
    cin.ignore();
    cin.get();
}

void modify_record(int num)
{
    student st;
    fstream file;
    bool found = false;
    file.open("student.dat",ios::binary|ios::in|ios::out);
    if(!file)
    {
        cout << "File could not open! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!file.eof()&&found==false)
    {
        file.read(reinterpret_cast<char *>(&st), sizeof(student));
        if(st.return_id()==num)
        {
            st.showdata();
            cout << "\n\nPlease enter the new details of student." << endl;
            st.getdata();
            int pos = (-1) * static_cast<int>(sizeof(st));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&st), sizeof(student));
            found = true;
        }
    }
    file.close();
    if(found==false)
        cout << "\n\n Record Not Exit. Press any key...";
    else
        cout << "\n\n\t Record Updated.Press any key...";
    cin.ignore();
    cin.get();
}

void delete_record(int num)
{
    student st;
    ifstream ifile;
    ifile.open("student.dat", ios::binary);
    if(!ifile)
    {
        cout << "File could not open! Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream ofile;
    ofile.open("temp.dat", ios::out);
    ifile.seekg(0, ios::beg);
    while(ifile.read(reinterpret_cast<char *>(&st),sizeof(student)))
    {
        if(st.return_id()!=num)
            ofile.write(reinterpret_cast<char *>(&st), sizeof(student));
    }
    ofile.close();
    ifile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    cout << "\n\n\tRecord deleted! Press any key...";
    cin.ignore();
    cin.get();
}

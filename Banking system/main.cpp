#include<iostream>

using namespace std;

class account{
public:
    char user[50];
    int deposit;
    int account_number;
    void create_account();  //创建账户
    void show_account();    //显示数据库中当前所有账户信息
    void modify();  //修改账户所属
    void access(int&,int&);  //存取
};

// Todo:检查新创建账户序号是否冲突
void account::create_account(){
    cout << "\nEnter The Account No.:";
    cin >> account_number;
    cout << "\nEnter Your Name:";
    cin.ignore();
    cin.getline(user,50);
    cout<<"\nEnter The Initioal amount(>=0): ";
    cin >> deposit;
    cout << "\n\n\nAccount Created Successfully! ";
}

void account::show_account(){
    cout << "\nAccount No.:" << account_number;
    cout << "\nAccount Holder Name: " << user;
    cout << "\nBalance Amount: " << deposit;
}

// Todo:修改账户分为新建账户和已有账户
void account::modify(){
    cout << "\nAccount No.:" << account_number;
    cout << "\n Modify Account Holder Name: ";
    cin.ignore();
    cin.getline(user, 50);
    cout << "\nModify Balance amount: ";
    cin >> deposit;
}

void account::access(int &flag,int &num){
    if(flag)
        deposit += num;
    else
        deposit -= num;
}

void intro();   //介绍

int main(){

    char ch;
    intro();
    do{
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE INQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. DELETE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
		system("cls");
        switch(ch){
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                cout<<"\n\n\tThanks for using bank managemnt system!\n";
                break;
            default:
                cout << "\n\n\tInvalid Operation! Select again!";
        }
        if(ch!='8'){
            cin.ignore();
            cin.get();
        }
    } while (ch != '8');

    return 0;

}

void intro(){
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




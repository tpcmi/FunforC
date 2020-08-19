#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class account{
public:
    char user[50];
    int deposit;
    int account_number;
    void create_account();  //创建账户
    void show_account();    //显示数据库中当前所有账户信息
    void modify();  //修改账户所属
    void access(int,int);  //存取
    int return_no() const { return account_number; }    //返回账户账号
    int return_deposit() const { return deposit; }  //返回存款数额
    void report() const;  //返回账户信息
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

void account::access(int flag,int num){
    if(flag)
        deposit += num;
    else
        deposit -= num;
}

void account::report() const {
    cout<<account_number<<setw(10)<<" "<<user<<setw(10)<<deposit<<endl;
}

void intro();   //介绍
void write_account();   //创建用户
void deposit_withdraw(int,int);
void display_deposit(int);   //显示余额
void display_all(); //显示所有账户信息
int main()
{

    char op;    //选项
    int num;
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
		cin>>op;
		system("cls");
        switch(op){
            case '1':
                write_account();
                break;
            case '2':
                cout << "\n\n\tEnter the account No. :";
                cin >> num;
                deposit_withdraw(num, 1);
                break;
            case '3':
                cout << "\n\n\tEnter the account No. :";
                cin >> num;
                deposit_withdraw(num, -1);
                break;
            case '4':
                cout << "\n\n\tEnter the account No. :";
                cin >> num;
                display_deposit(num);
                break;
            case '5':
                display_all();
                break;
            case '6':
            case '7':
            case '8':
                cout<<"\n\n\tThanks for using bank managemnt system!\n";
                break;
            default:
                cout << "\n\n\tInvalid Operation! Select again!";
        }
        if(op!='8'){
            cin.ignore();
            cin.get();
        }
    } while (op != '8');

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

void write_account(){
    account ac;
    ofstream outfile;
    outfile.open("account.dat", ios::binary | ios::app);    //以二进制方式在文件末尾添加数据
    ac.create_account();
    outfile.write(reinterpret_cast<char *>(&ac),sizeof(account));   //强制转换为char型；
    outfile.close();
}

//Todo:取钱失败后选择重新输入金额还是退出主页面
void deposit_withdraw(int num, int option){
    account ac;
    fstream file;
    bool found = false;
    int amount;
    file.open("account.dat", ios::binary | ios::in | ios::out);
    if(!file){
        cout << "File could not be open! Press any key....";
        return;
    }
    while(!file.eof() && found==false){
        file.read(reinterpret_cast<char *>(&ac), sizeof(account));
        if(ac.return_no()==num){
            ac.show_account();
            if(option==1){
                cout << "\n\n\tEnter the amount to be deposited";
                cin >> amount;
                ac.access(option, amount);
            }
            else{
                cout << "\n\n\tEnter the amount to be withdrawn";
                cin >> amount;
                int pre = ac.return_deposit();
                if(amount>pre)
                    cout << "Insufficient balance!";
                else
                    ac.access(option, amount);
            }
            // 
            int pos = (-1) * static_cast<int>(sizeof(ac));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char *>(&ac),sizeof(account));
            cout << "\n\n\tRecord updated ";
            found = true;
        }
    }
    file.close();
    if(found==false)
        cout << "\n\nRecord Not Found!";
}

void display_deposit(int num){
    account ac;
    bool found = false;
    ifstream file;
    file.open("account.dat", ios::binary);
    if(!file){
        cout << "File could not open! Press any key...";
        return;
    }
    cout << "\nBalance details\n";
    while(file.read(reinterpret_cast<char *>(&ac),sizeof(account))){
        if(ac.return_no()==num){
            ac.show_account();
            found = true;
        }
    }
    file.close();
    if(found==false)
        cout << "\n\nAccount number dose not exist!";
}

void display_all(){
    account ac;
    ifstream file;
    file.open("account.dat",ios::binary);
    if(!file){
        cout << "File could not open! Press any key...";
        return;
    }
    cout << "\n\n\tAccount holder list\n\n";
    cout<<"==========================================\n";
	cout<<"A/c no.      NAME           Balance\n";
	cout<<"==========================================\n";
    while(file.read(reinterpret_cast<char*>(&ac),sizeof(account)))
        ac.report();
    file.close();
}



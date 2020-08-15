#include<iostream>

using namespace std;

char square[10] = {'_','1', '2', '3', '4', '5', '6', '7', '8', '9'};

void board();
int checkwin(int &);

int main(){
	char label;
	cout << "Start Game? (y/n)";
	cin >> label;
	while(label=='y'){
		int player = 1,flag,choice,count = 0;
		char mark;
		do{
			board();
			player = (player % 2) ? 1 : 2;
			cout << "Player " << player << ", enter a number:   ";
			cin >> choice;
			count++;
			mark = (player == 1) ? 'X' : 'O';
			if (choice==square[choice]-'0')
				square[choice] = mark;
			else{
				cout << "Invalid move";
				player--;
				cin.ignore();
				cin.get();
				count--;
			}
			flag = checkwin(count);
			player++;
		} while(flag==-1);
		board();
		if(flag==1)
			cout << "==> Player " << --player << " win!\n";
		else
			cout << "Game draw!\n" << endl;

		cout << "Restart Game? (y/n)";
		cin >> label;
	}
	return 0;
}
	

// 检查对局情况；
int checkwin(int &count){
    if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (count==9)
		return 0;
	else
		return -1;
	}

// 更改屏幕值；
void board(){
	system("cls");
	cout << "=== Tic tac toe ===" << endl;
	cout << "Player 1: 'X' , Player 2: 'O' " << endl;
	cout << endl;
	cout << "   " << "  |     |  " <<  endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
	cout << "_____|_____|_____" <<  endl;
	cout << "     |     |  " << endl;
	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |  " << endl;
	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
	cout << "     |     |     " << endl;
}
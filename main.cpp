//This code is normaly written with Visual Studio 2019 which will display warnings
//The symbols 🍒, 🔔, 🍋, 🍊, ⭐, 💀 is found from the internet which might be copyright
//Written by ocean2top
//Developed using C++

//Vesrion 1.0

#include <iostream> //cout << and cin >>
#include <stdio.h> //printf(), scanf()
#include <sstream> //Covert string to integer
#include <cstdlib> //Random number generation rand()
#include <time.h> //sleep(), time()
#include "Checkdatatype.h" //Get header file

//#include <ctime> //Gets the real live time time() //Not needed if <time.h> works
//#include <stdlib.h> //Convert string to integer atoi() or exit() //Only C++ 11
//#include <windows.h> //Sleep( milliseconds ); //Not working in repl.it

//#define _CRT_SECURE_NO_WARNINGS //Not working in repl.it
//#pragma warning(disable : 4566) //Not working in repl.it

using namespace std; //Not need to type std::

int credit = 100;

string symbols[6] = { "🍒", "🔔", "🍋", "🍊", "⭐", "💀"};

void Jackpot(int* n1, int* n2, int* n3);

void Slection(int n);

void FruitMachine() //Function that starts the game.
{
	credit = credit - 20;
	int num[3];
	cout << '\n';
  printf("JACKPOT MACHINE\n ");
	srand((int)time(0));
	for (int i = 0; i < 3; i++)
	{
		num[i] = rand() % 6;
		cout << symbols[num[i]];
		if (i != 2)
			cout << "  | ";

	}
	cout << "\n\n";
	Jackpot(&num[0], &num[1], &num[2]);
}

int DisplayMenu() //Displys the main menu and get a input.
{
	bool repeat = true;
	while (repeat)
	{
		if (credit <= 0)
		{
			cout << '\n';
			cout << "Your current credit is £0\n";
			cout << '\n';
			cout << "Gameover!";
			exit(0);
		}
		string choice;
		cout << "                 MAINMENU\n";
		cout << "--------------------------------------------\n";
		cout << "1. Spin The wheel (20p to spin)\n";
		cout << "2. Check credit\n";
		cout << "9. Quit\n";
		cout << "--------------------------------------------\n\n";
		cout << "What do you want to do?: ";
		cin >> choice;
		if (!Validation(choice))
		{
			cout << '\n' << "Invalid Synatax!\n" << "Please try again\n\n";
		}
		else
		{
			repeat = false;
			stringstream integer(choice);
			int value;
			integer >> value;
			return value;
		}
	}
	return 0;
}

int main() //This is where the program starts
{
	int num = DisplayMenu();
	Slection(num);
	return 0;
}

void Jackpot(int* n1, int* n2, int* n3)
{
	if (symbols[*n1] == "🔔" && symbols[*n1] == symbols[*n2] && symbols[*n1] == symbols[*n3] && symbols[*n2] == symbols[*n3])
	{
		cout << "Jackpot!\n";
		credit = credit + 500;
	}
	else if (symbols[*n1] == "💀" && symbols[*n1] == symbols[*n2] && symbols[*n1] == symbols[*n3] && symbols[*n2] == symbols[*n3])
	{
		cout << "Three Skulls?\n" << "Oh no...\n" << "You lost all your credit\n";
		credit = 0;
	}
	else if (symbols[*n1] == symbols[*n2] && symbols[*n1] == symbols[*n3] && symbols[*n2] == symbols[*n3])
	{
		cout << "Three Roll!\n";
		credit = credit + 100;
	}
	else if ((symbols[*n1] == "💀" && symbols[*n2] == "💀") && (symbols[*n1] == symbols[*n2]) || (symbols[*n1] == "💀" && symbols[*n3] == "💀") && (symbols[*n1] == symbols[*n3]) || (symbols[*n2] == "💀" && symbols[*n3] == "💀") && (symbols[*n2] == symbols[*n3]))
	{
		cout << "Two Skuklls?\n" << "Oh no...\n" << "You lost 1 pound from your credit\n";;
		credit = credit - 100;
	}
	else if (symbols[*n1] == symbols[*n2] || symbols[*n1] == symbols[*n3] || symbols[*n2] == symbols[*n3])
	{
		cout << "Two Roll!\n";
		credit = credit + 50;
	}
	else
		cout << "No matching\n";

	cout << '\n';
	main();
}

void Slection(int n) //Give different output depends the users input.
{
	switch (n)
	{
	case 1:
		for (int i = 0; i < 50; i++)
			cout << '\n';
		FruitMachine();
		break;

	case 2:
		int pound, pence;
		pound = credit / 100;
		pence = credit % 100;
		cout << '\n';
		if (pence == 0)
		{
			cout << "Your current credit is: " << "£" << pound << "\n\n";
			main();
		}
		else if (pound == 0)
		{
			cout << "Your current credit is: " << pence << "p" <<"\n\n";
			main();
		}
		else
		{
			cout << "Your current credit is: " << "£" << pound << " and " << pence << "p" <<"\n\n";
			main();
		}
		break;

	case 9:
		exit(0);
		break;

	case 3052:
		cout << '\n';
		cout << "You have access the secret menu!\n";
		int choice;
		bool repeat;
		repeat = true;
		while (repeat)
		{
			cout << '\n';
			cout << "     SECRETMENU\n";
			cout << "-------------------\n";
			cout << "1. Change credit\n";
			cout << "9. Quit secret menu\n";
			cout << "-------------------\n\n";
			cout << "What do you want to do?: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << '\n';
				cout << "Type a credit that you want to change: ";
				cin >> credit;
				break;

			case 9:
				repeat = false;
				break;

			default:
				cout << '\n';
				cout << "Not valid a choice\n";
				break;
			}
			if (!repeat)
			{
				cout << '\n';
				main();
			}
		}
		break;

	default:
		cout << '\n' << "Not able currently\n\n";
		main();
		break;
	}
}
#include <iostream>
#include <iomanip>
#include <cstdlib> 

//I want the "Main" to be the 'Start' function
#define Start main

//I'm not writing std for ever cout, cin, and endl
using namespace std;

//Variables
char board[10];
int scores[2];
bool turn = 0;

//Functions
void Print();
void Update();
char Comparater(char, int);
void CheckScore();
void Restart();
char ToString(int);

//Start the loop
int Start() 
{
	cout << "Test";
	//initalize Start method
	for (int i = 0; i < (sizeof(board) / sizeof(*board)); i++)
	{
		//Null all the indexes
		board[i] = NULL;
	}

	//Call the print function to draw the board
	Print();


	return 0;
}

//The Print function that draws all the data to the screen
void Print()
{
	system("CLS");
	cout << "It is " << (turn ? "X's turn" : "O's turn") << endl;
	cout << " " << Comparater(board[1], 1) << " | " << Comparater(board[2], 2) << " | " << Comparater(board[3], 3) << "          CAT:" << scores[0] << endl;
	cout << "-----------" << endl;
	cout << " " << Comparater(board[4], 4) << " | " << Comparater(board[5], 5) << " | " << Comparater(board[6], 6) << "            X:" << scores[1] << endl;
	cout << "-----------" << endl;
	cout << " " << Comparater(board[7], 7) << " | " << Comparater(board[8], 8) << " | " << Comparater(board[9], 9) << "            O:" << scores[2] << endl;
	Update();
}

void Update() 
{
	//check to see if someone has won
	CheckScore();

	//Get the players input
	int x;
	cout << "\n\nEnter your choice: ";
	cin >> x;

	//Validate the input
	while (x < 1 || x > 9 || board[x] != NULL)
	{
		cout << "\n" << x << " has already bee chosen...";

		cout << "\nEnter your choice: ";
		cin >> x;
	}

	//See whoms turn it is, peep the dankkkk ternary operator
	board[x] = (turn ? 'X' : 'O');
	turn = !turn;

	//Re-Draw the screen with the updated data
	Print();
}

//Check if the value is NULL and if so draw that number's index to the screen
char Comparater(char value, int index) 
{
	if (value == NULL)
	{
		return ToString(index); //Cast to a string ("char") variable
	}
	else
		return value; //If it is valid return it back
}

//Have we won?
void CheckScore()
{
	//Vertical Check
	for (int i = 1; i < 3; i++)
	{
		if (board[i] != NULL)
		{
			if (board[i] == board[i] && board[i + 3] == board[i] && board[i + 6] == board[i])
			{
				turn ? scores[2]++ : scores[1]++;
				cout << board[i] << " has won!" << endl;
				Restart();
			}
		}
	}

	//Horizontal Check
	for (int i = 1; i < 9; i += 3)
	{
		if (board[i] != NULL)
		{
			if (board[i] == board[i] && board[i + 1] == board[i] && board[i + 2] == board[i])
			{
				turn ? scores[2]++ : scores[1]++;
				cout << board[i] << " has won!" << endl;
				Restart();
			}
		}
	}

	//Diagonal Check '\'
	if (board[1] != NULL)
	{
		if (board[1] == board[1] && board[5] == board[1] && board[9] == board[1])
		{
			turn ? scores[2]++ : scores[1]++;
			cout << board[1] << " has won!" << endl;
			Restart();
		}
	}
	//Diagonal Check '/'
	if (board[3] != NULL)
	{
		if (board[3] == board[3] && board[5] == board[3] && board[7] == board[3])
		{
			turn ? scores[2]++ : scores[1]++;
			cout << board[3] << " has won!" << endl;
			Restart();
		}
	}

	//Check to see if all the places are gone - a 'CAT'
	bool flag = false;
	for (int i = 1; i < (sizeof(board) / sizeof(*board)); i++)
	{
		if (board[i] == NULL)
			flag = true;
	}
	//If none of the places are NULL there is no places left and thus a tie
	if (!flag)
	{
		scores[0]++;
		Restart();
	}
}

//Wanna play again?
void Restart()
{	
	char response; //Response holder

	cout << "Play again?: ";
	cin >> response;

	if (response != 'y' && response != 'Y') //check to see if it's Y or y
	{
		cout << endl;
		system("pause");
		exit(0);
	}
	else //If so Restart the game from the Start Function
		Start();
}


//Cast to char type
char ToString(int val) 
{
	return '0' + val; //The '+' Operator is overloaded to assume value type of what ever is on the left side B)
}
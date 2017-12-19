#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;

//Function Definitions

void MenuList();
void DFA();
void DFAComplement();
void InvalidCharacter();
void Accept();
void NotAccept();

//Defines arrays for DFA

#define NSTATES 4		//Number of states: q0, q1, q2, and q3
#define NCHARS 2		//Number of character: 0 and 1
#define NACCEPTS 1		//Number of states that it accepts

int L[NSTATES][NCHARS] = { {1,3}, {3,2}, {2,2}, {3,3} };	//DFA Array
int ACCEPTS[NACCEPTS] = { 2 };								//Accepts on state q1

//Defines arrays for complement of DFA

#define CSTATES 4		//Number of states: q0, q1, q2, and q3
#define CCHARS 2		//Number of character: 0 and 1
#define CACCEPTS 3		//Number of states that it accepts

int COMPL[CSTATES][CCHARS] = { { 1,3 },{ 3,2 },{ 2,2 },{ 3,3 } };	//DFA Array
int COMPACCEPTS[CACCEPTS] = { 0, 1, 3 };							//Accepts on states q0, q1, or q3

//Main Function

int main()
{
	int menu;

	MenuList();
	cout << "Please enter an option:" << endl;
	cin >> menu;

	while (menu != 3)
	{
		switch (menu)
		{
		case 1:
			DFA();
			break;

		case 2:
			DFAComplement();
			break;

		default:
			cout << "Invalid Choice" << endl;
			cin >> menu;
		}

		MenuList();
		cout << "Please enter an option:" << endl;
		cin >> menu;
	}

	return 0;
}

//Menu Function

void MenuList()
{
	cout << "1. DFA Extra Credit" << endl;
	cout << "2. DFA Complement Extra Credit" << endl;
	cout << "3. Quit" << endl;

}

//DFA Function

void DFA()
{
	
//Declare Variables

	int ch;
	int state;		//x-axis of the L array
	int i;			//y-axis of the L array
	char firstletter;
	char secondletter;
	string word;
	
//Determine Alphabet with error checking to ensure two different letters

	cout << "We are going to determine your two letter alphabet." << endl;
	cout << "What is the first letter of your alphabet going to be?" << endl;
	cin >> firstletter;
	cout << "What is the second letter of your alphabet going to be?" << endl;
	cin >> secondletter;

	while (secondletter == firstletter)
	{
		cout << "Your alphabet but contain two different letters - Please enter a different second letter" << endl;
		cin >> secondletter;
	}

	cout << "Please enter a word using your alphabet." << endl;
	cin >> word;
	
//-------------------------------------------------------------------
	
	state = 0;									//Starts at state 0
	for (int j = 0; j < word.length(); ++j)		//Starts loop to go through string one character at a time
		{
			ch = word[j];						//Sets ch as the current character in the loop
			
//This section handles the y-axis for the DFA, allowing any alphabet of the user's choice
//This will allow me to expand my alphabets in the future
			
			if (word[j] == firstletter)
			{
				ch = 0;
			}
			else if (word[j] == secondletter)
			{
				ch = 1;
			}
			else
			{
				InvalidCharacter();
			}

//-------------------------------------------------------------------
			
			cout << "Array: x = " << state << " y = " << ch << endl;		//Displays current array axes
			state = L[state][ch];
			cout << "New State: " << state << endl << endl;					//Displays new state

		}

		for (i = 0; i < NACCEPTS; i++)
			if (ACCEPTS[i] == state)
			{
				cout << "Accepted" << endl << endl;
			}

//ACCEPTS array is only one value, 2.  If the state equals 2, that means the program accepts the input and outputs "yes"

		else
			{
				cout << "Not Accepted" << endl << endl;
			}

//Else the program does not accept and outputs "no"
	
}

//DFA Complement Function

void DFAComplement()
{
	
//Declare Variables
	
	int ch;
	int state;		//x-axis of the L array
	int i;			//y-axis of the L array
	char firstletter;
	char secondletter;
	int multaccept = 0;
	string word;

//Determine Alphabet with error checking to ensure two different letters

	cout << "We are going to determine your two letter alphabet." << endl;
	cout << "What is the first letter of your alphabet going to be?" << endl;
	cin >> firstletter;
	cout << "What is the second letter of your alphabet going to be?" << endl;
	cin >> secondletter;

	while (secondletter == firstletter)
	{
		cout << "Your alphabet but contain two different letters - Please enter a different second letter" << endl;
		cin >> secondletter;
	}

	cout << "Please enter a word using your alphabet." << endl;
	cin >> word;

//-------------------------------------------------------------------

	state = 0;									//Starts at state 0
	for (int j = 0; j < word.length(); ++j)		//Starts loop to go through string one character at a time
	{
		ch = word[j];							//Sets ch as the current character in the loop

//This section handles the y-axis for the DFA, allowing any alphabet of the user's choice
//This will allow me to expand my alphabets in the future

		if (word[j] == firstletter)
		{
			ch = 0;
		}
		else if (word[j] == secondletter)
		{
			ch = 1;
		}
		else
		{
			InvalidCharacter();
		}

//-------------------------------------------------------------------

		cout << "Array: x = " << state << " y = " << ch << endl; //Displays current array axes
		state = COMPL[state][ch];
		cout << "New State: " << state << endl << endl;			//Displays new state

	}

	for (i = 0; i < CACCEPTS; i++)
	{
		if (COMPACCEPTS[i] == state)
		{
			multaccept = multaccept + 1;
		}
	}

//CACCEPTS array accepts three values, 0, 1, and 3.  If the state equals any of them, that means the program accepts the input and outputs "Accepted"
//Because it is testing against each element in the COMPACCEPTS array and it accepts if a single one accepts, multaccept is a counter
//If COMPACCEPTS[i] never matches state, then the counter never increments and it comes up "Not Accepted"

	if (multaccept > 0)
	{

		cout << "Accepted" << endl << endl;

	}
	else
	{

		cout << "Not Accepted" << endl << endl;

	}
	
}

//Invalid Character Function

void InvalidCharacter()
{
	cout << "You have entered a character not in your alphabet" << endl;
	main();
}
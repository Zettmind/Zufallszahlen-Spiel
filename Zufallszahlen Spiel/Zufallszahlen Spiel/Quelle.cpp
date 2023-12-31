#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

const int maxNumber = 10;

char Menu()
{
	char input = ' ';
	cout << "\n MENU\n\ (P)lay\n (Q)uit\n\n";
	cout << "Input: ";
	cin >> input;
	system("cls");
	return input;
}

int GetUserGuess()
{
	int guess = 0;
	cout << "Your guess: ";
	cin >> guess;
	return guess;
}

bool ValidateUserGuess(int guess, int rightResult)
{
	if (guess == rightResult)
	{
		cout << "NICE!!!\nU guessed it right! :D\nThe searched number was: " << rightResult << endl;
			return true;
	}

	else if (guess < rightResult)
	{
		cout << "The Searched Number is higher than your guess\n";
		return false;
	}

	else if (guess > rightResult)
	{
		cout << "The Searched Number is lower than your guess\n";
		return false;
	}

	else
	{
		cout << "Invalid Input: '" << guess << "'\n";
		return false;
	}
}

void RunGame()
{
	int RandomNumber = rand() % maxNumber + 1;
	int guess = 0;
	int tries = 0;
	cout << "The searched number between 1 and " << maxNumber << " (both inclusive)\n";
	do
	{
		guess = GetUserGuess();
		tries++;
	} while (!ValidateUserGuess(guess, RandomNumber));
	cout << "You needed " << tries << " tries\n";
}

void RunMenu()
{
	while (true)
	{
		char input = Menu();
		if (input == 'P' || input == 'p')
			RunGame();
		else if (input == 'Q' || input == 'q')
			break;
		else
			cout << "Input '" << input << "' not recognized please try again:\n";
	}
}

int main()
{
	srand(time(NULL));
	RunMenu();

	//system("Pause");
	return 0;
}
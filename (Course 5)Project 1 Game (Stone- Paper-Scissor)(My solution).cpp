#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
//Project 1 game 

//My project

enum enGameChoices{Paper = 1, Stone = 2, Scissor = 3};

struct FinalResult {
	short Player1WonTimes ;
	short ComputerWonTimes ;
	short Draw ;
};

struct GameDetails {
	short Rounds = 0;
	short PlayerChoice = 0;
	short ComputerChoice = 0;

	FinalResult FinalResult1;
};

int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 1 || Number > 10);

	return Number;
}

int ReadNumberInRange(int From, int To, string Message)
{
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < From || Number > To);

	return Number;
}

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;

	return RandNumber;
}

string CheckChoice(short Input)
{
	switch (Input)
	{
	case enGameChoices::Paper:
		return "Paper";
		
	case enGameChoices::Stone:
		return "Stone";

	default:
		return "Scissor";
	}
}

string CheckWhoWonTheRound(GameDetails Game1Details)
{
	if (Game1Details.PlayerChoice == Game1Details.ComputerChoice)
	{
		return "[No Winner]";
	}
	else if (Game1Details.PlayerChoice == enGameChoices::Paper && Game1Details.ComputerChoice == enGameChoices::Stone)
	{

		return "[Player Winner]";
	}
	else if (Game1Details.PlayerChoice == enGameChoices::Stone && Game1Details.ComputerChoice == enGameChoices::Scissor)
	{

		return "[Player Winner]";
	}
	else if (Game1Details.PlayerChoice == enGameChoices::Scissor && Game1Details.ComputerChoice == enGameChoices::Paper)
	{

		return "[Player Winner]";
	}
	else if (Game1Details.PlayerChoice == enGameChoices::Paper && Game1Details.ComputerChoice == enGameChoices::Scissor)
	{

		return "[Computer Winner]";
	}
	else if (Game1Details.PlayerChoice == enGameChoices::Stone && Game1Details.ComputerChoice == enGameChoices::Paper)
	{

		return "[Computer Winner]";
	}
	else if (Game1Details.PlayerChoice == enGameChoices::Scissor && Game1Details.ComputerChoice == enGameChoices::Stone)
	{

		return "[Computer Winner]";
	}
}

string CheckWhoWonInFinal(GameDetails Game1Details)
{
	if (Game1Details.FinalResult1.Player1WonTimes == Game1Details.FinalResult1.ComputerWonTimes)
	{
		return "No winner";
	}
	else if (Game1Details.FinalResult1.Player1WonTimes > Game1Details.FinalResult1.ComputerWonTimes)
	{
		return "Player";
	}
	else
	{
		return "Computer";
	}
}

void ShowFinalResult(GameDetails Game1Details)
{
	cout << "\t\t______________________________________________________\n\n\t\t";
	cout << "\t\t  +++ Game over +++\n\n";
	cout << "\t\t_____________________________________________________\n\n";
	cout << "\t\t____________________[Game Result]____________________\n\n";
	cout << "\t\tGame Rounds        : " << Game1Details.Rounds << endl;
	cout << "\t\tPlayer Won times   : " << Game1Details.FinalResult1.Player1WonTimes << endl;
	cout << "\t\tComputer won times : " << Game1Details.FinalResult1.ComputerWonTimes << endl;
	cout << "\t\tDraw times         : " << Game1Details.FinalResult1.Draw << endl;
	cout << "\t\tFinal winner       : " << CheckWhoWonInFinal(Game1Details) << endl;
	cout << "\t\t_____________________________________________________\n";
}

void ShowEachRoundResult(int EachRound, GameDetails &Game1Details)
{
	cout << "______________Round [" << EachRound << "] ______________\n\n";

	cout << "Player1 choice: " << CheckChoice(Game1Details.PlayerChoice) << endl;
	cout << "Computer choice: " << CheckChoice(Game1Details.ComputerChoice) << endl;
	cout << "Round winner: " << CheckWhoWonTheRound(Game1Details) << endl;
	cout << "______________________________________\n";

	if (CheckWhoWonTheRound(Game1Details) == "[No Winner]")
	{
		Game1Details.FinalResult1.Draw++;
		system("color 60");
	}
	else if (CheckWhoWonTheRound(Game1Details) == "[Player Winner]")
	{
		Game1Details.FinalResult1.Player1WonTimes++;
		system("color 20");
	}
	else
	{
		Game1Details.FinalResult1.ComputerWonTimes++;
		cout << "\a";
		system("color 40");
	}
}

bool IsPlayerWantPlayAgain()
{
	char Answer;
	char OtherAnswer = 0;
	do
	{
		cout << "\n\t\tDo you want to play again? Y/N? " ;
		cin >> Answer;
		cout << "\n\n\n";
	
		if (Answer == 89 || Answer == 121)
		{
			return true;
		}
		else if (Answer == 78 || Answer == 110)
		{
			return false;
		}
		else
		{
			OtherAnswer = -1;
		}
	} while (OtherAnswer == -1);
}

void StartGame()
{
	GameDetails Game1Details;
	do
	{
		Game1Details.FinalResult1.Player1WonTimes = 0;
		Game1Details.FinalResult1.ComputerWonTimes = 0;
		Game1Details.FinalResult1.Draw = 0;

		system("cls");
		system("color 07");

		Game1Details.Rounds = ReadPositiveNumber("How many rounds 1 to 10");

		for (int i = 1; i <= Game1Details.Rounds; i++)
		{
			cout << "\nRound [" << i << "] begins:\n\n";
			cout << "Your choice: [1]:Paper, [2]:Stone, [3]:Scissors ? \n";
			Game1Details.PlayerChoice = ReadNumberInRange(1, 3, "Please enter number between 1 and 3 ");
			cout << endl;
			Game1Details.ComputerChoice = RandomNumber(1, 3);

			ShowEachRoundResult(i, Game1Details);
		}
		ShowFinalResult(Game1Details);
	} while (IsPlayerWantPlayAgain());
}

int main()
{
	srand(unsigned(time(NULL)));

	StartGame();

	
	return 0;
}







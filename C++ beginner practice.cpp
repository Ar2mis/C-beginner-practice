
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int playGuessingGame(int maxRange)
{
	int secretNumber = (rand() % maxRange) + 1;
	int guess = 0;
	int tries = 0;
	cout << "I have a secret number between 1 and " << maxRange << "!" << "Guess what it is : ";
	while (guess != secretNumber)
	{
		cin >> guess; tries++;
		if (guess == secretNumber)
		{
			cout << "Bingo! " << endl;
		}
		else if (guess < secretNumber)
		{
			cout << "Too low! " << endl;
		}
		else if (guess > secretNumber)
		{
			cout << "Too High " << endl;
		}
	}
	cout << "You won in " << tries << " tries!" << endl;
	return tries;
}

	int main()
	{
		srand(time(0));
		vector<int> scoreHistory;
		char keepPlaying;
		double totalTries = 0;
		do {
			int choice;
			int maxRange;
			cout << "Select Difficulty (1-3)";
			cin >> choice;
			switch (choice)
			{
			case 1:
				maxRange = 10;
				cout << "Mode :Easy " << endl;
				break;
			case 2:
				maxRange = 100;
				cout << "Mode :Hard " << endl;
				break;
			case 3:
				maxRange = 1000;
				cout << "Mode :Legend " << endl;
				break;
			default:
				maxRange = 10;
				cout << "Invalid! Defaulting to Easy. " << endl;
				break;
			}
				int currentScore = playGuessingGame(maxRange);
				scoreHistory.push_back(currentScore);
				totalTries += currentScore;

				if (scoreHistory.size() > 0)
				{
					cout << "Current Average Tries: " << totalTries / scoreHistory.size();
				}
				 cout << "Do you want to play again? (y/n) ";
			cin >> keepPlaying;
		} while (keepPlaying == 'y' || keepPlaying == 'Y');
		cout << "Total games played: " << scoreHistory.size();
		cout << "Thanks for playing! Bye! ";

		return 0;
	}

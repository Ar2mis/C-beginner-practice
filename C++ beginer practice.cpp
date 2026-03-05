
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void playGuessingGame(int maxRange)
{
	int secretNumber = (rand() % maxRange) + 1;
	int guess = 0;
	cout << "I have a secret number between 1 and " << maxRange << "!" << "Guess what it is : ";
	int tries = 0;
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
}

int main()
{ 
	srand(time(0));
	char keepPlaying;
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
		playGuessingGame(maxRange);
		cout << "Do you want to play again? (y/n) ";
		cin >> keepPlaying;
	} while (keepPlaying == 'y' || keepPlaying == 'Y');
	cout << "Thanks for playing! Bye! ";
		return 0;
		
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单



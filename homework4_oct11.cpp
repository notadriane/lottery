//----------------------------------------------------------
// Name: Adriane Delicana
// E-mail Address: add5509@psu.edu
// Class: CMPSC 121 Section 
// Project #4
// Due Date: Oct. 11
// Brief Project Description: This program generates a random 3-digit lottery number
//							  and awards the user based on the accuracy of their guess.
//----------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	//  Variables
	const int MIN_VALUE = 0,
		      MAX_VALUE = 999;

	int winningNumber, guess,
		digit1, digit2, digit3,  //  each digit of the user input
		win_digit1, win_digit2, win_digit3,  //  each digit of the lottery number
		checker = 0,  //  counter used to track number of digits that match
		win;  // sets amount of money won

	cout << " Welcome! "
		<< endl << endl;
	cout << "Try your chances at the lottery!"
		<< endl << endl;

	//  Generates 3-digit number between 0 and 999 with rand function for the winning number
	int seed = static_cast <int> (time(0));
	srand(seed);
	winningNumber = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
	cout << setw(3) << setfill('0');

	//  Ask user to enter 3-digit number
	cout << "Please enter a 3-digit number e.g. 001, 059, 425: ";

	//  Store user answer
	cin >> guess;

	//  Calculations to separate each digit
	win_digit3 = winningNumber % 10;
	win_digit2 = winningNumber / 10 % 10;
	win_digit1 = winningNumber / 100 % 10;

	digit3 = guess % 10;
	digit2 = guess / 10 % 10;
	digit1 = guess / 100 % 10;

	//  Comparison statements to check each digit of user input against each digit of lottery number
	if (digit1 == win_digit1 || digit1 == win_digit2 || digit1 == win_digit3) checker++;
	if (digit2 == win_digit1 || digit2 == win_digit2 || digit2 == win_digit3) checker++;
	if (digit3 == win_digit1 || digit3 == win_digit2 || digit3 == win_digit3) checker++;

	// if 3 digits match exactly, user wins 10000, else user matches in different order and wins 3000
	if (checker == 3)
	{
		if (digit1 == win_digit1 && digit2 == win_digit2 && digit3 == win_digit3)
		{
			win = 10000;
		}
		else win = 3000;
	}

	// if player matches 1 or 2 digits, player wins 1000
	else if (checker == 1 || checker == 2)
	{
		win = 1000;
	}

	//  if player doesn't match any digits, player wins nothing
	else
		win = 0;

	//  if player wins, winning number and player's guess is displayed along with prize amount.
		if (win) cout << "\nThe winning number is " << setw(3) << setfill('0') << winningNumber << " and you guessed " 
			<< setw(3) << setfill('0') << guess << ".\n\nYou win $" << win << "!\n";

	//  if player doesn't win, winning number and player guess is displayed with a "sorry" message
		else cout << "\nThe winning number is " << setw(3) << setfill('0') << winningNumber << " and you guessed " 
			<< setw(3) << setfill('0') << guess << ".\n\nSorry, you didn't win! Try again next time.\n";

		return 0;
}
#include <iostream>
#include <string>
#include "fBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instaniate a new game

// the entry point for the application
int main()
{
	std::cout << BCGame.
		() ;
	bool bPlayAgain(false);
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	
	return 0;
}


void PrintIntro()
{
	//introduce the game
	int32 HiddenWordLength = BCGame.GetHiddenWordLength();

	// TODO explain the rules of the game and what the goal of the game is
	// TODO make some art 

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << HiddenWordLength;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop for the numbers of times asking guesses
	
	for (int32 count = 0; count < MaxTries; count++)
	{
		FText Guess = GetGuess(); 

		EGuessStatus status = BCGame.CheckGuessValidity(Guess);
		

		//Submit valid guess for game 
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		
		//Print Bulls and cows 
		std::cout << " Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows;
		std::cout << std::endl;
	}

	// TODO summerise the game 

}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get a guess from the user
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again ? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');

}




#include "FBullCowGame.h"
#include <iostream>

using int32 = int;




FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	
	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	
	return ;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; //return error
	}
	else if (false)// if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;//return error
	}
	else if (Guess.length() != GetHiddenWordLength())// if the guesse length is wrong
	{
		return EGuessStatus::Wrong_Length;//return error
	}
	else // otherwise 
	{
		return EGuessStatus::OK; // return OK
	}
}

//recieves a VALID guess, increments turn, returns count 
FBullCowCount FBullCowGame::SubmitGuess(FString Guess )
{
	//incrimetn the turn number
	MyCurrentTry++;

	// set up a return value 
	FBullCowCount BullCowCount;
	
	// loop trough all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();

	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		// compare letters against in the hidden word 
		for (int32 MGChar = 0; MGChar < GuessLength; MGChar++)
		{
			// if they match then
			if (MyHiddenWord[MHWChar] == Guess[MGChar])
			{
				// if they are in the same plac
				if (MHWChar == MGChar)
				{
					BullCowCount.Bulls++;// incriment bulls
				}
				else
				{
					BullCowCount.Cows++;//incriment cows
				}

			}		
				
		}
	}


	return BullCowCount;
}
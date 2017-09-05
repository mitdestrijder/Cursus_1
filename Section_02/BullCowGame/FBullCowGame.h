#pragma once
#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase

};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); // TODO make a more rich return value 
	// provide a method for counting bulls and cows, and turns 
	FBullCowCount SubmitGuess(FString);

private:
	// see constructor for initializtation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};

//FBullCowGame::FBullCowGame()
//{
//}

//FBullCowGame::~FBullCowGame()
//{
//}
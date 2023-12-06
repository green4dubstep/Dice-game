// Add all the includes for the required header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"

int main()
{
	// Initialize the srand() to start the random generator
	srand(time(0));

	int Rounds;
	int numround;
	// Initialize the player-1 and player-2 points to 0
	int p1Points = 0, p2Points = 0;
	int currentPlayer = (getRandomNumber(1, 2) == 1) ? 1 : 2;
	// Initialize all other required variables
	// Ask the user for the number of rounds to run the game
	printf("Enter the number of Rounds you want to play: ");
	scanf("%d", &Rounds);
	printf("Player 1: 0\nPlayer 2: 0\n");

	// Call printPlayerPoints() function to print the initial player points which will be 0
	// Set up the loop to go through all the rounds one at a time
	for (numround = 1; numround <= Rounds; numround++)
	{
		printf("Round %d\n", numround);
		printf("--------\n");
		printf("Current Player: %d\n", currentPlayer);
		// Call the corresponding functions to get the information for this round - type, dice, points
		ROUNDTYPE roundType = getRoundType();
		int dice = getRandomNumber(1, 6);
		int points = getRoundPoints(roundType);
		// Call printRoundInfo() to print the round information
		printRoundInfo(roundType, dice, points);

		// MAIN GAME LOGIC
		// Write code here to get the main game logic using branches
		// Success: Player-1 (odd player) is the current player and the dice rolled is odd
		// OR Player-2 (even player) is the current player and the dice rolled is even.
		// Current player gains the points, based on the type of the round (see above). The current player’s turn continues in the next round.
		if ((currentPlayer == 1 && dice % 2 != 0) || (currentPlayer == 2 && dice % 2 == 0))
		{
			if (roundType == BONUS)
			{
				p1Points += 200;
			}
			else if (roundType == DOUBLE)
			{
				p1Points += (points * 2);
			}
			else
			{
				p1Points += points;
			}
		}
		// Failure: Player-1 (odd player) is the current player and the dice rolled is even
		// OR Player-2 (even player) is the current player and the dice rolled is odd.
		// Current player incurs penalty of the same number of points, based on the type of the round (see above). In the next round, the current player is changed to the other player.
		else
		{
			if (roundType == BONUS)
			{
				p1Points -= 200;
			}
			else if (roundType == DOUBLE)
			{
				p1Points -= (points * 2);
			}
			else
			{
				p1Points -= points;
			}
			currentPlayer = (currentPlayer == 1) ? 2 : 1;
		}
		printf("Rounds played %d\n", numround);
		// Call printPlayerPoints() to print the player information at the end of the round
		printPlayerPoints(p1Points, p2Points);
	}
	printf("\nGAME OVER!!\n");

	// Compare the final points for player-1 and player-2
	// Print the winner as the one with higher points
	if (p1Points > p2Points)
	{
		printf("Player 1 wins!\n");
	}
	else if (p2Points > p1Points)
	{
		printf("player 2 wins!\n");
	}
	else
	{
		printf("It's a Tie!\n");
	}
	// Return from the main() function to end the program successfully
	return 0;
}

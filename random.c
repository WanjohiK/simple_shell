#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point of the program.
 *
 * Description: This is a simple number guessing program.
 * the Betty checks.
 *
 * Return: 0 on success.
 */

int main(void)
{
	int numberToGuess, userGuess;
	int attempts = 0;

	/* Seed the random number generator with the current time.*/
	srand(time(NULL));

	/* Generate a random number between 1 and 100. */

	numberToGuess = rand() % 100 + 1;

	printf("Welcome to the Number Guessing Game!\n");
	printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

	do {
		printf("Enter your guess: ");
		scanf("%d", &userGuess);
		attempts++;

		if (userGuess < numberToGuess)
		{
			printf("Too low! Try again.\n");
		}
		else if (userGuess > numberToGuess)
		{
			printf("Too high! Try again.\n");
		}
		else
		{
			printf("Congratulations! You guessed the number %d in %d attempts.\n"
				, numberToGuess, attempts);
		}
	} while (userGuess != numberToGuess);



	return (0);
}

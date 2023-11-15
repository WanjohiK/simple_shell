#include "shell.h"

/**
 * _strToNum - Converts a string to an integer.
 * @str: String to be converted.
 *
 * Description: If the first character is '+', move to the next character.
 * Loop through the string while the flag is 0.
 * If the first character is '-', return -1
 * because we don't want negative values.
 * If the current character is a digit, convert it into a digit,
 * store it into the result.
 * If the next character is a letter, break out of the loop.
 * If the result is greater than INT_MAX or is negative,
 * return -1 for an error.
 * Else, return the result.
 *
 * Return: (int) The int converted from the string.
 */
long int _strToNum(char *str)
{
	int index = 0, length = _strlen(str), isNegative = 0, digit;
	long int result = 0;

	if (str[index] == '+')
	{
		index++;
	}

	while (index < length && !isNegative)
	{
		if (str[index] == '-')
		{
			return (-1);
		}

		if (str[index] >= '0' && str[index] <= '9')
		{
			digit = str[index] - '0';
			result = result * 10 + digit;
			isNegative = 1;
			if (str[index + 1] < '0' || str[index + 1] > '9')
			{
				break;
			}
			isNegative = 0;
		}
		index++;
	}

	if (!isNegative)
	{
		return (0);
	}

	if (result > INT_MAX || result < 0)
	{
		return (-1);
	}

	return (result);
}

/**
 * _numToStrBase - Converts number to a string representation in a given base.
 * @num: Input number.
 * @base: Input base.
 *
 * Description: Create a static buffer of 50 chars
 * and a static string of digits.
 * Go from the end of the buffer and loop until num reaches 0.
 * The current digit is the member of digits at index num % base.
 * Divide num by base.
 *
 * Return: (char *) Result string.
 */
char *_numToStrBase(int num, int base)
{
	static char *digits = "0123456789";
	static char buffer[50];
	char *resultPointer = NULL;

	resultPointer = &buffer[49];
	*resultPointer = '\0';
	do {
		*--resultPointer = digits[num % base];
		num /= base;
	} while (num != 0);

	return (resultPointer);
}


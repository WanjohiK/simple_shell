#include "custom_shell.h"

/**
 * copyToken - Copies characters from source to destination until delimiter is encountered
 * @destination: The destination buffer to copy characters to
 * @source: The source buffer to copy characters from
 * @delimiter: The delimiter character that indicates the end of the token
 * Returns: void
 */
static void copyToken(char *destination, char *source, char delimiter) {
	int j = 0;
	while (*source != delimiter && *source && *source != '\n') {
		destination[j] = *source;
		source++;
		j++;
	}
	destination[j] = '\0';
}

/**
 * getNextToken - Moves the inputString pointer to the next non-delimiter character
 * @inputString: The input string to traverse
 * @delimiter: The delimiter character to skip
 * Returns: A pointer to the next non-delimiter character in the inputString
 */
static char *getNextToken(char *inputString, char delimiter) {
	while (*inputString == delimiter)
		inputString++;

	return (inputString);
}

/**
 * allocateAndCopyToken - Allocates memory for a token and copies it from source to destination
 * @tokens: A pointer to the array of tokens
 * @index: The index where the token should be stored in the array
 * @copy: The source buffer containing the token to be copied
 * @length: The length of the token
 * Returns: void
 */
static void allocateAndCopyToken(char ***tokens, int index, char *copy, int length) {
	(*tokens)[index] = malloc(sizeof(char) * (length + 1));
	if (!(*tokens)[index]) {
		// Handle allocation failure
		exit(EXIT_FAILURE);
	}
	copyToken((*tokens)[index], copy, '\0');
}

/**
 * customTokenizer - Converts a string into an array of tokens
 * @inputString: The string to tokenize
 * @delimiter: The delimiter character between tokens
 * Returns: A pointer to the array of tokens on success, or NULL on failure
 */
char **customTokenizer(char *inputString, char delimiter) {
	char *copy = NULL, **tokens = NULL;
	int i = 0, j = 0, length = 0, totalTokens = 0;

	if (inputString == NULL || *inputString == '\0')
		return (NULL);

	totalTokens = countTokens(inputString, delimiter);
	if (totalTokens == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (totalTokens + 1));
	if (tokens == NULL) {
		// Handle allocation failure
		exit(EXIT_FAILURE);
	}

	while (*inputString && i < totalTokens) {
		inputString = getNextToken(inputString, delimiter);

		copy = inputString;
		while (*inputString != delimiter && *inputString) {
			length++;
			inputString++;
		}

		allocateAndCopyToken(&tokens, i, copy, length);

		i++;
		j = 0;
		length = 0;
	}

	tokens[i] = NULL;
	return (tokens);
}


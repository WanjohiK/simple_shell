#include "shell.h"

/**
 * convert_arr_to_list - Transform the environment variable into a linked list.
 * @head: Double pointer to the env_t list to fill.
 * @env_array: Array of strings containing the environment variables.
 *
 * Description: Deallocate the list if it already exists.
 * Iterate through the array and append a node for each string.
 *
 * Return: Number of nodes in the list.
 */
int convert_arr_to_list(env_t **head, char **env_array)
{
	int index = 0;

	if (head)
		release_list(head);

	while (env_array[index])
	{
		append_node_end(head, env_array[index]);
		index++;
	}
	return (index);
}

/**
 * convert_list_to_arr - Transform a linked list into an array of strings.
 * @head: Pointer to the env_t list.
 *
 * Description: If the list is non-existent, return NULL.
 * Allocate memory for the array and verify its allocation.
 * Traverse the list, allocate memory for each string.
 * Populate each string with the content from the node.
 * Set the last element of the array to NULL.
 * Return the array.
 *
 * Return: Address of the array or NULL if allocation failed.
 */
char **convert_list_to_arr(env_t *head)
{
	env_t *temp_node = head;
	char **str_array = NULL, *string = NULL;
	size_t size = 0;
	int i;

	size = determine_list_length(head);

	if (!head || !size)
		return (NULL);

	str_array = malloc(sizeof(char *) * (size + 1));
	if (!str_array)
		return (NULL);

	for (i = 0; temp_node; temp_node = temp_node->next, i++)
	{
		string = malloc(sizeof(char) * (_strlen(temp_node->str) + 1));
		if (!string)
		{
			release_everything(str_array);
			return (NULL);
		}
		string = _strcpy(string, temp_node->str);
		str_array[i] = string;
	}
	str_array[i] = NULL;

	return (str_array);
}

/**
 * display_list - Print all the nodes of a linked list.
 * @node: Pointer to the env_t list to print.
 *
 * Return: The number of nodes printed.
 */
size_t display_list(env_t *node)
{
	size_t count = 0;

	while (node)
	{
		if (!node->str)
			_puts("(nil)");
		else
			_puts(node->str);
		node = node->next;
		count++;
	}

	return (count);
}

/**
 * eliminate_list - Free all the nodes of a linked list.
 * @head: Env_t list to be freed.
 */
void eliminate_list(env_t **head)
{
	env_t *temp = NULL;

	if (head == NULL)
		return;

	while (*head)
	{
		temp = (*head)->next;
		free((*head)->str);
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

/**
 * determine_list_length - Calculate the number of elements in a linked list.
 * @node: Pointer to the env_t list.
 *
 * Return: Number of elements in the list.
 */
size_t determine_list_length(const env_t *node)
{
	size_t count = 0;

	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}


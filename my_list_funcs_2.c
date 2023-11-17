#include "shell.h"

/**
 * arr_to_lists - transforms the 
 * @head: double pointer to the env_t list to fill
 * @env: array of strings conta
 *
 * Description: Free the list if it exists
 *
 * Return: Number of nodes in the list
 */
int arr_to_lists(env_t **head, char **env)
{
	int j = 0;

	if (head)
		free_list(head);

	while (env[j])
	{
		add_node_end(head, env[j]);
		j++;
	}
	return (j);
}

/**
 * list_to_arrs - transforms a 
 * @head: pointer env_t 
 *
 * Description: If the list doesn't e
 *
 * Return: address of the array, or NULL if it failed
 */
char **list_to_arrs(env_t *head)
{
	env_t *temp = head;
	char **arr = NULL, *s = NULL;
	size_t size = 0;
	int j;

	size = list_lens(head);

	if (!head || !size)
		return (NULL);

	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);

	for (j = 0; temp; temp = temp->next, i++)
	{
		s = malloc(sizeof(char) * (_strlen(temp->str) + 1));
		if (!s)
		{
			free_everything(arr);
			return (NULL);
		}
		s = _strcpy(s, temp->str);
		arr[j] = s;
	}
	arr[j] = NULL;

	return (arr);
}

/**
 * print_lists - prints all the nodes of a linked list
 * @h: pointer to the list_t list to print
 *
 * Return: the number of nodes printed
 */
size_t print_lists(env_t *h)
{
	size_t s = 0;

	while (h)
	{
		if (!h->str)
			_puts("(nil)");
		else
			_puts(h->str);
		h = h->next;
		s++;
	}

	return (s);
}

/**
 * free_lists - frees all the nodes of a linked list
 * @head: list_t list to be freed
 */
void free_lists(env_t **head)
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
 * list_lens - returns the number
 * @h: pointer to
 *
 * Return: number of elements in h
 */
size_t list_lens(const env_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}

#include "shell.h"

/**
 * add_node_end - adds a new node at the end of a linked list
 * @head: double pointer to the env_t list
 * @str: string to put in the new node
 *
 * Description: allocate memory for a node
 * Return: address of the new element
 */
env_t *add_node_ends(env_t **head, char *str)
{
	env_t *new = NULL;
	env_t *temp = *head;

	new = malloc(sizeof(env_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;

	return (new);
}

/**
 * delete_node_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Description: If the list is empty
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_node_at_indexs(env_t **head, unsigned int index)
{
	env_t *temp = *head;
	env_t *current = NULL;
	unsigned int j = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp->str);
		free(temp);
		return (1);
	}

	while (j < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		j++;
	}

	current = temp->next;
	temp->next = current->next;
	free(current->str);
	free(current);

	return (1);
}

/**
 * add_node_at_indexs - adds a new node
 * @head: double pointer to the en_t list
 * @str: string to put in the new node
 * @idx: index where to insert the node
 *
 * Description: Allocate memory for a new node
 * 
 * Return: 0 on success, -1 on failure
 */
int add_node_at_indexs(env_t **head, char *str, int idx)
{
	int j;
	env_t *new = NULL;
	env_t *temp = *head;

	new = malloc(sizeof(env_t));
	if (!new || !head)
		return (-1);

	new->str = _strdup(str);
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (0);
	}

	for (j = 0; temp && j < idx; j++)
	{
		if (j == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (0);
		}
		else
			temp = temp->next;
	}

	return (-1);
}

/**
 * find_index_lists - finds the index
 * @head: pointer to the env_t list
 * @name: string of the node to find
 *
 * Description: Traverse the list,
 *
 * Return: index of the node, or 0 if the node is not found
 */
int find_index_lists(env_t *head, char *name)
{
	int index = 0;
	int k = 0;

	while (head)
	{
		k = _strncmp(head->str, name, _strlen(name));
		if (k == 0)
			return (index);
		index++;
		head = head->next;
	}

	return (0);
}

/*
   * File_name: line_list.c file
   * Functions: add_line_node_end, free_line_list
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * add_line_node_end - adds a command line at the
  *                     end of a line_list.
  *
  * @head: The head of the linked list.
  *
  * @line: command line.
  *
  * Return: address of the head.
  */

line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));
	if (new == NULL)
		return (NULL);

	new->line = line;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{

		*head = new;

	}
	else
	{
		while (temp->next != NULL)

			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}


/**
  * free_line_list - frees a line_list
  *
  * @head: The head of the linked list.
  *
  * Return: no return.
  */

void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;

		while ((temp = curr) != NULL)
		{

			curr = curr->next;
			free(temp);

		}

		*head = NULL;

	}
}

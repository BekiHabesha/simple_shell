/*
   * File_name: vi rvar_list.c file
   * Functions: add_rvar_node, free_rvar_list
   * Created: 11th of November, 2023
   * Author: Bereket Dereje Mekonnen
   * GitHub repository: simple_shell
   * Project: 0x16. C - Simple Shell
   * Directory: simple_shell
   */

#include "shell.h"

/**
  * add_rvar_node - adds a variable at the end
  *                 of a r_var list.
  *
  * @head: The head of the linked list.
  *
  * @lvar: The length of the variable.
  *
  * @val: The value of the variable.
  *
  * @lval: The length of the value.
  *
  * Return: address of the head.
  */

r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

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
  * free_rvar_list - frees a r_var list
  *
  * @head: The head of the linked list.
  *
  * Return: no return.
  */

void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

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

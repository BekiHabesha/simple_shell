#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <stddef.h>


#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/**
  * struct data - struct that contains all
  *               relevant data on runtime
  * @av: argument vector
  *
  * @input: command line written by the user
  *
  * @args: tokens of the command line
  *
  * @status: last status of the shell
  *
  * @counter: lines counter
  *
  * @_environ: environment variable
  *
  * @pid: process ID of the shell
  */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;


/**
  * struct builtin_s - Builtin struct for command args.
  *
  * @name: The name of the command builtin i.e cd, exit, env
  *
  * @f: data type pointer function.
  */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/**
  * struct r_var_list - single linked list
  *
  * @len_var: length of the variable
  *
  * @val: value of the variable
  *
  * @len_val: length of the value
  *
  * @next: next node
  *
  * Description: single linked list to store variables
  */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;


/**
  * struct line_list_s - single linked list
  *
  * @line: command line
  *
  * @next: next node
  *
  * Description: single linked list to store command lines
  */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;


/**
  * struct sep_list_s - single linked list
  *
  * @separator: ; | &
  *
  * @next: next node
  *
  * Description: single linked list to store separators
  */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

sep_list *add_sep_node_end(sep_list **head, char sep);
line_list *add_line_node_end(line_list **head, char *line);
r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);


void aux_help(void);
void aux_help_cd(void);
void aux_help_env(void);
void get_sigint(int sig);
void rev_string(char *s);
void aux_help_exit(void);
void aux_help_alias(void);
void aux_help_setenv(void);
void aux_help_general(void);
void aux_help_unsetenv(void);
void cd_to(data_shell *datash);
void cd_dot(data_shell *datash);
void free_rvar_list(r_var **head);
void cd_to_home(data_shell *datash);
void shell_loop(data_shell *datash);
void free_sep_list(sep_list **head);
void cd_previous(data_shell *datash);
void free_line_list(line_list **head);
void check_env(r_var **h, char *in, data_shell *data);
void set_env(char *name, char *value, data_shell *datash);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);


int _atoi(char *s);
int get_len(int n);
int _strlen(const char *s);
int _isdigit(const char *s);
int _env(data_shell *datash);
int is_cdir(char *path, int *i);
int _setenv(data_shell *datash);
int _strcmp(char *s1, char *s2);
int get_help(data_shell *datash);
int cmd_exec(data_shell *datash);
int _unsetenv(data_shell *datash);
int exec_line(data_shell *datash);
int cd_shell(data_shell *datash);
int exit_shell(data_shell *datash);
int _strspn(char *s, char *accept);
int first_char(char *input, int *i);
int is_executable(data_shell *datash);
int repeated_char(char *input, int i);
int get_error(data_shell *datash, int eval);
int cmp_chars(char str[], const char *delim);
int error_sep_op(char *input, int i, char last);
int (*get_builtin(char *cmd))(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int split_commands(data_shell *datash, char *input);
int check_syntax_error(data_shell *datash, char *input);
int check_vars(r_var **h, char *in, char *st, data_shell *data);


char *aux_itoa(int n);
extern char **environ;
char *read_line(int *i_eof);
char *_strdup(const char *s);
char **split_line(char *input);
char *_strchr(char *s, char c);
char *error_syntax(char **args);
char *without_comment(char *in);
char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_permission(char **args);
char *_strcpy(char *dest, char *src);
char *error_get_cd(data_shell *datash);
char *swap_char(char *input, int bool);
char *copy_info(char *name, char *value);
char *_which(char *cmd, char **_environ);
char *error_path_126(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);
char *_strcat(char *dest, const char *src);
char *_strtok(char str[], const char *delim);
char *rep_var(char *input, data_shell *datash);
char *_getenv(const char *name, char **_environ);
char *strcat_cd(data_shell *, char *, char *, char *);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

#endif

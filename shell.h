#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#define BUFF_SIZE 1024
#define PROMPT "$ "
#define EINVAL "Invalid argument"
#define ENOMEM "Out of memory"
#define ERROR "Error"
#define WRONG "Something went wrong"
#define END "exit"

/**
 * struct built_in - list of builtins
 * @bi: The specifier
 * @f: The function associated with printing
 */
typedef struct built_in
{
	char *bi;
	int (*f)();
} builtin_t;
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for ALX project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;


extern char **environ;


size_t list_len(list_t *h);
list_t *add_node(list_t **head, char *str);
list_t *add_node_end(list_t **head, char *str);
void free_list(list_t *head);
list_t *get_node(list_t **head, char *str);

int _putchar(char c);
void _strprint(char *str);
void print_array(char **array);
size_t print_list(list_t *h);

int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);


int _strcmp(char *s1, char *s2);
char *_strchr(char *str, char c);
int len_to_char(char *str, char c);
int _atoi(char *s);


int count_words(char *str, char delim);
int _wrdlen(char *s, char delim);
char **strtow(char *str, char delim);

int arr_size(char **arr);
list_t *array_to_list(char **array);
char **list_to_array(list_t **head);
void free_array(char **array);

char *_getenv(char *name, list_t **env_head);
int _setenv(char *name, char *value, list_t **env_head);
int _unsetenv(char *name, list_t **env_head);
int delete_node(list_t **head, char *string);
char *var_str(char *name, char *value);

int _getline(char *input, int size);
int exit_shell(char **line_tok);
void clear_buffer(char *buffer);
char *mem_cpy(char *dest, char *src, int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

int cmd_line_loop(char *buffer, char *line, list_t **env_head);

char **path_dirs_array(list_t **env_head);
char *cmd_in_path(char *str, list_t **env_head);
int run_command(char **line, list_t **env_head);

int built_ins(char **input, list_t **env_head);
int exit_bi(char **line);
int print_env(char **line, list_t **env_head);
int set_env(char **line, list_t **env_head);
int unset_env(char **line, list_t **env_head);

void shell_interactive(void);
void shell_non_interactive(void);

#endif

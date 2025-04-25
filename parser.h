#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>  
#include <readline/history.h>
#include <unistd.h>

#define WHITESPACE " \t\n\r\f\v"

typedef struct s_command
{
    // char *cmd;
    char *args;
    struct s_command *next;
} t_command;


typedef enum  
{
   UNCLOSED_DOUBLE_Q,
   UNCLODES_SINFGLE_Q 
} e_syntaxe;

// tokenation

typedef struct s_token
{
	TYPE_TOKEN type;
	char *value;
}	t_token;

typedef enum
{
	INTPUT_RED,
	OUTPUT_RED,
	HEREDOC,
	APPEND,
	PIPE,
	WORD
} TYPE_TOKEN;



t_command *parse_line(char *line);
void free_commands(t_command *cmd);
void	parcer(int ac, char **av);
char	*ft_strtrim(char const *s1, char const *set);
bool    syntaxe_error(char *str);
#endif

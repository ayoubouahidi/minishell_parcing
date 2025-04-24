#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdbool.h>
#include <readline/readline.h>  
#include <readline/history.h>
#include <unistd.h>

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


t_command *parse_line(char *line);
void free_commands(t_command *cmd);
void	parcer(int ac, char **av);
char	*ft_strtrim(char const *s1, char const *set);
bool    syntaxe_error(char *str);
#endif

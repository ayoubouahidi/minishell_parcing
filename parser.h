#ifndef PARSER_H
#define PARSER_H

typedef struct s_command
{
    char *args;
    struct s_command *next;
} t_command;

t_command *parse_line(char *line);
void free_commands(t_command *cmd);
void	parcer(int ac, char **av);
char	*ft_strtrim(char const *s1, char const *set);

#endif

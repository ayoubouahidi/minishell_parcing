#include "../parser.h"
#include <stdio.h>
#include "libft/libft.h"


// static char **split_pipe(char *line) {
//     char **parts = malloc(100 * sizeof(char *));
//     int i = 0;
//     char *token = strtok(line, "|");
//     while (token) {
//         parts[i++] = strdup(token);
//         token = strtok(NULL, "|");
//     }
//     parts[i] = NULL;
//     return parts;
// }

// static char **split_args(char *cmd) {
//     char **args = malloc(100 * sizeof(char *));
//     int i = 0;
//     char *token = strtok(cmd, " \t\n");
//     while (token) {
//         args[i++] = strdup(token);
//         token = strtok(NULL, " \t\n");
//     }
//     args[i] = NULL;
//     return args;
// }

// static void handle_redirection(t_command *cmd) {
//     char **new_args = malloc(100 * sizeof(char *));
//     int j = 0;

//     for (int i = 0; cmd->args[i]; i++) {
//         if (strcmp(cmd->args[i], ">") == 0 && cmd->args[i + 1]) {
//             cmd->outfile = strdup(cmd->args[++i]);
//             cmd->append = 0;
//         } else if (strcmp(cmd->args[i], ">>") == 0 && cmd->args[i + 1]) {
//             cmd->outfile = strdup(cmd->args[++i]);
//             cmd->append = 1;
//         } else if (strcmp(cmd->args[i], "<") == 0 && cmd->args[i + 1]) {
//             cmd->infile = strdup(cmd->args[++i]);
//         } else {
//             new_args[j++] = strdup(cmd->args[i]);
//         }
//     }
//     new_args[j] = NULL;
//     free(cmd->args);
//     cmd->args = new_args;
// }

// t_command *parse_line(char *line) {
//     t_command *head = NULL;
//     t_command *prev = NULL;

//     char **pipes = split_pipe(line);

//     for (int i = 0; pipes[i]; i++) {
//         t_command *cmd = malloc(sizeof(t_command));
//         cmd->args = split_args(pipes[i]);
//         cmd->infile = NULL;
//         cmd->outfile = NULL;
//         cmd->append = 0;
//         cmd->next = NULL;

//         handle_redirection(cmd);

//         if (!head)
//             head = cmd;
//         else
//             prev->next = cmd;
//         prev = cmd;
//     }

//     // free pipes
//     for (int i = 0; pipes[i]; i++) free(pipes[i]);
//     free(pipes);

//     return head;
// }

// void free_commands(t_command *cmd) {
//     t_command *tmp;
//     while (cmd) {
//         tmp = cmd->next;
//         for (int i = 0; cmd->args && cmd->args[i]; i++) free(cmd->args[i]);
//         free(cmd->args);
//         free(cmd->infile);
//         free(cmd->outfile);
//         free(cmd);
//         cmd = tmp;
//     }
// }

void	printlist(t_command *head)
{
	t_command	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf(" node ==> %s\n", tmp->args);
		tmp = tmp->next;
	}
}

t_command	*ft_lstnew_cmd(void *content)
{
	t_command	*tmp;

	tmp = (t_command *)malloc(sizeof(t_command));
	if (!tmp)
		return (NULL);
	tmp->args = content;
	tmp->next = NULL;
	return (tmp);
}

void	ft_lstadd_back_cmd(t_command **lst, t_command *new)
{
	t_command	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

void	add_node(char *line, t_command **head)
{
	int i;
	t_command *cmd;
	int lenght_line;
	// char *line_pss; 
	cmd = NULL;
	head++;
	cmd++;

	i = 0;
	lenght_line = 0;
	// a refaire 
	while (line[i] != '\0')
	{
		
		// lenght_line++;// lenght_line++;
		// if (line[i] == ' ')
		// {
			// cmd = ft_lstnew_cmd(line_pss - lenght_line -1);
			// ft_lstadd_back_cmd(head, cmd);

			// printf("String => %s\n", line + i - lenght_line -1);
			// i++;
		// }
		// while (line[i] == ' ')
		// 	i++;
		// if (line[i] == '"')
		// {
		// 	while (line[i] != '"')
		// 		i++;
		// 	if (line[i] == '"')
		// 	{
		// 		cmd = ft_lstnew_cmd(line + (i - 1));
		// 		ft_lstadd_back_cmd(head, cmd);
		// 	}
		// 	else
		// 		write(1, "Error\n", 6);
		// }
		i++;
	}
}

void	parcer(int ac, char **av)
{
	char	*line;
	char	*trim;
	// int	i;
	t_command *head;

	head = NULL;
    // (head)->args = NULL;
	ac++;
	av++;
	while (1)
	{
		line = readline("minishell$ ");
		if(*line)
			add_history(line);
		trim = ft_strtrim(line, " ");
		printf("trim => %s\n", trim);
		add_node(trim, &head);
		printlist(head);
		
		// cmd->args = ft_split(trim, ' ');
		// if(!cmd->args)
		// {
		// 	printf("error\n");
		// 	exit(1);
		// }
		// ft_lstnew(cmd->args);
		// i = 0;
		// while ((head)->args[i])
		// {
		// 	printf("slpited => %s\n", (head)->args[i]);
		// 	i++;
		// }
		
	}
	
}
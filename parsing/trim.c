/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:47:40 by ayouahid          #+#    #+#             */
/*   Updated: 2025/04/18 17:47:42 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/parser.h"
#include "../../includes/utils.h"
#include "libft/libft.h"

static char	*mallocatehaha(char *newstr)
{
	newstr = malloc(sizeof(char) * 1);
	if (newstr != NULL)
		newstr[0] = '\0';
	return (newstr);
}

static int	mokana(char const	*s1,
		char const *set, size_t	cmpt, size_t	j)
{
	while (s1[j] != '\0' && ft_strchr(set, s1[j]))
	{
		j--;
		cmpt++;
	}
	return (cmpt);
}

static void	mallocatehaha2(char const *s1,
		char const *set, size_t *i, size_t *cmpt)
{
	while (s1[*i] != '\0' && ft_strchr(set, s1[*i]))
	{
		(*i)++;
		(*cmpt)++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	cmpt;
	char	*newstr;

	i = 0;
	cmpt = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
	{
		newstr = NULL;
		newstr = mallocatehaha(newstr);
		return (newstr);
	}
	mallocatehaha2(s1, set, &i, &cmpt);
	if (ft_strlen(s1) == cmpt)
		return (ft_strdup(""));
	j = ft_strlen(s1) - 1;
	cmpt = mokana(s1, set, cmpt, j);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) - cmpt + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s1 + i, (ft_strlen(s1) - cmpt + 1));
	return (newstr);
}

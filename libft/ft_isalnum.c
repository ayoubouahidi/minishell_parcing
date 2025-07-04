/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayouahid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:35:58 by ayouahid          #+#    #+#             */
/*   Updated: 2024/10/21 18:36:02 by ayouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int a)
{

	// if (ft_isalpha(a) || ft_isdigit(a))
	if (ft_isalpha(a) || ft_isdigit(a)  || (a >= '(' && a <= '.') || a == '{' || a == '}'|| a == '/' || a == '_')
		return (1);
	return (0);
}

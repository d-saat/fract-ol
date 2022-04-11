/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 18:32:52 by dsaat         #+#    #+#                 */
/*   Updated: 2022/04/09 17:06:28 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*ftoa(double nb)
{
	int		decimal;
	int		fractional;
	char	*str_d;
	char	*str_f;
	char	*str;

	decimal = (int)nb;
	str_d = ft_itoa(decimal);
	fractional = (nb - (double)decimal) * 100;
	if (fractional < 0)
	{
		fractional *= -1;
		if (decimal == 0)
		{
			str = ft_calloc(1, sizeof(char) + 1);
			if (!str)
				return (NULL);
			str[0] = '-';
			str_d = strjoin(str, str_d);
		}	
	}
	str_f = ft_itoa(fractional);
	str = ft_calloc(1, sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[0] = '.';
	str = strjoin(str_d, str);
	if (!str)
		return (NULL);
	str = strjoin(str, str_f);
	if (!str)
		return (NULL);
	return (str);
}

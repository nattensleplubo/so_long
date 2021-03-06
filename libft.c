/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:32:21 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/12 11:32:14 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solong.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	dest = malloc(count * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*dest;
	unsigned int	cpy;

	i = ((cpy = (n * (1 - (2 * (n < 0))))), (n < 0));
	while (cpy > 9)
		cpy = (i++, cpy / 10);
	dest = malloc(i + 2);
	if (!dest)
		return (NULL);
	dest[i + 1] = 0;
	dest[0] = ((cpy = (n * (1 - (2 *(n < 0))))), '-' + 3 * (n == 0));
	while (cpy > 0)
		cpy = ((dest[i--] = (cpy % 10) + '0'), cpy / 10);
	return (dest);
}

char	*ft_strjoinz(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * ft_strlen((char *) s1)
			+ ft_strlen((char *) s2) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

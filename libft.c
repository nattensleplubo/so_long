/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:32:21 by ngobert           #+#    #+#             */
/*   Updated: 2022/01/11 15:31:10 by ngobert          ###   ########.fr       */
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
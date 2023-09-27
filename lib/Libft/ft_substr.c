/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouwen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:18:45 by cbouwen           #+#    #+#             */
/*   Updated: 2023/04/13 15:33:47 by cbouwen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	size_t			sublen;
	unsigned int	strlen;

	strlen = ft_strlen(s);
	if (start > strlen)
	{
		ss = (char *)malloc(1 * sizeof(char));
		if (!ss)
			return (0);
		*ss = '\0';
		return (ss);
	}
	if (start + len > strlen)
		sublen = strlen - start;
	else
		sublen = len;
	ss = (char *)malloc((sublen + 1) * sizeof(char));
	if (!ss)
		return (0);
	ft_strlcpy(ss, s + start, sublen + 1);
	return (ss);
}

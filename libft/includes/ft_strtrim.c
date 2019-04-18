/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lravier <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 07:48:16 by lravier       #+#    #+#                 */
/*   Updated: 2019/03/28 10:34:16 by lravier       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_malloc_check(char *r)
{
	if (!r)
		return (NULL);
	return (r);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	j = (int)ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	j++;
	if (j < i)
	{
		r = ft_strnew(0);
		return (ft_malloc_check(r));
	}
	else
	{
		r = ft_strnew(j - i);
		if (!r)
			return (NULL);
		ft_strncpy(r, &s[i], j - i);
	}
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:21:24 by cfriot            #+#    #+#             */
/*   Updated: 2014/11/08 15:31:30 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	void	*stmp;

	i = 0;
	stmp = (char *)s;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (stmp + i);
		i++;
	}
	if (s[i] == (char)c)
		return (stmp + i);
	return (0);
}

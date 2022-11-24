/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:50:38 by dborione          #+#    #+#             */
/*   Updated: 2022/11/12 13:29:22 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	int i;
	int j = BUFFER_SIZE;

	i = 0;
	if (!fd)
		return (NULL);
	if (!stash)
		stash = "";
	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while ((j > 0) && (read(fd, buf, 1) && buf[i] != '\n'))
	{
		// if (read(fd, buf, BUFFER_SIZE) == 0)
		// 	return (NULL);
		i++;
		j--;
	}
	printf("%d", i);
	// stash = ft_substr(buf, 0, i + 1);
	// printf("buf:%s:fin", buf);
	free (buf);
	return (stash);
}
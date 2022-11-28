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

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		read_ret;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!ft_strchr(stash, '\n'))
	{
		while ((read_ret = read(fd, buf, BUFFER_SIZE)))
		{
			if (read_ret == -1)
			{
				free (buf);
				return (NULL);
			}
			buf[read_ret] = '\0';
			stash = ft_strjoin(stash, buf);
			if (strchr(buf, '\n'))
			{
				free (buf);
				return (stash);
			}
		}
	}
	free (buf);
	if (*stash == '\0')
		return (NULL);
	return (stash);
}

char *ft_copy_line(char *stash)
{
	char		*line;
	int			i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
	{
		free (stash);
		return (NULL);
	}
	ft_strlcpy(line, stash, (i + 2));
	return (line);
}

char *ft_copy_stash(char *stash)
{
	char		*new_stash;
	int			i;
	int			stash_len;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	stash_len = ft_strlen(stash) - i - 2;
	new_stash = malloc(sizeof(*new_stash) * stash_len);
	if (!new_stash)
	{
		free (stash);
		return (NULL);
	}
	printf("stash:%s:fin\n", stash);
	ft_strlcpy(new_stash, stash, (i + 2));
	free (stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char *line;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	printf("fjhhjhjkh");
	if (!stash)
	{
		stash = malloc(sizeof(*stash));
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	stash = ft_read_line(fd, stash);
	if (!stash)
	{
		free (stash);
		return (NULL);
	}
	stash = ft_copy_stash(stash);
	line = ft_copy_line(stash);
	return (line);
}
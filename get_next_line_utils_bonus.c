/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:37:21 by dborione          #+#    #+#             */
/*   Updated: 2022/10/20 10:50:40 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = ft_strlen(dst);
	i = 0;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[i] && (i < (dstsize - dstlen - 1)))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		i++;
		if (i == (ft_strlen(s) + 1))
			return (NULL);
	}
	return ((char *)&s[i]);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*s3;
	size_t		buf;

	if (!s2 || !s1)
		return (NULL);
	buf = ft_strlen(s1) + ft_strlen(s2) + 1;
	s3 = malloc (sizeof(*s3) * buf);
	if (!s3)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(s3, s1, (ft_strlen(s1) + 1));
	ft_strlcat(s3, s2, buf);
	free(s1);
	return (s3);
}
		// printf("buf:%s\n", buf);
		// printf("stash:%s\n", stash);
		//printf("%c|", stash[i]);
		//OPEN_MAX
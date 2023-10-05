/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:04:55 by eabdelha          #+#    #+#             */
/*   Updated: 2021/11/21 11:14:28 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
//#include <fcntl.h>

char	*ft_rline(char *hol, int i)
{
	int		j;
	char	*rline;

	if (hol == NULL)
		return (NULL);
	j = -1;
	if (i < 0)
		i = ft_strlen(hol) - 1;
	rline = (char *)malloc((size_t)(i + 2));
	if (rline == NULL)
		return (NULL);
	while (hol[++j] && hol[j - 1] != '\n')
		rline[j] = hol[j];
	rline[j] = '\0';
	return (rline);
}

char	*ft_nline(char *hol)
{
	int		j;
	char	*nline;
	int		i;

	j = 0;
	i = ft_strchr(hol);
	if (hol == NULL || (ft_strchr(hol)) < 0)
		return (NULL);
	if (hol != NULL && i == (ft_strlen(hol) - 1))
	{
		free(hol);
		return (NULL);
	}
	nline = (char *)malloc((size_t)(ft_strlen(hol) - i));
	if (nline == NULL)
		return (NULL);
	while (hol[++i])
		nline[j++] = hol[i];
	nline[j] = '\0';
	free(hol);
	hol = NULL;
	return (nline);
}

char	*get_next_line(int fd)
{
	static char	*hol[9000];
	char		*buf;
	int			rt;

	if (fd < 0)
		return (NULL);
	hol[fd] = ft_nline(hol[fd]);
	if ((ft_strchr(hol[fd])) > 0)
		return (ft_rline(hol[fd], ft_strchr(hol[fd])));
	buf = (char *)malloc((size_t)(BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_strchr(hol[fd]) < 0)
	{
		rt = read(fd, buf, BUFFER_SIZE);
		if (rt <= 0)
			break ;
		hol[fd] = ft_strjoin(hol[fd], buf, rt);
	}
	free(buf);
	if (rt < 0)
		return (NULL);
	if (rt == 0 && (ft_strchr(hol[fd])) < 0)
		return (hol[fd]);
	return (ft_rline(hol[fd], ft_strchr(hol[fd])));
}
/*int main (void)
{
	int fd;
	//fd = open("a", O_RDONLY);
	char *g;
	while (g != NULL)
	{
		g = get_next_line(0);
		printf("%s", g);
	}
	
	return 0;
}*/
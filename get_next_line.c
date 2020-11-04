/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:38:53 by youlee            #+#    #+#             */
/*   Updated: 2020/11/04 18:44:27 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char *res;
	int i;
	int j;

	if (!(res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str1[j])
		res[i++] = str1[j++];
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';
	return (res);
}

int		get_next_line(char **line)
{
	int size;
	char *temp;
	char *store;
	char buf[2];

	size = 1;
	buf[size] = '\0';
	store = ft_strjoin("", "");
	while (size == 1 && buf[0] != '\n')
	{
		size = read(0, buf, 1);
		if(buf[0] != '\n', size > 0)
		{
			temp = ft_strjoin(store, buf);
			free(store);
			store = temp;
		}
	}
	*line = store;
	return (size);
}

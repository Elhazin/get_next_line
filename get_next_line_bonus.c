/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:37:05 by abouzanb          #+#    #+#             */
/*   Updated: 2022/11/08 22:14:58 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_if_there_line(char *storage)
{
	int	i;

	i = 0;
	while (storage && storage[i])
	{
		if (storage[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *storage, char *reading)
{
	int		i;
	int		x;
	char	*str;

	x = gnl_strlen(storage);
	i = 0;
	str = malloc(BUFFER_SIZE + x + 1);
	while (storage && storage[i])
	{
		str[i] = storage[i];
		i++;
	}
	x = 0;
	while (reading && reading[x])
		str[i++] = reading[x++];
	str[i] = '\0';
	free(storage);
	return (str);
}

char	*read_from_a_file(int fd, char *storage)
{
	int		readed;
	char	*reading;

	reading = malloc(BUFFER_SIZE + 1);
	readed = 1;
	while (readed != 0 && !check_if_there_line(storage))
	{
		readed = read(fd, reading, BUFFER_SIZE);
		if (readed == -1)
		{
			free(reading);
			free(storage);
			return (NULL);
		}
		reading[readed] = '\0';
		storage = gnl_strjoin(storage, reading);
	}
	free(reading);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*to_line;
	static char	*storage[OPEN_MAX];
	char		*to_recover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_from_a_file(fd, storage[fd]);
	if (storage[fd] == NULL)
		return (NULL);
	to_line = get_until_line(storage[fd]);
	to_recover = storage[fd];
	storage[fd] = get_after_line(storage[fd]);
	free(to_recover);
	return (to_line);
}

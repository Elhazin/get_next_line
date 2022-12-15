/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzanb <abouzanb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:40:40 by abouzanb          #+#    #+#             */
/*   Updated: 2022/11/08 22:19:03 by abouzanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <string.h>
# include<fcntl.h>
# include <stdalign.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*read_from_a_file(int fd, char *storage);
int		check_if_there_line(char *storage);
char	*get_until_line(char *storage);
char	*get_after_line(char *storage);
int		where_is_line( char *storage);
int		gnl_strlen(char *str);
char	*gnl_strsub(const char *str, int begin, int end);
#endif

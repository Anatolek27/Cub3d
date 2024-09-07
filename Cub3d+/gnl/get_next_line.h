/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunegel <akunegel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:04:27 by akunegel          #+#    #+#             */
/*   Updated: 2024/08/08 14:37:47 by akunegel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*f_strchr(char *s, int c);
char	*f_strdup(char *s1);
char	*f_strjoin(char *s1, char *s2);
int ft_strlen(char *str);

#endif
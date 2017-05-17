/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:59:21 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/17 11:55:56 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "/Users/dnetto/Desktop/get_next_line/libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define FD_VL 65636

# define BUFF_SIZE  1

int	get_next_line(const int fd, char **line);

#endif

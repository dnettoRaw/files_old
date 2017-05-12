/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnetto <dnetto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 12:33:45 by dnetto            #+#    #+#             */
/*   Updated: 2017/05/12 19:07:10 by dnetto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
    char    *line = NULL;
    int     fd = 0;
//    int     fd2 = 0;
    int     ret = 0;
/*
    if (ac > 1)
    {
        fd = open(av[1], O_RDONLY);
        fd2 = open(av[2], O_RDONLY);
        get_next_line(fd, &line);    
            puts(line);
        get_next_line(fd2, &line);
            puts(line);
        get_next_line(fd, &line);
            puts(line);
        get_next_line(fd2, &line);
            puts(line);
        get_next_line(fd, &line);
            puts(line); 
        get_next_line(fd2, &line);
            puts(line);
        get_next_line(fd, &line);
            puts(line);
        get_next_line(fd2, &line);
            puts(line);
        get_next_line(fd, &line);    
            puts(line);
        // get_next_line(fd2, &line);
        //     puts(line);
        // get_next_line(fd, &line);
        //     puts(line);
        // get_next_line(fd, &line);
        //     puts(line);
        // get_next_line(fd, &line);
        //     puts(line);
        // get_next_line(fd, &line);
        //     puts(line);
        // get_next_line(fd, &line);
        //     puts(line);
        // get_next_line(fd, &line);
        //     puts(line);
        // get_next_line(fd, &line);
            // puts(line);
        // get_next_line(fd2, &line);  
        // puts(line);
    }
    return (0);
    */
    if (ac > 1)
    {
        if ((fd = open(av[1], O_RDONLY)) > 0)
        {
            while ((ret = get_next_line(fd, &line)) > 0) {
                // ft_putnbr(ret);
                // ft_putstr(">");
                // ft_putstr(line);
                // ft_putstr("<");
                puts(line);
                // ft_putstr(line);
                free(line);
            }
            if (ret < 0){
                printf("/\e[1;31m!\e[0m\\ error reading '%s'\n", av[1]);
            }
            close(fd);
        }
        else {
            printf("/\e[1;31m!\e[0m\\ error opening '%s'\n", av[1]);
        }
    }
    else
        while ((ret = get_next_line(0, &line)) > 0){
            puts(line);
            free(line);
        }
        
    return (0);
}

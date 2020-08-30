/*
** get_next_line.h for get_next_line in /home/atlani/Rendu/Tek2/PSU_réseau/PSU_2016_myftp
** 
** Made by Atlani
** Login   <mylan.atlani@epitech.eu>
** 
** Started on  Sun May 21 18:38:52 2017 Atlani
** Last update Sun May 21 18:41:50 2017 Atlani
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#include <unistd.h>
#include <stdlib.h>

#ifndef READ_SIZE
# define READ_SIZE (10)
#endif /* !READ_SIZE */

char	*get_next_line(const int fd);
char	*my_realloc(char *ptr, int size);
char	define_x(const int fd);

#endif /* !GET_NEXT_LINE_H_ */

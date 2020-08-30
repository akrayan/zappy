/*
** my.h for my.h in /home/thenascrazy/.bibli
**
** Made by Afou Nacerdine
** Login   <afou_n@epitech.net>
**
** Started on  Wed May 25 19:21:10 2016 Afou Nacerdine
** Last update Tue Jun 27 15:35:19 2017 TheNasCrazy
*/

#ifndef MY_H_

# define MY_H_
# define READ_SIZE 10

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"

int		is_lower(char c);
char		*my_strupcase(char *str);
char		*my_strncat(char *dest, char *src, int nb);
char		*my_strstr(char *str, char *to_find);
int		my_strlen(char *str);
char		*my_strcpy(char *dest, char *src);
int		check_end_line(char *buffer);
char		*my_two_str(char *result, char *buffer);
int		rest_of_read(char *buffer, int *k, char **result);
char		*get_next_line(const int fd);
char		my_lower(char c);
int		my_strcasencmp(char *s1, char *s2, int n);
char		*convert_base(char *nbr, char *base_from, char *base_to);
int		my_strncmp(char *s1, char *s2, int n);
int		my_put_nbr(int nb);
int		my_strcmp(char *s1, char *s2);
void		my_show_wordtab(char **tab);
char		*my_strncpy(char *dest, char *src, int n);
void		my_putstr(char *str);
int		my_str_islower(char *str);
int		my_showstr(char *str);
char		my_lower(char c);
int		my_strcasecmp(char *s1, char *s2);
int		check_buf(char *str);
int		my_getnbr(char *str);
char		*my_strcapitalize(char *str);
int		my_putnbr_base(int nbr, char *base);
int		my_swap(char *s1, char *s2);
char		*my_revstr(char *str);
int		is_alpha(char c);
int		my_str_isalpha(char *str);
char		*my_strdup(char *str);
int		is_num(char c);
int		my_str_isnum(char *str);
int		init(char *base, int *nbr, int *j, int *i);
int		check_neg(char *s);
int		check_base(char *base, int n);
int		my_getnbr_base(char *str, char *base);
int		swap_tab(char **tab, int index1, int index2);
int		my_sort_wordtab(char **tab);
int		is_printable(char c);
int		my_str_isprintable(char *str);
void		my_putchar(char c);
int		my_str_isupper(char *str);
char		*my_strcat(char *dest, char *src);
int		is_upper(char c);
char		*my_strlowcase(char *str);
int		my_tablen(char **tab);


int		aff_hexa_min(va_list ap);
int		aff_hexa_maj(va_list ap);
int		aff_octal(va_list ap);
int		aff_printable(va_list ap);
int		aff_unsigned(va_list ap);
int		octal_printable(unsigned int nbr);
int		pf_check_flag(char c);
int		pf_tab_flag(int i, va_list ap);
int		count(int i);
int		pf_strlen(char *str);
int		aff_number(va_list ap);
int		aff_char(va_list ap);
int		aff_string(va_list ap);
int		aff_binary(va_list ap);
int		aff_modulo(va_list ap);
int		aff_pointer(va_list ap);
int		aff_count(va_list ap);
int		my_printf(const char *format, ...);

#endif /* MY_H_*/

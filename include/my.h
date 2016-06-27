/*
** my.h for template in /home/flipper/rendu/template/include/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:10:59 2016 Matthis Le Texier
** Last update Tue May 31 11:27:02 2016 Matthis Le Texier
*/

#ifndef		MY_H_
# define 	MY_H_

# include	<stdarg.h>
# include	<unistd.h>
# include 	<stdbool.h>
# include 	"get_next_line.h"

/*
** Functions parameters.
*/
# define	READ_SIZE	1024
# define	BYTES_PER_LINE	32

/*
** Files descriptors.
*/
# define	STD_INPUT	0
# define	STD_OUTPUT	1
# define	ERR_OUTPUT	2

/*
** Functions returns.
*/
# define	RET_ERROR	-1
# define	RET_SUCCESS	0
# define	RET_FAILURE	1

/*
** Numeric bases.
*/
# define	BASE_BIN	"01"
# define	BASE_OCT	"01234567"
# define	BASE_DEC	"0123456789"
# define	BASE_HEX	"0123456789abcdef"

/*
** Macros.
*/
# define	MIN(X, Y)	(((X) < (Y)) ? (X) : (Y))
# define	MAX(X, Y)	(((X) > (Y)) ? (Y) : (X))
# define	ABS(X)		(((X) < 0) ? -(X) : (X))

/*
** ./memory functions.
*/
void		*my_calloc(int size);
void		*my_malloc(unsigned int size);
void		*my_realloc(void *ptr, int old_size, int new_size);
int		    my_memcpy(void *dest, const void *src, int size);
int		    my_memset(void *ptr, int c, int size);
int		    my_memshow(const void *ptr, int size);
int		    my_memshow_n(const void *ptr, int size, int bytes_per_line);

/*
** ./standard functions.
*/
int		my_fputchar(const int fd, int c);
int		my_putchar(int c);
int		my_fputstr(const int fd, const char *str);
int		my_putstr(const char *str);
int		my_fputnbr_base(const int fd, int nbr, const char *base);
int		my_putnbr_base(int nbr, const char *str);
int		my_fputnbr(const int fd, int nbr);
int		my_putnbr(int nbr);
int		my_getnbr_base(const char *str, const char *base);
int		my_getnbr(const char *str);
int		my_vfprintf(const int fd, const char *format, va_list *vl);
int		my_fprintf(const int fd, const char *format, ...);
int		my_printf(const char *format, ...);

/*
** ./string functions.
*/
int		my_strlen(const char *str);
char		*my_strdup(const char *str);
char		*my_strndup(const char *str, int n);
int		my_explode(char ***arr_ptr, const char *str, const char *dlm);
bool		my_match(const char *str, const char *pattern);
char		*my_getline(const int fd);
int		my_strpos(const char *str, const int c);
const char	*my_strchr(const char *str, const int c);
const char	*my_strstr(const char *haystack, const char *needle);
int		my_strcpy(char *dest, const char *src);
int		my_strncpy(char *dest, const char *src, int n);
int		my_strcat(char *dest, const char *src);
int		my_strncat(char *dest, const char *src, int n);
int		my_strcmp(const char *str1, const char *str2);
int		my_strncmp(const char *str1, const char *str2, int n);
bool		my_str_isnum(const char *str);
int             my_strclean(char *str);
int		my_revstr(char *str);
char		**my_str_to_wordtab(char *str);

/*
** error.c
*/
int		error_int(int code, const char *msg, ...);
void		*error_ptr(void *ptr, const char *msg, ...);
bool		error_bool(bool val, const char *msg, ...);

char		*get_next_line(const int fd);

#endif /* !MY_H_ */

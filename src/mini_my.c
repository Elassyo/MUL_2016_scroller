/*
** mini_my.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 13:07:00 2017 Arthur Melin
** Last update Sat Apr  1 13:08:04 2017 Arthur Melin
*/

#include <scroller.h>

int	my_die(char *msg)
{
  fprintf(stderr, msg);
  return (84);
}

void	*my_die_null(char *msg)
{
  fprintf(stderr, msg);
  return (NULL);
}

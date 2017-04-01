/*
** scroller.h for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 12:39:20 2017 Arthur Melin
** Last update Sat Apr  1 13:08:43 2017 Arthur Melin
*/

#ifndef SCROLLER_H_
# define SCROLLER_H_

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <SFML/Audio.h>
# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <SFML/System.h>

struct	s_scroller;

typedef struct	s_effect
{
  char		*name;
  void		*(*init)(int, char **, int *);
  void		(*render)(struct s_scroller *, void *);
}		t_effect;

typedef struct		s_scroller
{
  int			width;
  int			height;
  sfRenderWindow	window;
  int			effects_count;
  t_effect		effects;
}			t_scroller;

int		my_die(char *msg);
void		*my_die_null(char *msg);

#endif /* !SCROLLER_H_ */

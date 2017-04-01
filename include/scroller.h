/*
** scroller.h for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 12:39:20 2017 Arthur Melin
** Last update Sat Apr  1 13:59:19 2017 Arthur Melin
*/

#ifndef SCROLLER_H_
# define SCROLLER_H_

# include <math.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <SFML/Audio.h>
# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <SFML/System.h>

struct	s_scroller;

typedef struct	s_effect
{
  char		*name;
  void		*(*init)(int, char **, int *);
  void		(*render)(struct s_scroller *, void *,
			  const sfUint8 *, sfUint8 *);
  void		(*free)(void *);
}		t_effect;

typedef struct		s_effect_list
{
  void			(*render)(struct s_scroller *, void *,
				  const sfUint8 *, sfUint8 *);
  void			(*free)(void *);
  void			*param;
  struct s_effect_list	*next;
}			t_effect_list;

typedef struct		s_scroller
{
  int			width;
  int			height;
  sfRenderWindow	*window;
  int			effects_count;
  t_effect		*effects;
  t_effect_list		*effect_list;
}			t_scroller;

int		window_create(t_scroller *app);
void		window_destroy(t_scroller *app);

int		init_effects(t_scroller *app);
int		list_effects(char *app_name, t_scroller *app);

void		*test_init(int argc, char **argv, int *pos);
void		test_render(t_scroller *app, void *param,
			    const sfUint8 *ifb, sfUint8 *ofb);
void		test_free(void *param);

int		my_die(char *msg);
void		*my_die_null(char *msg);

#endif /* !SCROLLER_H_ */

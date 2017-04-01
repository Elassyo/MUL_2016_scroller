/*
** effects.c for  in /home/remi/delivery/Igraph2016/scroller/src
** 
** Made by Rémi
** Login   <remi.vuillemin@epitech.eu@epitech.net>
** 
** Started on  Sat Apr  1 13:11:05 2017 Rémi
** Last update Sat Apr  1 13:18:50 2017 Rémi
*/

#include <scroller.h>

static void	add_effect(t_effect *ptr, char *name,
			   void *(*init)(int, char **, int *),
			   void (*render)(t_scroller *, void *))
{
  ptr->name = name;
  ptr->init = init;
  ptr->render = render;
}

int		init_effects(t_scroller *app)
{
  t_effect	*ptr;

  app->effects_count = 1;
  if (!(app->effects = malloc(app->effects_count * sizeof(t_effect))))
    return (my_die("Fatal: malloc failed\n"));
  ptr = app->effects;
  add_effect(ptr++, "test", test_init, test_render);
  return (0);
}

int	list_effects(char *app_name, t_scroller *app)
{
  int	i;

  printf("Usage: %s w h [effect [arg1 arg2 ...]] ...\n\n", app_name);
  printf("%d effects:\n", app->effects_count);
  i = 0;
  while (i < app->effects_count)
      printf("  %s\n", app->effects[i++].name);
  return (84);
}

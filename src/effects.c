/*
** effects.c for  in /home/remi/delivery/Igraph2016/scroller/src
**
** Made by Rémi
** Login   <remi.vuillemin@epitech.eu@epitech.net>
**
** Started on  Sat Apr  1 13:11:05 2017 Rémi
** Last update Sat Apr  1 14:18:17 2017 Arthur Melin
*/

#include <scroller.h>

static void	add_effect(t_effect *ptr, char *name, ...)
{
  va_list	args;

  va_start(args, name);
  ptr->name = name;
  ptr->init = va_arg(args, void *(*)(int, char **, int *));
  ptr->render = va_arg(args, void (*)(struct s_scroller *, void *,
				     const sfUint8 *, sfUint8 *));
  ptr->free = va_arg(args, void (*)(void *));
  va_end(args);
}

int		init_effects(t_scroller *app)
{
  t_effect	*ptr;

  app->effects_count = 1;
  if (!(app->effects = malloc(app->effects_count * sizeof(t_effect))))
    return (my_die("Fatal: malloc failed\n"));
  ptr = app->effects;
  add_effect(ptr++, "test", test_init, test_render, test_free);
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

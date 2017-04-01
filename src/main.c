/*
** main.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 12:38:53 2017 Arthur Melin
** Last update Sat Apr  1 13:43:31 2017 Arthur Melin
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

static int	init_effects(t_scroller *app)
{
  t_effect	*ptr;

  app->effects_count = 1;
  if (!(app->effects = malloc(app->effects_count * sizeof(t_effect))))
    return (my_die("Fatal: malloc failed\n"));
  ptr = app->effects;
  add_effect(ptr++, "test", test_init, test_render);
  return (0);
}

static int	list_effects(char *app_name, t_scroller *app)
{
  int		i;

  printf("Usage: %s w h [effect [arg1 arg2 ...]] ...\n\n", app_name);
  printf("%d effects:\n", app->effects_count);
  i = 0;
  while (i < app->effects_count)
      printf("  %s\n", app->effects[i++].name);
  return (84);
}

int		main(int argc, char **argv)
{
  int		pos;
  t_scroller	app;

  pos = 1;
  if (init_effects(&app))
    return (84);
  if (argc < 3)
    return (list_effects(argv[0], &app));
  app.width = atoi(argv[1]);
  app.height = atoi(argv[2]);
  if (app.width <= 0 || app.height <= 0)
    return (my_die("Error: invalid window size\n"));
  if (window_create(&app))
    return (84);
  window_destroy(&app);
  free(app.effects);
  return (0);
}

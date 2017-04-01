/*
** main.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 12:38:53 2017 Arthur Melin
** Last update Sat Apr  1 13:09:44 2017 Arthur Melin
*/

#include <scroller.h>

void		init_effects(t_scroller *app)
{
  app->effects_count = 0;
}

int		list_effects(char *app_name, t_scroller *app)
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
  init_effects(&app);
  if (argc < 3)
    return (list_effects(argv[0], &app));
  app.width = atoi(argv[1]);
  app.height = atoi(argv[2]);
  if (app.width <= 0 || app.height <= 0)
    return (my_die("Error: invalid window size\n"));
  return (0);
}

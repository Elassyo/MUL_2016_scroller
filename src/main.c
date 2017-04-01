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

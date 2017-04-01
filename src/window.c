/*
** window.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 13:17:26 2017 Arthur Melin
** Last update Sat Apr  1 13:22:20 2017 Arthur Melin
*/

#include <scroller.h>

int		window_create(t_scroller *app)
{
  sfVideoMode	mode;

  mode.width = app->width;
  mode.height = app->height;
  mode.bitsPerPixel = 32;
  if (!(app->window = sfRenderWindow_create(mode, "Scroller", sfClose, NULL)))
    return (my_die("Error: failed to open window\n"));
  return (0);
}

void	window_destroy(t_scroller *app)
{
  sfRenderWindow_destroy(app->window);
}

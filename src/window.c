/*
** window.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 13:17:26 2017 Arthur Melin
** Last update Sat Apr  1 15:03:34 2017 Arthur Melin
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
  if (!(app->texture = sfRenderTexture_create(app->width, app->height, 0)))
    return (my_die("Error: failed to create render texture\n"));
  if (!(app->sprite =  sfSprite_create()))
    return (my_die("Error: failed to create render sprite\n"));
  if (!(app->tmpTexture = sfTexture_create(app->width, app->height)))
    return (my_die("Error: failed to create temporary target texture\n"));
  if (!(app->tmpSprite =  sfSprite_create()))
    return (my_die("Error: failed to create temporary target sprite\n"));
  if (!(app->ifb = malloc(4 * app->width * app->height)) ||
      !(app->ofb = malloc(4 * app->width * app->height)))
    return (my_die("Fatal: malloc failed\n"));
  return (0);
}

void	window_destroy(t_scroller *app)
{
  sfRenderWindow_destroy(app->window);
  sfRenderTexture_destroy(app->texture);
  sfTexture_destroy(app->tmpTexture);
  sfSprite_destroy(app->sprite);
  sfSprite_destroy(app->tmpSprite);
  free(app->ifb);
  free(app->ofb);
}

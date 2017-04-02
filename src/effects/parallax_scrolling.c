/*
** parallax_scrolling.c for emacs in /home/baptiste.kissel/scroller/src/effects
** 
** Made by Baptiste Kissel
** Login   <baptiste.kissel@epitech.net>
** 
** Started on  Sat Apr  1 21:36:29 2017 Baptiste Kissel
** Last update Sun Apr  2 15:36:10 2017 Baptiste Kissel
*/

#include <effects.h>
#include <parallax_scrolling.h>

void			*parallax_scrolling_init(int __attribute__ ((unused))
						 argc,
						 char __attribute__ ((unused))
						 **argv, int *pos)
{
  t_parallax_scrolling	*res;
  sfImage		*image;

  if (!(res = malloc(sizeof(t_parallax_scrolling))))
    return (my_die_null("Fatal: malloc failed\n"));
  if (!(image = sfImage_createFromFile(ST_IMAGE_PATH)))
    return (my_die_null("Error: failed to open font image\n"));
  sfImage_createMaskFromColor(image, sfBlack, 0);
  if (!(res->texture = sfTexture_createFromImage(image, NULL)))
    return (my_die_null("Error: failed to upload image to texture\n"));
  if (!(res->sprite = sfSprite_create()))
    return (my_die_null("Error: failed to create sprite\n"));
  sfSprite_setTexture(res->sprite, res->texture, sfTrue);
  sfImage_destroy(image);
  res->counter = 0;
  (*pos) += 1;
  return (res);
}

int			parallax_scrolling_render(t_scroller *app, void *param)
{
  sfVector2f		vec;
  t_parallax_scrolling	*ps;

  ps = (t_parallax_scrolling *)param;
  vec.x = 2 * ps->counter % 1280;
  vec.y = app->height / 2;
  sfSprite_setPosition(ps->sprite, vec);
  sfRenderTexture_drawSprite(app->texture, ps->sprite, NULL);
  vec.x = (2 * ps->counter % 1280) - 1280;
  vec.y = app->height / 2;
  sfSprite_setPosition(ps->sprite, vec);
  sfRenderTexture_drawSprite(app->texture, ps->sprite, NULL);
  ps->counter++;
  return (0);
}

void			parallax_scrolling_free(void *param)
{
  t_parallax_scrolling	*ps;

  ps = (t_parallax_scrolling *)param;
  sfSprite_destroy(ps->sprite);
  sfTexture_destroy(ps->texture);
  free(ps);
}


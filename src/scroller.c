/*
** scroller.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 15:15:13 2017 Arthur Melin
** Last update Sun Apr  2 20:19:32 2017 Arthur Melin
*/

#include <scroller.h>

static void	flipcpy(sfUint8 *dst, const sfUint8 *src, int w, int h)
{
  int		y;

  y = 0;
  while (y < h)
    {
      memcpy(dst + 4 * y * w, src + 4 * (h - y - 1) * w, 4 * w);
      y++;
    }
}

static void		render(t_scroller *app)
{
  sfImage		*image;
  t_effect_list		*effect;
  const sfTexture	*texture;

  effect = app->effect_list;
  sfRenderTexture_clear(app->texture, sfBlack);
  while (effect)
    {
      image = sfTexture_copyToImage(sfRenderTexture_getTexture(app->texture));
      flipcpy(app->ifb, sfImage_getPixelsPtr(image), app->width, app->height);
      if (effect->render(app, effect->param))
	{
	  sfTexture_updateFromPixels(app->tmpTexture, app->ofb,
				     app->width, app->height, 0, 0);
	  sfSprite_setTexture(app->tmpSprite, app->tmpTexture, sfTrue);
	  sfRenderTexture_drawSprite(app->texture, app->tmpSprite, NULL);
	}
      sfImage_destroy(image);
      effect = effect->next;
    }
  texture = sfRenderTexture_getTexture(app->texture);
  sfSprite_setTexture(app->sprite, texture, sfFalse);
}

int			scroller(t_scroller *app)
{
  sfIntRect		rect;
  sfEvent		event;

  rect.left = 0;
  rect.top = app->height;
  rect.width = app->width;
  rect.height = -app->height;
  sfSprite_setTextureRect(app->sprite, rect);
  while (sfRenderWindow_isOpen(app->window))
    {
      render(app);
      sfRenderWindow_drawSprite(app->window, app->sprite, NULL);
      sfRenderWindow_display(app->window);
      if (sfRenderWindow_pollEvent(app->window, &event) &&
	  (event.type == sfEvtClosed ||
	   (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)))
	sfRenderWindow_close(app->window);
    }
  return (0);
}

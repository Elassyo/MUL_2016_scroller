/*
** scroller.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 15:15:13 2017 Arthur Melin
** Last update Sat Apr  1 18:22:29 2017 Arthur Melin
*/

#include <scroller.h>

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
      memcpy(app->ifb, sfImage_getPixelsPtr(image),
	     4 * app->width * app->height);
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

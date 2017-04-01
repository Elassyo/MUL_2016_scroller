/*
** scroller.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 15:15:13 2017 Arthur Melin
** Last update Sat Apr  1 15:36:57 2017 Arthur Melin
*/

#include <scroller.h>

static const sfUint8	*get_pixels(t_scroller *app)
{
  sfImage		*image;
  const sfTexture	*texture;

  texture = sfRenderTexture_getTexture(app->texture);
  image = sfTexture_copyToImage(texture);
  return (sfImage_getPixelsPtr(image));
}

static void	set_pixels(t_scroller *app, sfUint8 *fb)
{
  sfTexture_updateFromPixels(app->tmpTexture, fb,
			     app->width, app->height, 0, 0);
  sfSprite_setTexture(app->tmpSprite, app->tmpTexture, sfTrue);
  sfRenderTexture_drawSprite(app->texture, app->tmpSprite, NULL);
}

int			scroller(t_scroller *app)
{
  sfUint8		*framebuffer;
  sfEvent		event;
  t_effect_list		*effect;

  if (!(framebuffer = malloc(4 * app->width * app->height)))
    return (my_die("Fatal: malloc failed\n"));
  while (sfRenderWindow_isOpen(app->window))
    {
      sfRenderTexture_clear(app->texture, sfTransparent);
      sfRenderWindow_clear(app->window, sfBlack);
      effect = app->effect_list;
      while (effect)
	{
	  if (effect->render(app, effect->param, get_pixels(app), framebuffer))
	    set_pixels(app, framebuffer);
	  effect = effect->next;
	}
      sfRenderWindow_display(app->window);
      if (sfRenderWindow_pollEvent(app->window, &event) &&
	  (event.type == sfEvtClosed ||
	   (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)))
	sfRenderWindow_close(app->window);
    }
  free(framebuffer);
  return (0);
}

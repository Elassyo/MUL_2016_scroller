/*
** image.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sun Apr  2 17:58:03 2017 Arthur Melin
** Last update Sun Apr  2 18:29:49 2017 Arthur Melin
*/

#include <effects.h>
#include <image.h>

void		*image_init(int argc, char **argv, int *pos)
{
  sfVector2f	vec;
  t_image	*res;

  if (argc - *pos < 6)
    return (my_die_null("Effect usage: image PATH X Y W H\n"));
  if (!(res = malloc(sizeof(t_image))))
    return (my_die_null("Error: malloc failed"));
  if (!(res->texture = sfTexture_createFromFile(argv[*pos + 1], NULL)) ||
      !(res->sprite = sfSprite_create()))
    return (my_die_null("Error: failed to open image\n"));
  sfSprite_setTexture(res->sprite, res->texture, sfTrue);
  vec.x = atoi(argv[*pos + 2]);
  vec.y = atoi(argv[*pos + 3]);
  sfSprite_setPosition(res->sprite, vec);
  vec.x = (float)atoi(argv[*pos + 4]) / sfTexture_getSize(res->texture).x;
  vec.y = (float)atoi(argv[*pos + 5]) / sfTexture_getSize(res->texture).y;
  sfSprite_setScale(res->sprite, vec);
  (*pos) += 6;
  return (res);
}

int		image_render(t_scroller *app, void *param)
{
  t_image	*image;

  image = (t_image *)param;

  sfRenderTexture_drawSprite(app->texture, image->sprite, NULL);
  return (0);
}

void		image_free(void *param)
{
  t_image	*image;

  image = (t_image *)param;
  sfSprite_destroy(image->sprite);
  sfTexture_destroy(image->texture);
  free(image);
}

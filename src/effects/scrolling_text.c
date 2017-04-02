/*
** scrolling_text.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 16:40:37 2017 Arthur Melin
** Last update Sun Apr  2 17:26:00 2017 Arthur Melin
*/

#include <effects.h>
#include <scrolling_text.h>

static void	draw_char(char c, int i, sfImage *font, sfImage *out)
{
  int		font_pos;
  char		*font_map;
  sfIntRect	rect;

  font_map = ST_FONT_MAP;
  if (!strchr(font_map, c))
    return ;
  font_pos = strchr(font_map, c) - font_map;
  rect.left = (font_pos % ST_FONT_CPL) * ST_FONT_CW;
  rect.top = (font_pos / ST_FONT_CPL) * ST_FONT_CH;
  rect.width = ST_FONT_CW;
  rect.height = ST_FONT_CH;
  sfImage_copyImage(out, font, i * ST_FONT_CW, 0, rect, sfTrue);
}

static int	gen_sprite(t_scrolling_text *st, char *text)
{
  int		i;
  sfImage	*font_image;
  sfImage	*text_image;

  if (!(font_image = sfImage_createFromFile(ST_FONT_PATH)))
    return (my_die("Error: failed to open font image\n"));
  if (!(text_image = sfImage_create(st->width = ST_FONT_CW * strlen(text),
				    st->height = ST_FONT_CH)))
    return (my_die("Error: failed to create temporary image\n"));
  i = 0;
  while (text[i])
    {
      draw_char(toupper(text[i]), i, font_image, text_image);
      i++;
    }
  sfImage_createMaskFromColor(text_image, sfBlack, 0);
  if (!(st->texture = sfTexture_createFromImage(text_image, NULL)))
    return (my_die("Error: failed to upload image to texture\n"));
  if (!(st->sprite = sfSprite_create()))
    return (my_die("Error: failed to create sprite\n"));
  sfSprite_setTexture(st->sprite, st->texture, sfTrue);
  sfImage_destroy(text_image);
  sfImage_destroy(font_image);
  return (0);
}

void			*scrolling_text_init(int argc, char **argv, int *pos)
{
  sfVector2f		vec;
  char			*text;
  t_scrolling_text	*res;

  if (argc - *pos < 3)
    return (my_die_null("Effect usage: scrolling_text TEXT TYPE\n"));
  if (!(res = malloc(sizeof(t_scrolling_text))))
    return (my_die_null("Fatal: malloc failed\n"));
  text = argv[*pos + 1];
  if (gen_sprite(res, text))
    return (NULL);
  res->scroll_type = atoi(argv[*pos + 2]);
  if (!(0 < res->scroll_type && res->scroll_type <= 4))
    return (my_die_null("Error: invalid scroll type (1->4)\n"));
  res->counter = 0;
  (*pos) += 3;
  vec.x = res->width / 2;
  vec.y = res->height / 2;
  sfSprite_setOrigin(res->sprite, vec);
  res->width *= (vec.x = 4);
  res->height *= (vec.y = 4);
  sfSprite_setScale(res->sprite, vec);
  return (res);
}

int			scrolling_text_render(t_scroller *app, void *param)
{
  sfVector2f		pos;
  t_scrolling_text	*st;

  st = (t_scrolling_text *)param;
  if (st->scroll_type == ST_TYPE_SIN)
    {
      pos.y = (0.6 * sin(st->counter * M_PI / 180) + 1) * app->height / 2;
      sfSprite_setRotation(st->sprite, 45 * cos(st->counter * M_PI / 180));
    }
  else
    pos.y = st->scroll_type == ST_TYPE_HRZ ? app->height / 2 :
      5 * st->counter % (app->height + st->height) - st->height / 2;
  pos.x = st->scroll_type == ST_TYPE_VRT ? app->width / 2 :
    5 * st->counter % (app->width + st->width) - st->width / 2;
  sfSprite_setPosition(st->sprite, pos);
  sfRenderTexture_drawSprite(app->texture, st->sprite, NULL);
  st->counter++;
  return (0);
}

void			scrolling_text_free(void *param)
{
  t_scrolling_text	*st;

  st = (t_scrolling_text *)param;
  sfSprite_destroy(st->sprite);
  sfTexture_destroy(st->texture);
  free(st);
}

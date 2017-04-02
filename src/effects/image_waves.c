/*
** image_waves.c for emacs in /home/baptiste.kissel/scroller/src
** 
** Made by Baptiste Kissel
** Login   <baptiste.kissel@epitech.net>
** 
** Started on  Sun Apr  2 16:31:59 2017 Baptiste Kissel
** Last update Sun Apr  2 20:05:12 2017 Baptiste Kissel
*/

#include <effects.h>

void	*image_waves_init(int __attribute__ ((unused)) argc,
			  char __attribute__ ((unused)) **argv, int *pos)
{
  int	*res;

  if (!(res = malloc(sizeof(int))))
    return (my_die_null("Fatal: malloc failed\n"));
  *res = 0;
  (*pos) += 1;
  return (res);
}
int	image_waves_render(t_scroller *app, void *param)
{
  int	x;
  int	y;
  int	off;
  int	px_off;
  int	counter;

  counter = (*(int *)param)++;
  memset(app->ofb, 255, 4 * app->width * app->height);
  y = 0;
  while(y < app->height)
    {
      px_off = 42 * sin(counter * 0.069) * sin(0.0666 * (y + counter));
      x = px_off < 0 ? 0 : px_off;
      while (x < app->width + (px_off > 0 ? 0 : px_off))
	{
	  off = x + y * app->width;
	  app->ofb[4 * off] = app->ifb[4 * (off + px_off)];
	  app->ofb[4 * off + 1] = app->ifb[4 * (off + px_off) + 1];
	  app->ofb[4 * off + 2] = app->ifb[4 * (off + px_off) + 2];
	  app->ofb[4 * off + 3] = app->ifb[4 * (off + px_off) + 3];
	  x++;
	}
      y++;
    }
  return (1);
}
void		image_waves_free(void *param)
{
  free(param);
}

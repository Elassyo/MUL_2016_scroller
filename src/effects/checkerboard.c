/*
** checkerboard.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sun Apr  2 18:43:03 2017 Arthur Melin
** Last update Sun Apr  2 21:12:47 2017 Arthur Melin
*/

#include <effects.h>

void	*checkerboard_init(int __attribute__ ((unused)) argc,
			  char __attribute__ ((unused)) **argv, int *pos)
{
  int	*res;

  if (!(res = malloc(sizeof(int))))
    return (my_die_null("Fatal: malloc failed\n"));
  *res = 0;
  (*pos) += 1;
  return (res);
}

int	checkerboard_render(t_scroller *app, void *param)
{
  int	x;
  int	y;
  int	off;
  int	counter;

  counter = (*(int *)param)++;
  y = 0;
  while(y < app->height)
    {
      x = 0;
      while (x < app->width)
	{
	  off = x + y * app->width;
	  if (((x + counter) / 128 + (y + counter) / 128) % 2 == 0)
	    *((sfUint32 *)app->ofb + off) = *((sfUint32 *)app->ifb + off);
	  else
	    *((sfUint32 *)app->ofb + off) =
	      (255 - *((sfUint32 *)app->ifb + off)) | 0xff000000;
	  x++;
	}
      y++;
    }
  return (1);
}

void		checkerboard_free(void *param)
{
  free(param);
}

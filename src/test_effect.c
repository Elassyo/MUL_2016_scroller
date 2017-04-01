/*
** test_effect.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 13:48:22 2017 Arthur Melin
** Last update Sat Apr  1 19:42:52 2017 Arthur Melin
*/

#include <effects.h>

float	saturate(float x)
{
  return (x < 1.0 ? (x > 0.0 ? x : 0.0) : 1.0);
}

void	*test_init(int __attribute__ ((unused)) argc,
		   char __attribute__ ((unused)) **argv, int *pos)
{
  int	*counter;

  if (!(counter = malloc(sizeof(int))))
    return (NULL);
  *counter = 0;
  (*pos)++;
  return (counter);
}

int		test_render(t_scroller *app, void *param)
{
  int		i;
  int		*counter;
  float		hue;
  sfUint8	color[4];

  counter = (int *)param;
  hue = fmod((float)(*counter)++ / 256, 1.0);
  color[0] = 255 * saturate(fabs(hue * 6.0 - 3.0) - 1.0);
  color[1] = 255 * saturate(2.0 - fabs(hue * 6.0 - 2.0));
  color[2] = 255 * saturate(2.0 - fabs(hue * 6.0 - 4.0));
  color[3] = 255;
  i = 0;
  while (i < app->width * app->height)
    {
      app->ofb[4 * i] = color[0];
      app->ofb[4 * i + 1] = color[1];
      app->ofb[4 * i + 2] = color[2];
      app->ofb[4 * i + 3] = color[3];
      i++;
    }
  return (1);
}

void	test_free(void *param)
{
  free(param);
}

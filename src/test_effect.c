/*
** test_effect.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 13:48:22 2017 Arthur Melin
** Last update Sat Apr  1 13:48:32 2017 Arthur Melin
*/

#include <scroller.h>

void	*test_init(int argc, char **argv, int *pos)
{
  float	*counter;

  (void)argc;
  (void)argv;
  (*pos)++;
  if (!(counter = malloc(sizeof(float))))
    return (NULL);
  *counter = 0;
  return (counter);
}

int	test_render(t_scroller *app, void *param)
{
  float	*counter;

  counter = (float *)param;
  memset(app->ofb, cos((*counter)++ * M_PI / 180) * 127 + 128,
	 4 * app->width * app->height);
  return (1);
}

void	test_free(void *param)
{
  free(param);
}

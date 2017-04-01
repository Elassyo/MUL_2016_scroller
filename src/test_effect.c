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
  (void)argc;
  (void)argv;
  (*pos)++;
  return (malloc(0));
}

void	test_render(t_scroller *app, void *param,
		    const sfUint8 *ifb, sfUint8 *ofb)
{
  (void)param;
  memcpy(ofb, ifb, app->width * app->height * 4);
}

void	test_free(void *param)
{
  free(param);
}

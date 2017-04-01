/*
** main.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 12:38:53 2017 Arthur Melin
** Last update Sat Apr  1 15:37:40 2017 Arthur Melin
*/

#include <scroller.h>

static int		add_effect(t_scroller *app, int	i, void *param)
{
  t_effect_list		*effect;
  t_effect_list		**ptr;

  ptr = &app->effect_list;
  while (*ptr)
    ptr = &(*ptr)->next;
  if (!(effect = malloc(sizeof(t_effect_list))))
    return (my_die("Fatal: malloc failed\n"));
  effect->render = app->effects[i].render;
  effect->free = app->effects[i].free;
  effect->param = param;
  effect->next = NULL;
  *ptr = effect;
  return (0);
}

static t_effect_list	*free_effect(t_effect_list *effect)
{
  t_effect_list		*next;

  next = effect->next;
  effect->free(effect->param);
  free(effect);
  return (next);
}

int	parse_cmd(int argc, char **argv, t_scroller *app)
{
  int	i;
  int	pos;
  void	*param;

  pos = 3;
  while (pos < argc)
    {
      i = 0;
      while (i < app->effects_count)
	{
	  if (strcmp(app->effects[i].name, argv[pos]) == 0)
	    {
	      if (!(param = app->effects[i].init(argc, argv, &pos)) ||
		  add_effect(app, i, param))
		return (84);
	      break;
	    }
	  i++;
	}
      if (i == app->effects_count)
	return (my_die("Error: invalid argument\n"));
    }
  return (0);
}

int			main(int argc, char **argv)
{
  t_effect_list		*effect;
  t_scroller		app;

  if (init_effects(&app))
    return (84);
  if (argc < 3)
    return (list_effects(argv[0], &app));
  app.effect_list = NULL;
  if (parse_cmd(argc, argv, &app))
    return (84);
  app.width = atoi(argv[1]);
  app.height = atoi(argv[2]);
  if (app.width <= 0 || app.height <= 0)
    return (my_die("Error: invalid window size\n"));
  if (window_create(&app) || scroller(&app))
    return (84);
  effect = app.effect_list;
  while (effect)
    effect = free_effect(effect);
  window_destroy(&app);
  free(app.effects);
  return (0);
}

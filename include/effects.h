/*
** effects.h for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 16:41:27 2017 Arthur Melin
** Last update Sun Apr  2 18:40:37 2017 Baptiste Kissel
*/

#ifndef EFFECTS_H_
# define EFFECTS_H_

# include <scroller.h>

# define ADD_EFFECT(n) add_effect(ptr++, #n, n##_init, n##_render, n##_free)

void		*test_init(int argc, char **argv, int *pos);
int		test_render(t_scroller *app, void *param);
void		test_free(void *param);

void		*scrolling_text_init(int argc, char **argv, int *pos);
int		scrolling_text_render(t_scroller *app, void *param);
void		scrolling_text_free(void *param);

void		*parallax_scrolling_init(int argc, char **argv, int *pos);
int		parallax_scrolling_render(t_scroller *app, void *param);
void		parallax_scrolling_free(void *param);

void		*tracker_init(int argc, char **argv, int *pos);
int		tracker_render(t_scroller *app, void *param);
void		tracker_free(void *param);

void		*image_init(int argc, char **argv, int *pos);
int		image_render(t_scroller *app, void *param);
void		image_free(void *param);

void		*image_waves_init(int argc, char **argv, int *pos);
int		image_waves_render(t_scroller *app, void *param);
void		image_waves_free(void *param);

void		*checkerboard_init(int argc, char **argv, int *pos);
int		checkerboard_render(t_scroller *app, void *param);
void		checkerboard_free(void *param);

#endif /* !EFFECTS_H_ */

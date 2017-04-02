/*
** parallax_scrolling.h for emacs in /home/baptiste.kissel/scroller/include
** 
** Made by Baptiste Kissel
** Login   <baptiste.kissel@epitech.net>
** 
** Started on  Sat Apr  1 21:39:07 2017 Baptiste Kissel
** Last update Sun Apr  2 15:23:33 2017 Baptiste Kissel
*/

#ifndef PARALLAX_SCROLLING_H_
# define PARALLAX_SCROLLING_H_

# define ST_IMAGE_PATH	"picture/montagnes.png"

typedef struct  s_parallax_scrolling
{
  sfSprite      *sprite;
  sfTexture     *texture;
  int           counter;
  int           width;
  int           height;
}               t_parallax_scrolling;

#endif /* !PARALLAX_SCROLLING_H_ */

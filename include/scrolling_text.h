/*
** scrolling_text.h for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 16:52:52 2017 Arthur Melin
** Last update Sat Apr  1 17:04:19 2017 Arthur Melin
*/

#ifndef SCROLLING_TEXT_H_
# define SCROLLING_TEXT_H_

# define ST_FONT_PATH	"font/font5.png"
# define ST_FONT_MAP_	" !\"#$% '()*+,-./0123456789:;<=>?@"
# define ST_FONT_MAP	ST_FONT_MAP_"ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]"
# define ST_FONT_CW	20
# define ST_FONT_CH	20
# define ST_FONT_CPL	13

# define ST_TYPE_HRZ	1
# define ST_TYPE_VRT	2
# define ST_TYPE_DIA	3
# define ST_TYPE_SIN	4

typedef struct	s_scrolling_text
{
  sfSprite	*sprite;
  sfTexture	*texture;
  int		scroll_type;
  int		counter;
  int		width;
  int		height;
}		t_scrolling_text;

#endif /* !SCROLLING_TEXT_H_ */

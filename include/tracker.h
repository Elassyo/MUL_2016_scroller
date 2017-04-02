/*
** tracker.h for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 22:02:14 2017 Arthur Melin
** Last update Sat Apr  1 22:03:21 2017 Arthur Melin
*/

#ifndef TRACKER_H_
# define TRACKER_H_

# define TRK_SAMPLES_PATH	"modlike"

typedef struct	s_note
{
  float		freq;
  float		dur;
}		t_note;

typedef struct		s_tracker
{
  int			len;
  int			pos;
  t_note		notes[1000];
  sfClock		*clock;
  sfSound		*sound;
  sfSoundBuffer		*soundbuffer;
}			t_tracker;

#endif /* !TRACKER_H */

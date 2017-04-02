/*
** tracker.c for scroller in /home/arthur.melin/Code/scroller
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.eu>
**
** Started on  Sat Apr  1 22:01:17 2017 Arthur Melin
** Last update Sun Apr  2 17:32:06 2017 Arthur Melin
*/

#include <effects.h>
#include <tracker.h>

int	parse_bsf_2(t_tracker *trk, FILE *f)
{
  int	i;

  i = 0;
  while (i < trk->len)
    {
      if (fscanf(f, "%*[\n\"]%f%*[\"]", &trk->notes[i++].freq) != 1)
	return (84);
      if (fgetc(f) != ',')
	break;
    }
  return (0);
}

int	parse_bsf(t_tracker *trk, FILE *f)
{
  int	i;
  char	key[256];
  char	path[256];

  strcpy(path, "modlike/");
  if (fscanf(f, "[track%d]%*[\n ] ", &i) != 1 || i != 1 ||
      fscanf(f, "%256[a-z]=", key) != 1 || strcmp(key, "sample") ||
      fscanf(f, "%*[\"]%256[a-zA-Z.-_]%*[\"\n ]", path + strlen(path)) != 1 ||
      fscanf(f, "%256[a-z]=", key) != 1 || strcmp(key, "duration"))
    return (my_die("Error: invalid BSF file 1\n"));
  i = 0;
  while (i < 1000)
    {
      if (fscanf(f, "%*[\n\"]%f%*[\"]", &trk->notes[i++].dur) != 1)
	return (my_die("Error: invalid BSF file 2\n"));
      if (fgetc(f) != ',')
	break;
    }
  trk->len = i;
  fscanf(f, "%*[\n ]");
  if (fscanf(f, "%256[a-z]=", key) != 1 || strcmp(key, "frequency") ||
      parse_bsf_2(trk, f))
    return (my_die("Error: invalid BSF file 3\n"));
  return ((trk->soundbuffer = sfSoundBuffer_createFromFile(path)) ? 0 : 84);
}

void		*tracker_init(int argc, char **argv, int *pos)
{
  FILE		*f;
  t_tracker	*trk;

  if (argc - *pos < 4)
    return (my_die_null("Effect usage: tracker BSF SLIDE VIBRATO\n"));
  if (!(trk = malloc(sizeof(t_tracker))))
    return (my_die_null("Error: malloc failed\n"));
  if (!(f = fopen(argv[*pos + 1], "r")))
    return (my_die_null("Error: failed to open BSF file\n"));
  trk->slide = atoi(argv[*pos + 2]);
  trk->vibrato = atoi(argv[*pos + 3]);
  if (parse_bsf(trk, f))
    return (NULL);
  trk->pos = 0;
  trk->pitch = trk->notes[0].freq / 440;
  trk->clock = sfClock_create();
  trk->sound = sfSound_create();
  sfSound_setBuffer(trk->sound, trk->soundbuffer);
  sfSound_setPitch(trk->sound, trk->pitch);
  sfSound_play(trk->sound);
  (*pos) += 4;
  fclose(f);
  return (trk);
}

int		tracker_render(t_scroller __attribute__ ((unused)) *app,
			       void *param)
{
  t_tracker	*trk;
  float		time;
  float		slide;
  float		vibrato;

  trk = (t_tracker *)param;
  time = sfTime_asMilliseconds(sfClock_getElapsedTime(trk->clock));
  if (time > trk->notes[trk->pos % trk->len].dur)
    {
      sfSound_stop(trk->sound);
      sfSound_play(trk->sound);
      trk->pitch = trk->notes[++trk->pos % trk->len].freq / 440;
      sfClock_restart(trk->clock);
    }
  slide = trk->slide ? time / trk->notes[trk->pos % trk->len].dur *
    ((trk->notes[(trk->pos + 1) % trk->len].freq / 440) - trk->pitch) : 0;
  vibrato = trk->vibrato ? 0.01 * exp(0.001 * time) * sin(time) + 1 : 1;
  sfSound_setPitch(trk->sound, (trk->pitch + slide) * vibrato);
  return (0);
}

void		tracker_free(void *param)
{
  t_tracker	*trk;

  trk = (t_tracker *)param;
  sfClock_destroy(trk->clock);
  sfSound_stop(trk->sound);
  sfSound_destroy(trk->sound);
  sfSoundBuffer_destroy(trk->soundbuffer);
  free(trk);
}

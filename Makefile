##
## Makefile for scroller in /home/arthur.melin/Code/scroller
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.eu>
##
## Started on  Sat Apr  1 12:34:59 2017 Arthur Melin
## Last update Sun Apr  2 19:51:16 2017 Baptiste Kissel
##

NAME		=	scroller

SRCS		=	main.c				\
			scroller.c			\
			window.c			\
			effects.c			\
			test_effect.c			\
			mini_my.c			\
			effects/scrolling_text.c	\
			effects/parallax_scrolling.c	\
			effects/tracker.c		\
			effects/image.c			\
			effects/image_waves.c
OBJS		=	$(SRCS:.c=.o)
INCS		=	scroller.h		\
			effects.h		\
			scrolling_text.h	\
			parallax_scrolling.h	\
			tracker.h		\
			image.h
LIBS		=	-lm -lc_graph_prog_full

SRCSDIR		=	src
SUBDIRS		=	effects
INCSDIR		=	include
OBJSDIR		=	obj
LIBSDIRS	=	lib

CC		=	gcc
CFLAGS		=	-c -I$(INCSDIR) -O2 -W -Wall -Wextra -pedantic
LDFLAGS		=	$(addprefix -L,$(LIBSDIRS)) $(LIBS)

MKDIR		=	mkdir -p
RM		=	rm -rf

all: $(NAME)

$(NAME): $(addprefix $(OBJSDIR)/,$(OBJS))
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJSDIR):
	$(MKDIR) $@

$(addprefix $(OBJSDIR)/,$(SUBDIRS)):
	$(MKDIR) $@

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c $(addprefix $(INCSDIR)/,$(INCS)) | $(OBJSDIR) $(addprefix $(OBJSDIR)/,$(SUBDIRS))
	$(CC) $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

##
## Makefile for scroller in /home/arthur.melin/Code/scroller
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.eu>
##
## Started on  Sat Apr  1 12:34:59 2017 Arthur Melin
## Last update Sat Apr  1 18:01:21 2017 Arthur Melin
##

NAME		=	scroller

SRCS		=	main.c				\
			scroller.c			\
			window.c			\
			effects.c			\
			test_effect.c			\
			mini_my.c			\
			effects/scrolling_text.c
OBJS		=	$(SRCS:.c=.o)
INCS		=	scroller.h	\
			effects.h	\
			scrolling_text.h
LIBS		=	-lm -lcsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system

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

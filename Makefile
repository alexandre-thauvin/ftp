##
## Makefile for  in /home/thauvi_a/rendu/tek2/trade
##
## Made by Alexandre Thauvin
## Login   <thauvi_a@epitech.net>
##
## Started on  Mon Feb 27 11:44:29 2017 Alexandre Thauvin
## Last update Fri Mar  3 15:02:48 2017 Alexandre Thauvin
##

NAME		= server

SRCS		= src/main.c

OBJS		= $(SRCS:.c=.o)

GXX		= gcc

RM		= rm -rf

CXXFLAGS	= -Wall -Werror -W -Wextra -I ./includes


$(NAME): $(OBJS)
	$(GXX) $(OBJS) -o $(NAME) $(CXXFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) sources/*~
	$(RM) sources/*#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:         all clean fclean re

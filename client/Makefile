##
## Makefile for  in /home/thauvi_a/rendu/tek2/trade
##
## Made by Alexandre Thauvin
## Login   <thauvi_a@epitech.net>
##
## Started on  Mon Feb 27 11:44:29 2017 Alexandre Thauvin
## Last update Thu May 11 15:58:11 2017 Alexandre Thauvin
##

NAME		= client

SRCS		= main.c

OBJS		= $(SRCS:.c=.o)

GCC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Werror -W -Wextra -I ../includes

$(NAME): $(OBJS)
	$(GCC) $(OBJS) -o $(NAME) $(CFLAGS)

all: $(NAME)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) *#

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:         all clean fclean re

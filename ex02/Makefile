# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 14:32:42 by junghwle          #+#    #+#              #
#    Updated: 2023/12/24 01:33:23 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ex02

SRCDIR=.
OBJDIR=objs
SRCS=main.cpp Fixed.cpp
OBJS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I.
CC=g++
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD
EXTRAFLAGS=-std=c++98
LIBRARIES=

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS) Makefile
	$(CC) $(CFLAGS) $(EXTRAFLAGS) -o $@ $(OBJS) $(LIBRARIES)
	echo "(CPP02-EX02)COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(EXTRAFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(CPP02-EX02)COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:

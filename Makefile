# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastilh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 10:20:32 by vcastilh          #+#    #+#              #
#    Updated: 2021/08/23 16:15:43 by vcastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -I. -c
CC = clang-11
HEADERFILES = libft.h 
FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \

OBJFILES = $(FILES:%.c=%.o)

all: $(NAME) 

$(NAME): $(OBJFILES) $(HEADERFILES)
	ar rcs $@ $^
	
$(OBJFILES): $(FILES)
	$(CC) $(CFLAGS) $^

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: clean fclean all re

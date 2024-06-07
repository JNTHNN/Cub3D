# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 12:51:23 by gdelvign          #+#    #+#              #
#    Updated: 2024/04/30 10:42:57 by gdelvign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 

CC			= cc -g -O0
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs

BUILD_DIR  	:= ./.build/
SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
				ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putuint.c \
				ft_putnbrbase.c ft_putaddress.c ft_putulong.c ft_printchar.c \
				ft_printstr.c ft_printnbr.c ft_printuint.c ft_printaddress.c \
				ft_printhex.c get_next_line.c get_next_line_utils.c

OBJS		:= $(SRCS:%.c=$(BUILD_DIR)%.o)
DEPS        := $(OBJS:.o=.d)

all: 		$(NAME)

-include $(DEPS)
$(BUILD_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(LIB)	$(NAME) $(OBJS)
	@mv $(NAME) $(BUILD_DIR)

.c.o: 		
	@$(CC) $(CFLAGS) -c $< -o $@

clean:		 
	@$(RM) -r $(BUILD_DIR)

fclean:	clean
	@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
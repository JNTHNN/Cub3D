# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelvign <gdelvign@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 14:06:04 by jgasparo          #+#    #+#              #
#    Updated: 2024/07/01 11:54:28 by gdelvign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
# 							Name of the executable							   #
# **************************************************************************** #

NAME			:= cub3d

# **************************************************************************** #
# 								  File paths								   #
# **************************************************************************** #

LIBFT_BUILD 	:= ./libft/.build/
LIBFT_DIR		:= ./libft/
INC_DIR 		:= ./includes/
MLX_DIR			:= ./minilibx/
SRC_DIR			:= ./sources/
BUILD_DIR  		:= ./.build/

# **************************************************************************** #
# 							  Librairies needed								   #
# **************************************************************************** #

LIBFT 			:= libft.a
MLX   			:= libmlx.a

# **************************************************************************** #
# 							  	Source files								   #
# **************************************************************************** #

SRC_FILES			:= main
UTILS_SRC			:= error free size atoi init temp
PARSER_SRC			:= parsing data colors textures map player wall
PARSER_UTILS_SRC	:= map_utils fd_utils
GRAPHICS_SRC		:= windows controls 
UTILS_SRC			:= error free  size  atoi init temp
PARSER_SRC			:= parsing info colors textures map player
PARSER_UTILS_SRC	:= map_utils
GRAPHICS_SRC		:= windows controls blur
GRAPHICS_UTILS_SRC	:= init settings


SRC				:= $(addprefix $(SRC_DIR),$(addsuffix .c, $(SRC_FILES)))
SRC 			+= $(addprefix $(SRC_DIR)parser/, $(addsuffix .c, $(PARSER_SRC)))
SRC				+= $(addprefix $(SRC_DIR)parser/utils/, $(addsuffix .c, $(PARSER_UTILS_SRC)))
SRC				+= $(addprefix $(SRC_DIR)utils/, $(addsuffix .c, $(UTILS_SRC)))
SRC				+= $(addprefix $(SRC_DIR)graphics/, $(addsuffix .c, $(GRAPHICS_SRC)))
SRC				+= $(addprefix $(SRC_DIR)graphics/utils/, $(addsuffix .c, $(GRAPHICS_UTILS_SRC)))



# **************************************************************************** #
# 							  	Object files								   #
# **************************************************************************** #

OBJS 			:= $(SRC:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)
DEPS        	:= $(OBJS:.o=.d)

# **************************************************************************** #
# 							  Compilation flags								   #
# **************************************************************************** #

CC 				:= cc -g -O0
CFLAGS 			:= -Wall -Wextra -Werror
CPPFLAGS		:= -MMD -MP
READL			:= -L/usr/local/lib -I/usr/local/include
MLX_FLAGS		:= -lm -lft -lmlx -framework OpenGL -framework AppKit
DEBUG			:= -fsanitize=address

# **************************************************************************** #
# 							  	   Colors	    							   #
# **************************************************************************** #

GREEN 			= \033[0;32m
CYAN 			= \033[36;1m
YELLOW			= \033[33;1m
WHITE 			= \033[0m

# **************************************************************************** #
# 							  	   Rules	    							   #
# **************************************************************************** #


all : $(NAME)

-include $(DEPS)
$(BUILD_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ -I $(INC_DIR)

$(LIBFT_BUILD)$(LIBFT):
	@echo "\n$(CYAN)Generating Libft...$(WHITE)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft created!$(WHITE)\n"

$(MLX_DIR)$(MLX):
	@echo "$(CYAN)Generating MiniLibX...$(WHITE)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN)MiniLibX created!$(WHITE)\n"

$(NAME): $(OBJS) $(LIBFT_BUILD)$(LIBFT) $(MLX_DIR)$(MLX)
	@echo "${CYAN}Generating game...${WHITE}"
	@$(CC) $(DEBUG) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -L $(LIBFT_BUILD) -L $(MLX_DIR) $(READL) -o $(NAME)
	@echo "${GREEN}Compilation successful ! Let's play 😏${WHITE}"

clean :
	@echo "\n${CYAN}Deleting object files...${WHITE}"
	@$(RM) -r $(BUILD_DIR)
	@make clean -C $(LIBFT_DIR)
	@find $(MLX_DIR) -name "*.o" -type f -delete
	@echo "$(GREEN)Object files were deleted.$(WHITE)\n"
	
fclean : clean
	@echo "$(CYAN)Cleaning all...$(WHITE)"
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "$(GREEN)$(MLX) was deleted.$(WHITE)"
	@echo "$(GREEN)$(LIBFT) was deleted.$(WHITE)"
	@$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) was deleted.$(WHITE)"

re : fclean all

.PHONY : all clean fclean re

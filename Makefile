# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 12:24:06 by noam              #+#    #+#              #
#    Updated: 2024/05/28 13:11:23 by nvoltair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
FLAGS = -Wall -Wextra -Werror
MV_UTLS_PTH = utils/moving_utils/
ND_UTLS_PTH = utils/node_utils/
STR_UTLS_PTH = utils/str_utils/
INSERT_PTH = insert_to_a/

SRC = $(MV_UTLS_PTH)push_to.c $(MV_UTLS_PTH)rr_rrr_ss.c \
		$(MV_UTLS_PTH)swap_rotate_revrotate.c \
		$(ND_UTLS_PTH)node_utils.c $(ND_UTLS_PTH)go_to_min_node.c \
		$(ND_UTLS_PTH)stack_comparing_utils.c \
		$(STR_UTLS_PTH)ft_atol.c $(STR_UTLS_PTH)is_digit.c \
		$(STR_UTLS_PTH)count_args.c $(STR_UTLS_PTH)ft_split.c \
		$(STR_UTLS_PTH)free_array.c\
		$(INSERT_PTH)find_cheapest.c $(INSERT_PTH)rotate_before_insert.c \
		$(INSERT_PTH)rotation_instructions.c \
		utils/check_input.c utils/error.c start_sorting.c \
		int_array_sorted.c sort_algo.c
		
SRCS = $(SRC) push_swap.c

BONUS_PTH = bonus/
BONUS_SRCS = $(SRC) $(BONUS_PTH)get_next_line/get_next_line.c \
			$(BONUS_PTH)get_next_line/get_next_line_utils.c \
			$(BONUS_PTH)bonus_utils/check_read_line.c \
			$(BONUS_PTH)bonus_utils/error_ko.c $(BONUS_PTH)bonus_utils/lst_len.c \
			$(BONUS_PTH)bonus_utils/ft_strncmp.c \
			$(BONUS_PTH)checker.c $(BONUS_PTH)execute_commands.c \
			$(BONUS_PTH)read_and_exec.c 

OBJ_DIR = objs/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ))
OBJ_DIR_BONUS = objs_bonus/
OBJ_BONUS = $(BONUS_SRCS:.c=.o)
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS),$(OBJ_BONUS))

$(NAME) : $(OBJS)
	cc $(FLAGS) -o $@ $(OBJS)
	
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	cc -c $(FLAGS) -o $@ $<
	
$(BONUS_NAME) : $(OBJS_BONUS)
	cc $(FLAGS) -o $@ $(OBJS_BONUS)

$(OBJ_DIR_BONUS):
	mkdir $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)%.o: %.c
	mkdir -p $(dir $@)
	cc -c $(FLAGS) -o $@ $<




all : $(OBJ_DIR) $(NAME) bonus $(BONUS_NAME)

bonus : $(OBJ_DIR) $(OBJ_DIR_BONUS) $(BONUS_NAME)

.PHONY : all clean fclean re bonus

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)	

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	rm -f a.out

re : fclean all

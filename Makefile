# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noam <noam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 12:24:06 by noam              #+#    #+#              #
#    Updated: 2024/03/24 17:00:45 by noam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
MV_UTLS_PTH = utils/moving_utils/
ND_UTLS_PTH = utils/node_utils/
STR_UTLS_PTH = utils/str_utils/
INSERT_PTH = insert_to_a/
# PRE_SORT_PTH = pre_sort_to_b/

SRCS = $(MV_UTLS_PTH)push_to.c $(MV_UTLS_PTH)rr_rrr_ss.c \
		$(MV_UTLS_PTH)swap_rotate_revrotate.c \
		$(ND_UTLS_PTH)node_utils.c $(ND_UTLS_PTH)go_to_min_node.c \
		$(ND_UTLS_PTH)stack_comparing_utils.c \
		$(STR_UTLS_PTH)ft_atol.c $(STR_UTLS_PTH)is_digit.c \
		$(STR_UTLS_PTH)count_args.c $(STR_UTLS_PTH)ft_split.c \
		$(STR_UTLS_PTH)ft_strncmp.c \
		$(INSERT_PTH)find_cheapest.c $(INSERT_PTH)rotate_before_insert.c \
		$(INSERT_PTH)rotation_instructions.c \
		utils/check_input.c utils/error.c \
		int_array_sorted.c sort_algo.c push_swap.c

OBJ_DIR = objs/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR),$(OBJ))

$(NAME) : | $(OBJ_DIR) $(OBJS)
	cc $(FLAGS) -o $@ $(OBJS)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	cc -c $(FLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# $(NAME) : $(OBJS)
# 	ar rcs $@ $^
# 	ranlib $@

all : $(OBJ_DIR) $(NAME)

.PHONY : all clean fclean re
clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f a.out

re : fclean all

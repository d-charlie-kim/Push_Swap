# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dokkim <dokkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 01:25:29 by dokkim            #+#    #+#              #
#    Updated: 2021/06/11 01:25:30 by dokkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap
# NAME_BONUS = checker

SRCS = push_swap.c \
		arg_count.c \
		arg_error_check.c \
		arg_parse.c \
		function_push.c \
		function_reverse_rotate.c \
		function_rotate.c \
		function_swap.c \
		sort_chunks.c \
		sort_pivot.c \
		sort_three_nor.c \
		sort_three.c \
		sort_two_or_three.c \
		sort_utils.c \
		utils_error_or_done.c \
		utils_lst.c \
		utils.c \

OBJS = $(SRCS:.c=.o)

# SRCS_BONUS = checker.c \
# 		arg_count.c \
# 		arg_error_check.c \
# 		arg_parse.c \
# 		function_push.c \
# 		function_reverse_rotate.c \
# 		function_rotate.c \
# 		function_swap.c \
# 		sort_chunks.c \
# 		sort_pivot.c \
# 		sort_three_nor.c \
# 		sort_three.c \
# 		sort_two_or_three.c \
# 		sort_utils.c \
# 		utils_error_or_done.c \
# 		utils_lst.c \
# 		utils.c \

# OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o : 
	$(CC) $(CFLAGS) -c -o $@ $<

all : $(NAME)
$(NAME) : $(OBJS)
		ar -rcs $@ $^


clean : 
		rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
		rm -rf $(NAME) $(NAME_BONUS)

re : fclean all

# bonus : $(OBJS) $(OBJS_BONUS)
# 		ar rc $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS)

.PHONY : bonus all clean fclean re
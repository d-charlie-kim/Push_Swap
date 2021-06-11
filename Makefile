NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# LIBFLAGS = -L ./include/libft -lft

SRCS_PARSE = $(addprefix ./arg/, \
			 arg_count.c \
			 arg_error_check.c \
			 arg_parse.c \
			 )

SRCS_FUNCTION = $(addprefix ./function/, \
				 function_push.c \
				 function_reverse_rotate.c \
				 function_rotate.c \
				 function_swap.c \
			 	 )

SRCS_SORT = $(addprefix ./sort/, \
			sort_chunks.c \
			sort_four_five.c \
			sort_pivot.c \
			sort_three_nor.c \
			sort_three.c \
			sort_two_or_three.c \
			sort_utils.c \
			)

SRCS_CHECKER = $(addprefix ./bonus_checker/, \
			  bonus_checker.c \
			   )

SRCS_GNL = $(addprefix ./get_next_line/, \
		   get_next_line.c \
	   	   get_next_line_utils.c \
		   )

SRCS_UTILS = $(addprefix ./utils/, \
			utils.c \
			utils_error_or_done.c \
			utils_lst.c \

SRCS = ./push_swap.c \
	   $(SRCS_PARSE) \
	   $(SRCS_FUNCTION) \
   	   $(SRCS_SORT) \
	   $(SRCS_UTILS) \

BONUS_SRCS = ./checker.c \
			 $(SRCS_PARSE) \
			 $(SRCS_GNL) \
			 $(SRCS_FUNCTION) \
			 $(SRCS_UTILS) \
			 $(SRCS_CHECKER) \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

all : $(NAME)

clean :
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

bonus : all $(BONUS_NAME)

re : fclean all

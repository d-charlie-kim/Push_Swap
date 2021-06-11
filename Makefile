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

SRCS_OPERATION = $(addprefix ./function/, \
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

SRCS_CHECKER = $(addprefix ./checker/, \
			   checker.c \
			   )

SRCS_GNL = $(addprefix ./include/get_next_line/, \
		   get_next_line.c \
	   	   get_next_line_utils.c \
		   )

SRCS = ./push_swap.c \
	   $(SRCS_PARSE) \
	   $(SRCS_OPERATION) \
   	   $(SRCS_SORT) \
   	   $(SRCS_CHECKER) \

BONUS_SRCS = ./checker.c \
			 $(SRCS_PARSE) \
			 $(SRCS_GNL) \
			 $(SRCS_OPERATION) \
			 $(SRCS_CHECKER) \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME) : $(OBJS)
	# make -C ./include/libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	# make -C ./include/libft
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

all : $(NAME)

clean :
	# make -C ./include/libft clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	# make -C ./include/libft fclean
	rm -rf $(NAME) $(BONUS_NAME)

bonus : all $(BONUS_NAME)

re : fclean all

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# LIBFLAGS = -L ./include/libft -lft

SRCS_PARSE = $(addprefix ./parsing/, \
			 parsing.c \
			 validate.c \
			 linked_list.c \
			 )

SRCS_OPERATION = $(addprefix ./operation/, \
				 swap.c \
				 push.c \
				 rotate.c \
				 reverse_rotate.c \
			 	 )

SRCS_SORT = $(addprefix ./sort/, \
			sort.c \
			sort_2_to_3.c \
			sort_4_to_5.c \
			recursive.c \
			recursive_util.c \
			)

SRCS_CHECKER = $(addprefix ./check/, \
			   check.c \
			   )

SRCS_GNL = $(addprefix ./include/get_next_line/, \
		   get_next_line.c \
	   	   get_next_line_utils.c \
		   )

SRCS = ./parsing/push_swap.c \
	   $(SRCS_PARSE) \
	   $(SRCS_OPERATION) \
   	   $(SRCS_SORT) \
   	   $(SRCS_CHECKER) \

BONUS_SRCS = ./check/checker_main.c \
			 $(SRCS_PARSE) \
			 $(SRCS_GNL) \
			 $(SRCS_OPERATION) \
			 $(SRCS_CHECKER) \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME) : $(OBJS)
	# make -C ./include/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	# make -C ./include/libft
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFLAGS) -o $(BONUS_NAME)

all : $(NAME)

clean :
	# make -C ./include/libft clean
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean : clean
	# make -C ./include/libft fclean
	rm -rf $(NAME) $(BONUS_NAME)

bonus : all $(BONUS_NAME)

re : fclean all

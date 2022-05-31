NAME		= push_swap

SRCS_DIR	= srcs/
HEAD_DIR	= includes/
BUILD_DIR	= build/

SRCS_FILES	= main.c						\
			  hash/contains.c				\
			  hash/hash.c					\
			  hash/insert.c					\
			  hash/resize.c					\
			  libft/atol.c					\
			  libft/atoi.c					\
			  libft/malloc.c				\
			  libft/memset.c				\
			  libft/put_fd.c				\
			  push_swap/exec_ps.c			\
			  push_swap/exec_r.c			\
			  push_swap/exec_rr.c			\
			  push_swap/insert_pos.c		\
			  push_swap/markup.c			\
			  push_swap/parse.c				\
			  push_swap/push_swap.c			\
			  push_swap/set_index.c			\
			  stack/new.c					\
			  stack/pop.c					\
			  stack/push.c					\
			  stack/rotate.c				\
			  stack/stack.c					\
			  stack/swap.c					

OBJS_FILES	= $(SRCS_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(BUILD_DIR), $(OBJS_FILES))
DEPS		= $(OBJS:.o=.d)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -g

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c $(BUILD_DIR)%.d
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEAD_DIR) -o $@ -c $<

$(BUILD_DIR)%.d: ;

$(DEPS):
-include $(wildcard $(DEPS))

clean: 
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re

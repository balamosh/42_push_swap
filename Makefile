NAME		= push_swap
B_NAME		= checker

SRCS_DIR	= srcs/
HEAD_DIR	= includes/
BUILD_DIR	= build/

SRCS_FILES	= push_swap/main.c				\
			  hash/contains.c				\
			  hash/hash.c					\
			  hash/insert.c					\
			  hash/resize.c					\
			  libft/abs.c					\
			  libft/atol.c					\
			  libft/lsign.c					\
			  libft/atoi.c					\
			  libft/malloc.c				\
			  libft/max.c					\
			  libft/memset.c				\
			  libft/min.c					\
			  libft/put_fd.c				\
			  push_swap/allign.c			\
			  push_swap/atob.c				\
			  push_swap/btoa.c				\
			  push_swap/exec_ps.c			\
			  push_swap/exec_r.c			\
			  push_swap/exec_rr.c			\
			  push_swap/exec.c				\
			  push_swap/insert_pos.c		\
			  push_swap/markup_mode.c		\
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

B_SRCS_FILES = checker/main.c				\
			   hash/contains.c				\
			   hash/hash.c					\
			   hash/insert.c				\
			   hash/resize.c				\
			   libft/abs.c					\
			   libft/atol.c					\
			   libft/lsign.c				\
			   libft/atoi.c					\
			   libft/malloc.c				\
			   libft/max.c					\
			   libft/memset.c				\
			   libft/min.c					\
			   libft/put_fd.c				\
			   push_swap/allign.c			\
			   push_swap/atob.c				\
			   push_swap/btoa.c				\
			   push_swap/exec_ps.c			\
			   push_swap/exec_r.c			\
			   push_swap/exec_rr.c			\
			   push_swap/exec.c				\
			   push_swap/insert_pos.c		\
			   push_swap/markup_mode.c		\
			   push_swap/markup.c			\
			   push_swap/parse.c			\
			   push_swap/push_swap.c		\
			   push_swap/set_index.c		\
			   push_swap/sorted.c			\
			   stack/new.c					\
			   stack/pop.c					\
			   stack/push.c					\
			   stack/rotate.c				\
			   stack/stack.c				\
			   stack/swap.c					\
			   gnl/gnl.c					\
			   gnl/gnl_utils.c

OBJS_FILES	= $(SRCS_FILES:.c=.o)
B_OBJS_FILES = $(B_SRCS_FILES:.c=.o)

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS		= $(addprefix $(BUILD_DIR), $(OBJS_FILES))
DEPS		= $(OBJS:.o=.d)

B_SRCS 		= $(addprefix $(SRCS_DIR), $(B_SRCS_FILES))
B_OBJS		= $(addprefix $(BUILD_DIR), $(B_OBJS_FILES))
B_DEPS		= $(B_OBJS:.o=.d)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -MMD -g

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(B_NAME): $(B_OBJS)
	$(CC) $(B_OBJS) -o $(B_NAME)

$(BUILD_DIR)%.o: $(SRCS_DIR)%.c $(BUILD_DIR)%.d
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEAD_DIR) -o $@ -c $<

$(BUILD_DIR)%.d: ;

$(DEPS):
-include $(wildcard $(DEPS))

$(B_DEPS):
-include $(wildcard $(B_DEPS))

clean: 
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(B_NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re

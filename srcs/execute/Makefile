CC=cc
CFLAGS=-Wall -Wextra -Werror
NAME=minishell
LIB=libft/libft.a
SRCS=main.c envset.c envutil.c
BSRCS=main_bonus.c

.PHONY: all clean fclean re bonus

all : $(NAME)

$(NAME) : manda_flag

manda_flag : $(SRCS) $(LIB)	
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -L ./libft -lft
	touch manda_flag

bonus : bonus_flag

bonus_flag : $(BSRCS) $(LIB)
	rm -f $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(BSRCS) -L ./libft -lft
	touch bonus_flag
	touch manda_flag

$(LIB) :
	make -C ./libft

clean :
	make -C ./libft fclean
	rm -f manda_flag
	rm -f bonus_flag

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

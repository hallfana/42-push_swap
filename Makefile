NAME = push_swap

SRC = algo/redix.c \
	algo/smol.c \
	instruction/ps_pa.c \
	instruction/ps_pb.c \
	instruction/ps_ra.c \
	instruction/ps_rb.c \
	instruction/ps_rr.c \
	instruction/ps_rra.c \
	instruction/ps_rrb.c \
	instruction/ps_rrr.c \
	instruction/ps_sa.c \
	instruction/ps_sb.c \
	instruction/ps_ss.c \
	instruction/utils.c \
	utils/ft_check_args.c \
	utils/ft_list_utils1.c \
	utils/ft_list_utils2.c \
	utils/ft_utils.c \
	main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make libft
	$(CC) $(CFLAGS) $(SRC) ./includes/libft.a -g -o $(NAME)

clean:
	make -C ./includes clean
	@true

fclean: clean
	make -C ./includes fclean
	rm -f $(NAME)

re: fclean all

libft:
	make -C ./includes

.PHONY: all clean fclean re libft

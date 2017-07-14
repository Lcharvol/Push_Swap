NAME = checker

SRCS = 	main.c \
				tools.c \

INC = ../../includes/ft_push_swap.h

FLAGS = -Wall -Werror -Wextra -I./includes

OBJ = $(addprefix ./, $(SRCS:.c=.o))

all: ../../libft $(NAME)

libft:
	@make -C ../../libft

$(NAME): ../../libft $(INC) $(OBJ)
	@make -C ../../libft
	@gcc -o $(NAME) $(FLAGS) $(OBJ) -L ../../libft -lft

clean:
	make clean -C ../../libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C ../../libft
	rm -f $(NAME)

re: fclean all

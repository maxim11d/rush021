NAME = rush-02

SRC_FILES = dico.c fichier_norminette.c list.c main.c parser.c parser2.c putnbr.c string.c

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)
$(NAME) : $(SRC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re
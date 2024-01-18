NAME= philo
CC= gcc
FLAGS= -Wall -Wextra -Werror -pthread -fsanitize=thread
SOURCE= *.c
OBJECT= $(SOURCE:.c=.o)
RM= rm -rf

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -o $(NAME)

$(OBJECT):
	$(CC) $(FLAGS) -c $(SOURCE)

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all
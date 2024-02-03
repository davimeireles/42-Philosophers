NAME= philo
CC= cc
FLAGS= -Wall -Wextra -Werror -g -pthread -fsanitize=thread
SOURCE= date_utils.c main.c philo_utils.c routine.c thread_utils.c utils.c validate_input.c
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
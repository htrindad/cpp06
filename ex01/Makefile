NAME = Serializer
SRC = Serializer.cpp main.cpp
CPPFLAGS = -Wall -Werror -Wextra -O3
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

NAME = typeIdent
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CPPFLAGS = -Wall -Werror -Wextra -O3

%o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

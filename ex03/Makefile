CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -Wshadow 
CXXFLAGS += -Wconversion -Wunreachable-code
CXXFLAGS += -Wno-shadow
# CXXFLAGS += -pedantic

# -O0: Disables optimization to make debugging easier..
CXXFLAGS += -g3 -O0
# Uncomment this line to turn off debug flags
# CXXFLAGS += -DNDEBUG


CXX = c++

NAME = diamondTrap 
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# This is to recompile the .o files if the makefile changes
%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

run: all
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && $(NAME) $(ARGS)

valrun: all
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes $(NAME) $(ARGS)

.PHONY : all clean fclean re
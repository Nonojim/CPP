FILES		=	main.cpp		\
				Dog.cpp			\
				Animal.cpp		\
				Cat.cpp

NAME		= DiamondTrap

RM			= rm -rf

CC			= c++

CFLAGS		= -Wall -Wextra -Werror -std=c++98 -g

OBJ		= $(addprefix $(OBJDIR)/, $(FILES:.cpp=.o))

OBJDIR = obj

all:		${NAME}

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[1;32m" "Cleaning .o \033[0m"
	@$(RM) $(OBJDIR)

fclean: clean
	@echo "\033[1;32m" "Cleaning program \033[0m"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
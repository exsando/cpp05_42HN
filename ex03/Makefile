# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 08:21:24 by asando            #+#    #+#              #
#    Updated: 2026/09/20 12:23:15 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := c++
CPP_FLAG := c++98
FLAGS := -Wall -Wextra -Werror -std=$(CPP_FLAG)

INCLUDE := .
SRC_DIR := .
OBJ_DIR := obj

SRC_FILES := AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
			 RobotomyRequestForm.cpp PresidentialPardonForm.cpp \
			 Intern.cpp main.cpp

SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

NAME := Intern

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR) ./*_shrubbery

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

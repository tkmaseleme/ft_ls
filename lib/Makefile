# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaselem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 16:27:01 by tmaselem          #+#    #+#              #
#    Updated: 2018/11/01 10:27:12 by tmaselem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \x1b[31m
GREEN = \x1b[32m
CYAN = \x1b[36m
NC = \033[0m
LOAD1 = "${RED}......(30%)\r\c${NC}"
LOAD2 = "${RED}..........(65%)\r\c${NC}"
LOAD3 = "${GREEN}................(100%)\r\c${NC}"


NAME = libft.a
H_PATH = includes/libft.h
S_PATH = srcs/
E_FLAGS = -Wall -Werror -Wextra
OPT_FLAGS = -c -I $(H_PATH)
SRC = $(S_PATH)ft_putchar.c $(S_PATH)ft_putstr.c $(S_PATH)ft_strlen.c \
	  $(S_PATH)ft_putnbr.c $(S_PATH)ft_isdigit.c $(S_PATH)ft_memset.c\
	  $(S_PATH)ft_atoi.c $(S_PATH)ft_memcpy.c $(S_PATH)ft_bzero.c\
	  $(S_PATH)ft_memccpy.c $(S_PATH)ft_memmove.c $(S_PATH)ft_memchr.c \
	  $(S_PATH)ft_memcmp.c $(S_PATH)ft_strcat.c $(S_PATH)ft_strchr.c \
	  $(S_PATH)ft_strcmp.c $(S_PATH)ft_strcpy.c $(S_PATH)ft_strncat.c \
	  $(S_PATH)ft_strncpy.c $(S_PATH)ft_strdup.c $(S_PATH)ft_strlcat.c \
	  $(S_PATH)ft_strrchr.c $(S_PATH)ft_strstr.c $(S_PATH)ft_strnstr.c \
	  $(S_PATH)ft_strncmp.c $(S_PATH)ft_isalpha.c $(S_PATH)ft_isalnum.c \
	  $(S_PATH)ft_isascii.c $(S_PATH)ft_isprint.c $(S_PATH)ft_toupper.c\
	  $(S_PATH)ft_tolower.c $(S_PATH)ft_memalloc.c $(S_PATH)ft_memdel.c \
	  $(S_PATH)ft_strnew.c $(S_PATH)ft_strdel.c $(S_PATH)ft_strclr.c \
	  $(S_PATH)ft_striter.c $(S_PATH)ft_striteri.c $(S_PATH)ft_strmap.c\
	  $(S_PATH)ft_strmapi.c $(S_PATH)ft_winfns.c $(S_PATH)ft_unsfns.c\
	  $(S_PATH)ft_strequ.c $(S_PATH)ft_strnequ.c $(S_PATH)ft_strsub.c \
	  $(S_PATH)ft_strjoin.c $(S_PATH)ft_txtfns.c $(S_PATH)ft_ptrfns.c\
	  $(S_PATH)ft_iswhitespace.c $(S_PATH)ft_strtrim.c $(S_PATH)ft_itoa.c \
	  $(S_PATH)ft_strsplit.c $(S_PATH)ft_strndup.c $(S_PATH)ft_printf.c\
	  $(S_PATH)ft_putendl.c $(S_PATH)ft_putchar_fd.c $(S_PATH)ft_putstr_fd.c\
	  $(S_PATH)ft_putendl_fd.c $(S_PATH)ft_putnbr_fd.c $(S_PATH)get_next_line.c\
	  $(S_PATH)ft_lstnew.c  $(S_PATH)ft_lstdelone.c $(S_PATH)ft_lstdel.c\
	  $(S_PATH)ft_lstadd.c $(S_PATH)ft_lstiter.c $(S_PATH)ft_lstmap.c\
	  $(S_PATH)ft_putchar_error.c $(S_PATH)ft_putstr_error.c $(S_PATH)ft_getopt.c\
	  $(S_PATH)ft_strcasecmp.c $(S_PATH)ft_octfns.c $(S_PATH)ft_fnscall.c\
	  $(S_PATH)ft_dgtfns.c $(S_PATH)ft_hexfns.c $(S_PATH)ft_lstpshbck.c\
	  $(S_PATH)error.c $(S_PATH)space_stuff.c $(S_PATH)hand_strout.c $(S_PATH)ft_output.c\

OBJ = $(SRC:$(S_PATH)%.c=%.o)

$(NAME):
	@echo "${CYAN}Create Object Files${NC}"
	@echo $(LOAD1)
	@echo "\n"
	@gcc $(E_FLAGS) $(OPT_FLAGS) $(SRC)
	@echo $(LOAD2)
	@echo "\n"
	@ar rcs $(NAME) $(OBJ)
	@echo $(LOAD3)
	@echo "\n"

all: $(NAME)

clean:
	@echo "${CYAN}Removing Object Files${NC}"
	@echo $(LOAD1)
	@echo "\n"
	@echo $(LOAD2)
	@echo "\n"
	@rm -f $(OBJ)
	@echo $(LOAD3)
	@echo "\n"

fclean: clean
	@echo "${CYAN}Removing libft.a${NC}"
	@echo $(LOAD1)
	@echo "\n"
	@echo $(LOAD2)
	@echo "\n"
	@rm -f $(NAME)
	@echo $(LOAD3)
	@echo "\n"

re: fclean all


MAGENTA = \x1b[35m
CYAN = \x1b[36m
RED = \x1b[31m
GREEN = \x1b[32m
NC = \033[0m
LOAD1 = "${RED}......(30%)\r\c${NC}"
LOAD2 = "${RED}..........(65%)\r\c${NC}"
LOAD3 = "${GREEN}................(100%)\r\c${NC}"

NAME = ft_ls
S_PATH = srcs/
E_FLAGS = -Wall -Werror -Wextra
LIBFT = lib/
SRC = $(S_PATH)initialize.c $(S_PATH)main.c $(S_PATH)big_r.c \
	  $(S_PATH)error_handling.c $(S_PATH)files.c\
	  $(S_PATH)helpers.c $(S_PATH)memory.c $(S_PATH)lists.c $(S_PATH)printf_stuf.c \
	  $(S_PATH)printf_stuff.c $(S_PATH)sorting.c \


#OBJ = $(SRC:$(S_PATH)%.c=%.o)

$(NAME): 
		@echo "${MAGENTA}Creating $(NAME) Libft Files${NC}"
		@make -C lib/
		@echo $(LOAD1)
		@sleep 0.1
		@echo "\n"
		@gcc $(E_FLAGS) $(SRC) -o $(NAME) $(LIBFT)libft.a
		@sleep 0.1
		@echo $(LOAD2)
		@echo "\n"
		@sleep 0.1
		@echo $(LOAD3)
		@echo "\n"

all : $(NAME)

clean:
	@make -C lib/ clean
	@rm -rf $(OBJ)
	@echo "${MAGENTA}Removing ft_ls Objects...${NC}"
	@sleep 0.1
	@echo $(LOAD2)
	@echo "\n"
	@echo "${MAGENTA}Almost done!${NC}"
	@sleep 0.1
	@echo $(LOAD3)
	@echo "\n"

fclean:
	@make -C lib/ fclean
	@echo "${MAGENTA}Removing ft_ls ${NC}"
	@sleep 0.1
	@echo $(LOAD2)
	@echo "\n"
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)

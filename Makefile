NAME      = libftprintf.a
LIBFT     = libft/
INCLUDES  = include/
SRC_DIR   = src/
OBJ_DIR   = obj/
CC        = gcc
CC_FLAGS  = -Wall -Werror -Wextra -I
AR        = ar rcs

SRC_FILES = ft_print_char ft_print_hexa ft_print_nbr ft_print_ptr ft_print_str ft_print_uint ft_printf

SRC       = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ       = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJ_CACHE = .cache_exists

#####

all:			$(NAME)

$(NAME):		$(OBJ)
					@make -C $(LIBFT)
					@cp $(LIBFT)libft.a .
					@mv libft.a $(NAME)
					@$(AR) $(NAME) $(OBJ)
					@ranlib $(NAME)
					@echo "libftprintf compiled!"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_CACHE)
					@echo "Compiling $<"
					@$(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_CACHE):
					@mkdir -p $(OBJ_DIR)

clean:
					@rm -rf $(OBJ_DIR)
					@make clean -C $(LIBFT)
					@echo "ft_printf object files cleaned!"

fclean:			clean
					@rm -f $(NAME)
					@rm -f $(LIBFT)libft.a
					@echo "ft_printf executable files cleaned!"
					@echo "libft executable files cleaned!"

re:				fclean all
					@echo "Cleaned and rebuilt everything for ft_printf!"

.PHONY:			all clean fclean re
NAME := AICu

INCLUDE := includes/

MLX_DIR := minilibx

MLX_LIB := $(MLX_DIR)/libmlx_Linux.a

BUILD_DIR := .build

RM := rm -f

FLAGS := -Wall -Werror -Wextra

FINCLUDE := -I $(INCLUDE) -I $(MLX_DIR)

DEPFLAGS := -MMD -MP -g3

SRC_FILES := main.c\
	vectors.c\
	parsing.c\
	parse_user.c\
	algo.c\
	algo_utils.c\
	display_terminal.c\
	image_utils.c

OBJ := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
DEPS := $(patsubst %.o, %.d, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(FLAGS) $(FINCLUDE) $(OBJ) -L $(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(FLAGS) $(FINCLUDE) $(DEPFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	$(RM) $(OBJ) $(DEPS)
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)

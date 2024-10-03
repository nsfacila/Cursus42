#---------------- NAMES -----------------------

NAME_C = client

NAME_CB = client_bonus

NAME_S = server

NAME_SB = server_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

#-------------- LIBRARY -----------------------


PRINT_DIR = ./Printf

#PRINT_PATH = $(PRINT_DIR)/libftprintf.a

INCLUDES = -I /include

#-----------------SRC & OBJ-------------------

CLIENT_SRC = \
	client.c \
	utils/ft_atoi.c

SERVER_SRC = \
	server.c \
	utils/ft_atoi.c

CLIENT_BONUS_SRC = \
		client_bonus.c\
		utils/ft_atoi.c

SERVER_BONUS_SRC = \
		server_bonus.c\
		utils/ft_atoi.c

CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRC:.c=.o)
SERVER_BONUS_OBJS = $(SERVER_BONUS_SRC:.c=.o)

#------------------------RULES-----------------


all: $(NAME_C) $(NAME_S) #$(PRINT_PATH)

bonus: $(NAME_CB) $(NAME_SB) #$(PRINT_PATH)

# $(PRINT_PATH):
# 	@make -s -C $(PRINT_DIR)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME_C): $(CLIENT_OBJS) #$(PRINT_PATH)
		@make -C Printf
		@mv 	Printf/libftprintf.a .
		$(CC) $(CFLAGS) $(CLIENT_OBJS) libftprintf.a -o $(NAME_C)  
#$(PRINT_PATH)

$(NAME_S): $(SERVER_OBJS) $(PRINT_PATH)
		@make -C Printf
		@mv 	Printf/libftprintf.a .
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_S) $(SERVER_OBJS) libftprintf.a 
#$(PRINT_PATH)

$(NAME_CB): $(CLIENT_BONUS_OBJS) $(PRINT_PATH)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_CB) $(CLIENT_BONUS_OBJS) $(PRINT_DIR)

$(NAME_SB): $(SERVER_BONUS_OBJS) $(PRINT_PATH)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_SB) $(SERVER_BONUS_OBJS) $(PRINT_DIR)
# %.o: %.c
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean_printf:
	@make -s -C $(PRINT_DIR) clean

clean: clean_printf
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)

fclean_printf:
	@make -s -C $(PRINT_DIR) fclean

fclean: clean_printf clean
	rm -f $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_CS) 


re : fclean all

.PHONY : all clean fclean re bonus





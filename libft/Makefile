# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 13:21:57 by iwozniak          #+#    #+#              #
#    Updated: 2023/10/06 20:08:04 by iwozniak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES_PRINT = \
			ft_putchar \
			ft_putstr \
			ft_putnbr \
			ft_base_nbrlen \
			ft_u_base_nbrlen \
			ft_u_base_putnbr \
			ft_u_puthexa

CFILES_PRINTF = \
			ft_printf

CFILES_GNL = \
			get_next_line

CFILES_STRING = \
			ft_itoa \
			ft_putstr \
			ft_strchar \
			ft_strcpy \
			ft_strdup \
			ft_strjoin \
			ft_strlen \
			ft_strncmp

CFILES_LIST = \
			ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize \
			ft_lstlast

SRCS_DIR = ./srcs/
SRCS_DIR_PRINT = $(SRCS_DIR)print/
SRCS_DIR_PRINTF = $(SRCS_DIR)printf/
SRCS_DIR_GNL = $(SRCS_DIR)gnl/
SRCS_DIR_STRING = $(SRCS_DIR)str/
SRCS_DIR_LIST = $(SRCS_DIR)lst/

SRCS_PRINT = $(addprefix $(SRCS_DIR_PRINT), $(addsuffix .c, $(CFILES_PRINT)))
SRCS_PRINTF = $(addprefix $(SRCS_DIR_PRINTF), $(addsuffix .c, $(CFILES_PRINTF)))
SRCS_GNL = $(addprefix $(SRCS_DIR_GNL), $(addsuffix .c, $(CFILES_GNL)))
SRCS_STRING = $(addprefix $(SRCS_DIR_STRING), $(addsuffix .c, $(CFILES_STRING)))
SRCS_LIST = $(addprefix $(SRCS_DIR_LIST), $(addsuffix .c, $(CFILES_LIST)))

OBJS_PRINT = $(SRCS_PRINT:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
OBJS_GNL =  $(SRCS_GNL:.c=.o)
OBJS_STRING =  $(SRCS_STRING:.c=.o)
OBJS_LIST = $(SRCS_LIST:.c=.o)

HDR_NAMES = libft.h
HDR_FOLDER = ./includes/
HDRS = $(addprefix $(HDR_FOLDER), $(HDR_NAMES))
HDR_INC = $(addprefix -I, $(HDR_FOLDER))

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

$(NAME): $(OBJS_PRINT) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_STRING) $(OBJS_LIST) $(HDRS)
	$(AR) $@ $^

$(OBJS_PRINT):%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(HDR_INC) -o $@ $<

$(OBJS_PRINTF):%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(HDR_INC) -o $@ $<

$(OBJS_GNL):%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(HDR_INC) -o $@ $<

$(OBJS_STRING):%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(HDR_INC) -o $@ $<

$(OBJS_LIST):%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $(HDR_INC) -o $@ $<

all: $(NAME) $(HDRS)

clean:
	$(RM) $(OBJS_PRINT) $(OBJS_PRINTF) $(OBJS_GNL) $(OBJS_STRING) $(OBJS_LIST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

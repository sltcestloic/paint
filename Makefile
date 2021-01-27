# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 16:40:32 by lbertran          #+#    #+#              #
#    Updated: 2021/01/27 13:18:24 by lbertran         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC		= 	mode.c \
			paint.c \
			window.c \
			hook/mouse_hook.c \
			render/draw.c \
			render/frame.c \
			render/pixel.c \
			utils/point_util.c \
			utils/error.c \
			utils/rgbint.c
SRCS 	= $(addprefix srcs/, ${SRC})
OBJS	= ${SRCS:.c=.o}
INCS	= includes/paint.h
MLX		= ./mlx
NAME	= paint
LIBC	= ar rcs
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

srcs/%.o: srcs/%.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@ -I${INCS}

${NAME}: ${OBJS}
	@${MAKE} -C ${MLX}
	${CC} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS} libft/libft.a ${MLX}/libmlx.a

all: ${NAME}

clean:
	${MAKE} clean -C ${MLX}
	${RM} ${OBJS}
	${RM} a.out

fclean: clean
	${MAKE} clean -C ${MLX}
	${RM} ${NAME}

re: fclean all
	
.PHONY: all clean fclean re .c.o

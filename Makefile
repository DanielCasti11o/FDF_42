# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dacastil <dacastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 19:24:02 by dacastil          #+#    #+#              #
#    Updated: 2025/02/13 20:44:54 by dacastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Werror -Werror -lX11 -lXext a.c libmlx_Linux.a -fsanitize=address
EXEC = fdf
RM = rm -f
SCRS = fdf.c a.c get_next_line_bonus.c get_next_line_utils_bonus

all: $(EXEC)

$(EXEC):
	$(CC) $(CFLAGS)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmin <hmin@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 16:37:50 by hmin              #+#    #+#              #
#    Updated: 2020/03/02 23:10:27 by hmin             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	\
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			\
			ft_strlen.c \
			\
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			\
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			\
			ft_calloc.c \
			ft_strdup.c \
			\
			\
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

SRCS_B	=	\
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
LIBC	= ar -rcs
CFLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

bonus: $(NAME) $(OBJS_B)
	$(LIBC) $(NAME) $(OBJS_B)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) $(bonus)

re: fclean all

.PHONY: all bonus clean fclean re .c.o

# so:
# 	make fclean
# 	make
# 	$(CC) -shared -o libft.so $(OBJS) $(OBJS_B)

#####################################################
#! Sources BACKUP
#####################################################
# OBJS	= $(SRCS:.c=.o)
# OBJS_B	= $(SRCS_B:.c=.o)
# RM		= rm -f
# LIBC	= ar -rcs
# CCFLAGS	= -Wall -Wextra -Werror
# INCS	= .

# TEST_OUT = _TEST.out
# TEST_MAIN_OBJ = m.o

# .c.o :
# 	$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

# $(NAME): $(OBJS)
# 	$(LIBC) $(NAME) $(OBJS)

# all: $(NAME)

# bonus: $(NAME) $(OBJS_B)
# 	$(LIBC) $(NAME) $(OBJS_B)

# clean:
# 	$(RM) $(OBJS) $(OBJS_B) $(TEST_OUT) $(TEST_MAIN_OBJ)

# fclean: clean
# 	$(RM) $(NAME) $(bonus)

# re: fclean all


# ### test m.c

# test: $(TEST_OUT)

# $(TEST_OUT): $(TEST_MAIN_OBJ) $(NAME)
# 	$(CC) $(CCFLAGS) -o $@ $^
# 	./$(TEST_OUT)

# .PHONY: all bonus clean fclean re .c.o

#####################################################
#! BELOW CODES ARE NOT THE ANSWER!! IT'S JUST FOR TEST OF FUNCTIONS' VALIDITY!
#! FOR Libft-unit-test
#####################################################

#####################################################
#
#	CC = gcc
#	CCFLAGS = -Wall -Wextra -Werror
#	TARGET = _test.out
#	#################################################
#
#	# Just a dummy target to prioritize main.out file
#	# Mandatory if main.out: blah... is not on the top of all commands
#	all : $(TARGET)
#
#	# $@ == The file name of the target of the rule.
#	# $^ == The names of all the prerequisites.
#	# $< == The name of the first prerequisite.
#	$(TARGET) : $(OBJECTS)
#		$(CC) $(CCFLAGS) -o $@ $^
#
#	clean :
#		rm -f *.o
#
#	fclean : clean
#		rm -f $(TARGET)
#
#	re : fclean all
#
#	# Say that these commands are just rules
#	# Not a mandatory
#	.PHONY : all clean fclean re
#

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2015/12/02 10:30:47 by jlagneau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Variables
NAME      = libhashtable.a
DEB_NAME  = libhashtable_debug.a

# Libraries
FT_PATH   = libft/

# Directories
SRCS_PATH = src/
HEAD_PATH = include/

OBJS_PATH = .obj/
DEPS_PATH = .dep/

# Exec
CC        = gcc
AR        = ar
RM        = rm -rf

# Flags
CFLAGS    = -Wall -Wextra -Werror -pedantic
CPPFLAGS  = -I$(HEAD_PATH) -I$(FT_PATH)include
DEPSFLAGS = -MMD -MF"$(DEPS_PATH)$(notdir $(@:.o=.d))"
ARFLAGS   = rcsT

# Files
SRCS     := $(shell find src -type f)
DEPS      = $(addprefix $(DEPS_PATH), $(notdir $(SRCS:.c=.d)))
OBJS      = $(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

DEB_OBJS  = $(OBJS:.o=_debug.o)
DEB_DEPS  = $(addprefix $(DEPS_PATH), $(notdir $(DEB_OBJS:.o=.d)))

# Phony
.PHONY: all clean fclean norme re redebug

# Rules
$(NAME): CFLAGS += -O3 -DLIBHASH_INTERNAL
$(NAME): $(OBJS)
	@-git submodule update --init --recursive
	@make -C $(FT_PATH)
	$(AR) $(ARFLAGS) $@ $(FT_PATH)libft.a $^
	ranlib $@

$(DEB_NAME): CFLAGS += -g3 -DLIBHASH_INTERNAL
$(DEB_NAME): $(DEB_OBJS)
	@-git submodule update --init --recursive
	@make -C $(FT_PATH) debug
	$(AR) $(ARFLAGS) $@ $(FT_PATH)libft_debug.a $^
	ranlib $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH) $(DEPS_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@

$(OBJS_PATH)%_debug.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH) $(DEPS_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) -c $< -o $@

debug: $(DEB_NAME)

norme:
	@norminette ./**/*.{h,c}

all: $(NAME)

clean:
	@make -C $(FT_PATH) clean
	@make -C tests clean
	$(RM) $(OBJS_PATH) $(DEPS_PATH)

fclean:
	@make -C $(FT_PATH) fclean
	@make -C tests fclean
	$(RM) $(OBJS_PATH) $(DEPS_PATH)
	$(RM) $(NAME) $(DEB_NAME)

re: fclean all

redebug: fclean debug

test:
	@make -C tests
	@./tests/test

-include $(DEPS)
-include $(DEB_DEPS)

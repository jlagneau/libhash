#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 08:29:58 by jlagneau          #+#    #+#              #
#    Updated: 2016/01/11 13:30:44 by jlagneau         ###   ########.fr        #
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
AR        = ar
RM        = rm -rf

# Flags
CFLAGS    = -Wall -Wextra -Werror -pedantic -DLIBHASH_INTERNAL
CPPFLAGS  = -I$(HEAD_PATH) -I$(FT_PATH)include
DEPSFLAGS = -MMD -MF"$(DEPS_PATH)$(notdir $(@:.o=.d))"
ARFLAGS   = rcsT

# OS
UNAME_S  := $(shell uname -s)

# Files
SRCS     := $(shell find src -type f)
DEPS      = $(addprefix $(DEPS_PATH), $(notdir $(SRCS:.c=.d)))
OBJS      = $(addprefix $(OBJS_PATH), $(notdir $(SRCS:.c=.o)))

DEB_OBJS  = $(OBJS:.o=_debug.o)
DEB_DEPS  = $(addprefix $(DEPS_PATH), $(notdir $(DEB_OBJS:.o=.d)))

# Phony
.PHONY: all clean fclean norme re redebug test

# Rules
$(NAME): CFLAGS += -O3
$(NAME): $(OBJS)
	@-git submodule update --init --recursive
	@make -C $(FT_PATH)
ifeq ($(UNAME_S), Darwin)
	libtool -static -o $@ $(FT_PATH)libft.a $^
else
	$(AR) $(ARFLAGS) $@ $(FT_PATH)libft.a $^
endif
	ranlib $@

$(DEB_NAME): CFLAGS += -g3
$(DEB_NAME): $(DEB_OBJS)
	@-git submodule update --init --recursive
	@make -C $(FT_PATH) debug
ifeq ($(UNAME_S), Darwin)
	libtool -static $@ $(FT_PATH)libft.a $^
else
	$(AR) $(ARFLAGS) $@ $(FT_PATH)libft.a $^
endif
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

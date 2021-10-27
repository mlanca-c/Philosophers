# **************************************************************************** #
# libft
#
# version: 3
# Author: mlanca-c
# URL: https://github.com/mlanca-c/libft
# **************************************************************************** #

USER := mlanca-c
PROJECT := Philosophers

# **************************************************************************** #
# Project Variables
# **************************************************************************** #

NAME1 := ...

NAMES := ${NAME1}

# **************************************************************************** #
# Configs
# **************************************************************************** #

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
VERBOSE := 1

GREEN := \e[38;5;118m
YELLOW := \e[38;5;226m
RESET := \e[0m
_SUCCESS := [${GREEN}SUCCESS${RESET}]
_INFO := [${YELLOW}INFO${RESET}]

# **************************************************************************** #
# Compiler and Flags
# **************************************************************************** #

CC := gcc
CLIB := ar -rc

CFLAGS := -Wall -Wextra -Werror
DFLAGS := -g
OFLAGS := -03
FSANITIZE := -fsanitize=address

# **************************************************************************** #
# Root Folders
# **************************************************************************** #

SRC_ROOT := sources/
OBJ_ROOT := objects/
INC_ROOT := includes/
LIB_ROOT := libraries/
BIN_ROOT := binaries/

# **************************************************************************** #
# Libraries
# **************************************************************************** #

LIBFT_DIR := ${LIB_ROOT}libft/
LIBFT := libft.a

MLX := minilibx_mms 

LIBS := ${LIBFT_DIR} ${MLX}

# **************************************************************************** #
# Content Folders
# **************************************************************************** #

DIRS := ...

SRC_DIRS_LIST := $(addprefix ${SRC_ROOT},${DIRS})
SRC_DIRS_LIST := $(foreach dl,${SRC_DIRS_LIST},$(subst :,:${SRC_ROOT},${dl}))

SRC_DIRS = $(subst :,${SPACE},${SRC_DIRS_LIST})
OBJ_DIRS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRC_DIRS})

INC_DIRS = ${INC_ROOT} ${LIBS}

LIB_DIRS_LIST := ${addprefix ${LIB_ROOT},${LIBS}}
LIB_DIRS_LIST := $(foreach dl,${SRC_DIRS_LIST},$(subst :,:${SRC_ROOT},${dl}))

LIB_DIRS = $(subst :,${SPACE},${LIB_DIRS_LIST})

# **************************************************************************** #
# Files
# **************************************************************************** #

SRCS_LIST = $(foreach dl,${SRC_DIRS_LIST},$(subst ${SPACE},:,$(strip $(foreach\
	dir,$(subst :,${SPACE},${dl}),$(wildcard ${dir}*.c)))))
OBJS_LIST = $(subst ${SRC_ROOT},${OBJ_ROOT},$(subst .c,.o,${SRCS_LIST}))

SRCS = $(foreach dir,${SRC_DIRS},$(wildcard ${dir}*.c))
OBJS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRCS:.c=.o})

INCS := ${addprefix -I,${INC_DIRS}}

BINS := ${addprefix ${BIN_ROOT},${NAMES}}

# **************************************************************************** #
# VPATHS
# **************************************************************************** #

vpath %.o ${OBJ_ROOT}
vpath %.h ${INC_ROOT}
vpath %.c ${SRC_DIRS}
vpath %.a ${LIB_DIRS}

# **************************************************************************** #
# Conditions
# **************************************************************************** #

ifneq (${MLX},)
	ifeq ($(shell uname), Linux)
		MLX = minilibx_linux
		MLX_FLAGS = -lbsd -Llibraries/$(MLX) -lmlx -lXext -lX11 -lm -DOS=2
	else ifeq ($(shell uname), Darwin)
		MLX = minilibx_mms
		MLX_FLAGS = -Ilibraries/$(MLX) -L${LIB_ROOT}/$(MLX) -lmlx -DOS=1
		MLX_CP = cp ./${LIB_ROOT}/$(CURR_MLX)/libmlx.dylib ./
	endif
endif

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLOCK := &/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
# Constants
# **************************************************************************** #

NULL =
SPACE = ${NULL} #

# **************************************************************************** #
# Mandatory Targets
# **************************************************************************** #

.PHONY: all
all: ${BINS}

${BIN_ROOT}${NAME1}: ${OBJS}
	${AT} ${CC} ${CFLAGS} ${INCS} ${OBJS} ${LIBS} -o $@ ${BLOCK}
	${AT}printf "${_SUCCESS} ${@F} CREATED\n"

# **************************************************************************** #
# Library Targets
# **************************************************************************** #

.PHONY: minilibx
minilibx:
	${AT} ${MAKE} -C ${LIB_ROOT}${MLX} ${BLOCK}
	${AT} ${MLX_CP} ${BLOCK}
	CFLAGS += ${MLX_FLAGS} ${OFLAGS}

${LIB_ROOT}${LIBFT}:
	${AT} ${MAKE} -C ${LIBFT_DIR} ${BLOCK}

.PHONY: add_libft
add_libft:
	${AT} git submodule add git@github.com:mlanca-c/libft_v2.git ${LIBFT_DIR} ${BLOCK}
	${AT} git commit -m "Created submodule libft - automatic" ${BLOCK}
	${AT} printf "${_INFO} LIBFT CREATED\n" ${BLOCK}

.PHONY: remove_libft
remove_libft:
	${AT} git rm --cached ${LIBFT_DIR} ${BLOCK}
	${AT} rm -rf .git/modules/${LIBFT_DIR} ${BLOCK}
	${AT} git commit -m "Removed submodule libft - automatic" ${BLOCK}
	${AT} rm -rf ${LIBFT_DIR} ${BLOCK}
	${AT} printf "${_INFO} LIBFT REMOVED\n" ${BLOCK}

.PHONY: update_libft
update_libft:
	${AT} git submodule update ${LIBFT_DIR} ${BLOCK}
	${AT} git commit -m "Updated submodule libft - automatic" ${BLOCK}
	${AT} printf "${_INFO} LIBFT UPDATED\n" ${BLOCK}

# **************************************************************************** #
# Clean Targets
# **************************************************************************** #

.PHONY: clean
clean:
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}find ${OBJ_ROOT} -type f -delete ${BLOCK}
	${AT}printf "$(_INFO) CLEANED ${OBJ_ROOT}\n" ${BLOCK}

.PHONY: fclean
fclean: clean
	${AT}mkdir -p ${BIN_ROOT} ${BLOCK}
	${AT}find ${LIB_ROOT} -type f -delete ${BLOCK}
	${AT}printf "$(_INFO) REMOVED ${NAMES}\n" ${BLOCK}

.PHONY: re
re: fclean all

# **************************************************************************** #
# Debug Targets
# **************************************************************************** #

debug_san: CFLAGS += ${DFLAGS} ${FSANITIZE}
debug_san: all

debug: CFLAGS += ${DFLAGS}
debug: all

debug_re: fclean debug

# **************************************************************************** #
# Norminette Targets
# **************************************************************************** #

.PHONY: norm
norm:
	${AT} norminette ${SRCS} ${INC_ROOT} ${BLOCK}

.PHONY: norm_status
norm_status:
	${AT} printf "FILES No: " ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|wc -l ${BLOCK}
	${AT} printf "OK: " ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|grep -wc "OK" ${BLOCK}

# **************************************************************************** #
# Setup Targets
# **************************************************************************** #

.PHONY: .init
.init:
	${AT}clear ${BLOCK}
	${AT}printf "${_INFO} CREATING FOLDERS\n" ${BLOCK}
	${AT}mkdir -p ${SRC_ROOT} ${BLOCK}
	${AT}mkdir -p ${INC_ROOT} ${BLOCK}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}mkdir -p ${LIB_ROOT} ${BLOCK}
	${AT}printf "${_INFO} CREATING README.md\n" ${BLOCK}
	${AT}git clone git@github.com:${USER}/Generic-README.git ${BLOCK}
	${AT}mv Generic-README/README.md ./ ${BLOCK}
	${AT}rm -rf Generic-README ${BLOCK}
	${AT}sed -i 's/NAME/${PROJECT}/g' README.md ${BLOCK}
	${AT}printf "${_INFO} INITIALIZING GIT REPOSITORY\n" ${BLOCK}
	${AT}git init ${BLOCK}
	${AT}echo "*.o\n*.d\n.vscode\na.out\n.DS_Store" > .gitignore ${BLOCK}
	${AT}git add README.md ${BLOCK}
	${AT}git add .gitignore ${BLOCK}
	${AT}git add Makefile ${BLOCK}
	${AT}git commit -m "first commit - automatic" ${BLOCK}
	${AT}git branch -M main ${BLOCK}
	${AT}git remote add origin git@github.com:${USER}/${PROJECT}.git ${BLOCK}
	${AT}git push -u origin main ${BLOCK}
	${AT}printf "${_SUCCESS} SETUP READY\n" ${BLOCK}
	${AT}git status ${BLOCK}

# **************************************************************************** #
# Functions
# **************************************************************************** #

# **************************************************************************** #
# Target Templates
# **************************************************************************** #

define make_bin
${1} : ${2}
endef

define make_obj
${1} : ${2}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT} $${CC} $${CFLAGS} $${INCS} -c $$< -o $$@ $${BLOCK}
endef

# **************************************************************************** #
# Target Generator
# **************************************************************************** #

$(foreach bin,${BINS},$(eval\
$(call make_bin,$(notdir ${bin}),${bin})))

$(foreach src,${SRCS},$(eval\
$(call make_obj,$(subst ${SRC_ROOT},${OBJ_ROOT},${src:.c=.o}),${src})))

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

NAME1 := philo

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

GREEN	:= \e[38;5;118m
YELLOW	:= \e[38;5;226m
RED		:= \e[38;5;9m
RESET	:= \e[0m

_SUCCESS	:= [${GREEN} ok ${RESET}]
_FAILURE	:= [${RED} ko ${RESET}]
_INFO		:= [${YELLOW} info ${RESET}]

# **************************************************************************** #
# Compiler and Flags
# **************************************************************************** #

CC		:= gcc

CFLAGS		:= -Wall -Wextra -Werror
DFLAGS		:= -g
#OFLAGS		:= -03
TFLAGS		:= -pthread
FSANITIZE	:= -fsanitize=address

CFLAGS		+= ${TFLAGS}

# **************************************************************************** #
# Root Folders
# **************************************************************************** #

SRC_ROOT	:= sources/
OBJ_ROOT	:= objects/
INC_ROOT	:= includes/
BIN_ROOT	:= ./
TEST_ROOT	:= tests/

# **************************************************************************** #
# Content Folders
# **************************************************************************** #

DIRS := ./

SRC_DIRS_LIST := $(addprefix ${SRC_ROOT},${DIRS})
SRC_DIRS_LIST := $(foreach dl,${SRC_DIRS_LIST},$(subst :,:${SRC_ROOT},${dl}))

SRC_DIRS = $(subst :,${SPACE},${SRC_DIRS_LIST})
OBJ_DIRS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRC_DIRS})

INC_DIRS = ${INC_ROOT}

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

# **************************************************************************** #
# Conditions
# **************************************************************************** #

#ifneq (${MLX},)
#	ifeq ($(shell uname), Linux)
#	else ifeq ($(shell uname), Darwin)
#endif

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

${OBJ_ROOT}%.o: ${SRC_ROOT}%.c
	${CC} ${CFLAGS} ${INCS} -c $< -o $@ ${BLOCK}
	

.PHONY: all
all: ${BINS}

${BIN_ROOT}${NAME1}: cl ${OBJS}
	${AT} ${CC} ${CFLAGS} ${INCS} ${OBJS} -o $@ ${BLOCK}
	${AT}printf "Object files created .................. ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Binary file compiled .................. ${_SUCCESS}\n" ${BLOCK}
	${AT}printf "Binary file ready ..................... ${_SUCCESS}\n" ${BLOCK}

# **************************************************************************** #
# Clean Targets
# **************************************************************************** #

.PHONY: cl
cl:
	${AT}clear ${BLOCK}

.PHONY: clean
clean: cl
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}find ${OBJ_ROOT} -type f -delete ${BLOCK}
	${AT}printf "Object files removed .................. ${_SUCCESS}\n" ${BLOCK}

.PHONY: fclean
fclean: cl clean
	${AT} rm -f ${NAMES} ${BLOCK}
	${AT} rm -rf *.dSYM ${BLOCK}
	${AT}printf "Binary file removed ................... ${_SUCCESS}\n" ${BLOCK}

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
# Test Targets
# **************************************************************************** #

.PHONY: run_invalid_arg
run_invalid_arg: re cl
	${AT}bash ${TEST_ROOT}invalid_arg.sh ${BLOCK}
	${AT}printf "Bash file compiled .................... ${_SUCCESS}\n" ${BLOCK}

# **************************************************************************** #
# Norminette Targets
# **************************************************************************** #

.PHONY: norm
norm: cl
	${AT} norminette ${SRCS} ${INC_ROOT} ${BLOCK}
	${AT}printf "Target working accordingly ............ ${_SUCCESS}\n" ${BLOCK}

.PHONY: norm_status
norm_status: cl
	${AT} printf "[${YELLOW} FILES No ${RESET}]:" ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|wc -l ${BLOCK}
	${AT} printf "${_SUCCESS}:\t\t   " ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|grep -wc "OK" ${BLOCK}
	${AT}printf "Target working accordingly ............ ${_SUCCESS}\n" ${BLOCK}

# **************************************************************************** #
# Setup Targets
# **************************************************************************** #

.PHONY: folders
folders: cl
	${AT}mkdir -p ${SRC_ROOT} ${BLOCK}
	${AT}mkdir -p ${INC_ROOT} ${BLOCK}
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}printf "Project folders created ............... ${_SUCCESS}\n" ${BLOCK}

.PHONY: .init
.init: cl folders
	${AT}clear ${BLOCK}
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
	${AT}printf "Initial setup ready ................... ${_SUCCESS}\n" ${BLOCK}
	${AT}git status ${BLOCK}

# **************************************************************************** #
# Functions
# **************************************************************************** #

# **************************************************************************** #
# Target Templates
# **************************************************************************** #

#define make_bin
#${1} : ${2}
#endef

#define make_obj
#${1} : ${2}
#	$${AT}mkdir -p $${@D} $${BLOCK}
#	$${AT} $${CC} $${CFLAGS} $${INCS} -c $$< -o $$@ $${BLOCK}
#endef

# **************************************************************************** #
# Target Generator
# **************************************************************************** #

$(foreach bin,${BINS},$(eval\
$(call make_bin,$(notdir ${bin}),${bin})))

$(foreach src,${SRCS},$(eval\
$(call make_obj,$(subst ${SRC_ROOT},${OBJ_ROOT},${src:.c=.o}),${src})))

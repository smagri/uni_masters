#
# 41012 week1 exercises, pointers & reference
#

# -----------------------------------------------------------------------------
# - Define macros
# ---------------
SHELL = /bin/csh

OTHER_ARG =
OTHER_ARG_afn =

CC = gcc
#CPP = g++
#CC = g++

CFLAGS = -Iinclude -O -Wall -g
CFLAGS_fn = -Iinclude -O -Wall -g -c
# !debugging:
# CFLAGS_fn = -Iinclude -O -Wall -ansi -pedantic -c

#  include debug_macros

# -----------------------------------------------------------------------------
# - Targets, prerequisites and their build rules
# ----------------------------------------------
ptrsAndRef: ptrsAndRef.c
	${CC} ${CFLAGS} ptrsAndRef.c -o ptrsAndRef

#  include debug_targets

# -----------------------------------------------------------------------------
# - misc commands
# ---------------
clean:
	\rm -rf ptrsAndRef

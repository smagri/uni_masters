#
# 41012 week1 exercises, c arrays & macros
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
cStrings: cStrings.c
	${CC} ${CFLAGS} cStrings.c -o cStrings

#  include debug_targets

# -----------------------------------------------------------------------------
# - misc commands
# ---------------
clean:
	\rm -rf cStrings

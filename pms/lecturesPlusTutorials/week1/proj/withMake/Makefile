#
# writeSerialPort -> usb modem
#

# -----------------------------------------------------------------------------
# - Define macros
# ---------------
SHELL = /bin/csh

OTHER_ARG =
OTHER_ARG_afn =

#CC = gcc
#CPP = g++
CC = g++

CFLAGS = -Iinclude -O -Wall -g
CFLAGS_fn = -Iinclude -O -Wall -g -c
# !debugging:
# CFLAGS_fn = -Iinclude -O -Wall -ansi -pedantic -c

#  include debug_macros

# -----------------------------------------------------------------------------
# - Targets, prerequisites and their build rules
# ----------------------------------------------
hw: hw.cpp
	${CC} ${CFLAGS} hw.cpp -o hw

#  include debug_targets

# -----------------------------------------------------------------------------
# - misc commands
# ---------------
clean:
	\rm -rf hw

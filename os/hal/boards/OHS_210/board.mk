# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/OHS_210/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/OHS_210

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

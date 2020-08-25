# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/OHS_204/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/OHS_204

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

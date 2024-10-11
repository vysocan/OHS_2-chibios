# List of all the board related files.
BOARDSRC = ${CHIBIOS}/os/hal/boards/OHS_STM32_F103_MINI/board.c

# Required include directories
BOARDINC = ${CHIBIOS}/os/hal/boards/OHS_STM32_F103_MINI

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

# ST CRYPT files.
#STCRYSRC = $(CHIBIOS)/ext/STM32_Cryptographic_Library/src/crypto.c 

STCRYINC = $(CHIBIOS)/ext/STM32_Cryptographic_Library/inc

# Shared variables
ALLCSRC += $(STCRYSRC)
ALLINC  += $(STCRYINC)

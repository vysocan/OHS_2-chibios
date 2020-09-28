# ST CRYPT files.
STCRYSRC = $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/crypto.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c \
           $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c

STCRYINC = $(CHIBIOS)/ext/STM32F4xx_StdPeriph_Driver/inc

# Shared variables
ALLCSRC += $(STCRYSRC)
ALLINC  += $(STCRYINC)

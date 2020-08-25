ifeq ($(USE_SMART_BUILD),yes)
ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/hal_serial_lld.c
endif
ifneq ($(findstring HAL_USE_UART TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/hal_uart_lld.c
endif
ifneq ($(findstring HAL_USE_RS485 TRUE,$(HALCONF)),)
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/hal_rs485_lld.c
endif
else
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/hal_serial_lld.c
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/hal_uart_lld.c
PLATFORMSRC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1/hal_rs485_lld.c
endif

PLATFORMINC += $(CHIBIOS)/os/hal/ports/STM32/LLD/USARTv1

# ZNP framework files.
    #     $(CHIBIOS)/ext/znp/framework/platform/stm32/rpcTransportUart.c \ 
    #     $(CHIBIOS)/ext/znp/framework/rpc/rpc_queue.c \ 
ZNPSRC = $(CHIBIOS)/ext/znp/framework/platform/stm32/dbgPrint.c \
         $(CHIBIOS)/ext/znp/framework/rpc/rpc.c \
#         $(CHIBIOS)/ext/znp/framework/mt/mtParser.c \
#         $(CHIBIOS)/ext/znp/framework/mt/Af/mtAf.c \
#         $(CHIBIOS)/ext/znp/framework/mt/AppCfg/mtAppCfg.c \
#         $(CHIBIOS)/ext/znp/framework/mt/Sapi/mtSapi.c \
#         $(CHIBIOS)/ext/znp/framework/mt/Sys/mtSys.c \
#         $(CHIBIOS)/ext/znp/framework/mt/Util/mtUtil.c \
#         $(CHIBIOS)/ext/znp/framework/mt/Zdo/mtZdo.c 


ZNPINC = $(CHIBIOS)/ext/znp/framework/platform/stm32 \
         $(CHIBIOS)/ext/znp/framework/rpc# \
#         $(CHIBIOS)/ext/znp/framework/mt \
#         $(CHIBIOS)/ext/znp/framework/mt/Af \
#         $(CHIBIOS)/ext/znp/framework/mt/AppCfg \
#         $(CHIBIOS)/ext/znp/framework/mt/Sapi \
#         $(CHIBIOS)/ext/znp/framework/mt/Sys \
#         $(CHIBIOS)/ext/znp/framework/mt/Util \
#         $(CHIBIOS)/ext/znp/framework/mt/Zdo 

# Shared variables
ALLCSRC += $(ZNPSRC)
ALLINC  += $(ZNPINC)

#include <stdint.h>
// - 2.0.6 #include <stm32f4xx_rcc.h>

#define DEBUG_WOLFSSL
#define WOLFSSL_STM32F4
#define WOLFSSL_STM32_CUBEMX

//#define NO_STM32_RNG
#define NO_STM32_CRYPTO
//#define NO_STM32_HASH
//

/* Configuration */
#define WOLFSSL_GENERAL_ALIGNMENT 4
#define HAVE_TM_TYPE
#define WORD64_AVAILABLE

/* ChibiOS + Lwip */
#define HAVE_LWIP_NATIVE 
#define WOLFSSL_CHIBIOS 

#define USER_TICKS 
#define WOLFSSL_USER_CURRTIME 
#define XMALLOC_OVERRIDE 
//#define USE_WOLF_TIME_T
#define XTIME(tl)       (LowResTimer())

/* ARM  */
#define RSA_LOW_MEM
#define NO_OLD_RNGNAME  
#define SMALL_SESSION_CACHE
#define WOLFSSL_SMALL_STACK // needs + 7KB tread stack size, then faster 14->12 sec

//#define TFM_ARM
#define SINGLE_THREADED
#define NO_SIG_WRAPPER
		
/* Cipher features */
//#define USE_FAST_MATH // Actually adds time to execution
//#define ALT_ECC_SIZE
// tests
/*
#define WOLFSSL_SP_ASM
#define WOLFSSL_SP_ARM_CORTEX_M_ASM
#define WOLFSSL_SP
#define WOLFSSL_HAVE_SP_RSA
#define WOLFSSL_HAVE_SP_DH
#define WOLFSSL_HAVE_SP_ECC
*/

#define WOLFSSL_SP_MATH
#define WOLFSSL_SP_ASM
#define WOLFSSL_SP_ARM_CORTEX_M_ASM
//#define WOLFSSL_SP_NONBLOCK
#define WOLFSSL_HAVE_SP_RSA
#define WOLFSSL_HAVE_SP_DH
#define WOLFSSL_HAVE_SP_ECC

//#define HAVE_FFDHE_2048
//#define HAVE_CHACHA
//#define HAVE_POLY1305
#define HAVE_ECC 
#define HAVE_CURVE25519
#define CURVED25519_SMALL
#define HAVE_ONE_TIME_AUTH
#define WOLFSSL_DH_CONST // -- turns off use of floating point values
//#define WOLFSSL_STATIC_RSA // removing discouraged
//OHS
// + pushover api
#define HAVE_AES_CBC
//#define WOLFSSL_STATIC_RSA
#define HAVE_AESGCM // Telegram suite
		
/* HW RNG support */
unsigned int chibios_rand_generate(void);
int custom_rand_generate_block(unsigned char* output, unsigned int sz);

#define CUSTOM_RAND_GENERATE chibios_rand_generate
#define CUSTOM_RAND_TYPE uint32_t

//#define HAVE_ED25519
//--#define HAVE_SHA512
//--#define WOLFSSL_SHA512

/* Size/speed config */
//#define USE_SLOW_SHA2
//#define USE_SLOW_SHA512

/* Robustness */
#define TFM_TIMING_RESISTANT
#define ECC_TIMING_RESISTANT
#define WC_RSA_BLINDING

/* Remove Features */
#define NO_WRITEV
//#define NO_DEV_RANDOM
#define NO_FILESYSTEM
#define NO_MAIN_DRIVER
#define NO_MD4
#define NO_RABBIT
#define NO_HC128
#define NO_DSA
#define NO_PWDBASED
#define NO_PSK
#define NO_DES3
#define NO_RC4

// OHS added disable all certificate date checking
#define NO_ASN_TIME

// OHS special defines
#define WOLFSSL_HEAP_ON_UMM
#define WOLFSSL_USE_SOCKET

#ifndef WOLFSSL_HEAP_ON_UMM
/* Realloc (to use without USE_FAST_MATH) */
void *chHeapRealloc (void *addr, uint32_t size);
#define XREALLOC(p,n,h,t) chHeapRealloc( (p) , (n) )
#endif

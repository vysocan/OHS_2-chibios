# List of the required lwIP files.
MBEDTLS = $(CHIBIOS)/ext/mbedtls

#MBEDTLSBINDSRC = \
#        $(CHIBIOS)/os/various/wolfssl_bindings/wolfssl_chibios.c \
#        $(CHIBIOS)/os/various/wolfssl_bindings/hwrng.c

MBEDTLSCRYPTO = \
	$(MBEDTLS)/library/aes.c \
	$(MBEDTLS)/library/aesni.c \
	$(MBEDTLS)/library/arc4.c \
	$(MBEDTLS)/library/aria.c \
	$(MBEDTLS)/library/asn1parse.c \
	$(MBEDTLS)/library/asn1write.c \
	$(MBEDTLS)/library/base64.c \
	$(MBEDTLS)/library/bignum.c \
	$(MBEDTLS)/library/blowfish.c \
	$(MBEDTLS)/library/camellia.c \
	$(MBEDTLS)/library/ccm.c \
	$(MBEDTLS)/library/chacha20.c \
	$(MBEDTLS)/library/chachapoly.c \
	$(MBEDTLS)/library/cipher.c \
	$(MBEDTLS)/library/cipher_wrap.c \
	$(MBEDTLS)/library/cmac.c \
	$(MBEDTLS)/library/ctr_drbg.c \
	$(MBEDTLS)/library/des.c \
	$(MBEDTLS)/library/dhm.c \
	$(MBEDTLS)/library/ecdh.c \
	$(MBEDTLS)/library/ecdsa.c \
	$(MBEDTLS)/library/ecjpake.c \
	$(MBEDTLS)/library/ecp.c \
	$(MBEDTLS)/library/ecp_curves.c \
	$(MBEDTLS)/library/entropy.c \
	$(MBEDTLS)/library/entropy_poll.c \
	$(MBEDTLS)/library/error.c \
	$(MBEDTLS)/library/gcm.c \
	$(MBEDTLS)/library/havege.c \
	$(MBEDTLS)/library/hkdf.c \
	$(MBEDTLS)/library/hmac_drbg.c \
	$(MBEDTLS)/library/md.c \
	$(MBEDTLS)/library/md2.c \
	$(MBEDTLS)/library/md4.c \
	$(MBEDTLS)/library/md5.c \
	$(MBEDTLS)/library/memory_buffer_alloc.c \
	$(MBEDTLS)/library/nist_kw.c \
	$(MBEDTLS)/library/oid.c \
	$(MBEDTLS)/library/padlock.c \
	$(MBEDTLS)/library/pem.c \
	$(MBEDTLS)/library/pk.c \
	$(MBEDTLS)/library/pk_wrap.c \
	$(MBEDTLS)/library/pkcs12.c \
	$(MBEDTLS)/library/pkcs5.c \
	$(MBEDTLS)/library/pkparse.c \
	$(MBEDTLS)/library/pkwrite.c \
	$(MBEDTLS)/library/platform.c \
	$(MBEDTLS)/library/platform_util.c \
	$(MBEDTLS)/library/poly1305.c \
	$(MBEDTLS)/library/psa_crypto.c \
	$(MBEDTLS)/library/psa_crypto_se.c \
	$(MBEDTLS)/library/psa_crypto_slot_management.c \
	$(MBEDTLS)/library/psa_crypto_storage.c \
	$(MBEDTLS)/library/psa_its_file.c \
	$(MBEDTLS)/library/ripemd160.c \
	$(MBEDTLS)/library/rsa.c \
	$(MBEDTLS)/library/rsa_internal.c \
	$(MBEDTLS)/library/sha1.c \
	$(MBEDTLS)/library/sha256.c \
	$(MBEDTLS)/library/sha512.c \
	$(MBEDTLS)/library/ssl_cli.c \
	$(MBEDTLS)/library/ssl_tls.c \
	$(MBEDTLS)/library/ssl_msg.c \
	$(MBEDTLS)/library/ssl_srv.c \
	$(MBEDTLS)/library/ssl_ciphersuites.c \
	$(MBEDTLS)/library/threading.c \
	$(MBEDTLS)/library/timing.c \
	$(MBEDTLS)/library/version.c \
	$(MBEDTLS)/library/version_features.c \
	$(MBEDTLS)/library/xtea.c

MBEDTLSX509 = \
	$(MBEDTLS)/library/certs.c \
	$(MBEDTLS)/library/pkcs11.c \
	$(MBEDTLS)/library/x509.c \
	$(MBEDTLS)/library/x509_create.c \
	$(MBEDTLS)/library/x509_crl.c \
	$(MBEDTLS)/library/x509_crt.c \
	$(MBEDTLS)/library/x509_csr.c \
	$(MBEDTLS)/library/x509write_crt.c \
	$(MBEDTLS)/library/x509write_csr.c

MBEDTLSSRCTLS = \
	$(MBEDTLS)/library/debug.c \
#	$(MBEDTLS)/library/net_sockets.c \
	$(MBEDTLS)/library/ssl_cache.c \
	$(MBEDTLS)/library/ssl_ciphersuites.c \
#	$(MBEDTLS)/library/ssl_cli.c \
	$(MBEDTLS)/library/ssl_cookie.c \
	$(MBEDTLS)/library/ssl_msg.c \
	$(MBEDTLS)/library/ssl_srv.c \
	$(MBEDTLS)/library/ssl_ticket.c \
	$(MBEDTLS)/library/ssl_tls.c

MBEDSRC = $(MBEDTLSCRYPTO) ${MBEDTLSX509} ${MBEDTLSSRCTLS}

MBEDINC = \
        $(MBEDTLS)/include

# Shared variables
ALLCSRC += $(MBEDSRC)
ALLINC  += $(MBEDINC)


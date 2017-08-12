AM_CFLAGS =                   -I$(top_srcdir)/include -I$(top_srcdir)/secp256k1/src -std=c99 @CHECK_CFLAGS@
LDADD =                       $(top_builddir)/src/libtwineconsensus.la @CHECK_LIBS@
LDFLAGS =                     -static

CLEANFILES =                  tw_lic_check

TESTS =                       test_version_check test_u256_check test_sha256_check test_secp256k1_check
check_PROGRAMS =              test_version_check test_u256_check test_sha256_check test_secp256k1_check

TW_TWINE_HEADER =             $(top_builddir)/include/twineconsensus.h vectors/*.h

test_version_check_SOURCES =  test_version_check.c $(TW_TWINE_HEADER)
test_u256_check_SOURCES =     test_u256.c vectors/vectors_u256.h $(TW_TWINE_HEADER)
test_sha256_check_SOURCES =   test_sha256.c vectors/vectors_sha256.h $(TW_TWINE_HEADER)
test_secp256k1_check_SOURCES =test_secp256k1.c vectors/vectors_secp256k1.h $(TW_TWINE_HEADER)

TW_ALL_SRC =                  $(test_version_check_SOURCES)
TW_ALL_SRC +=                 $(test_u256_check_SOURCES)
TW_ALL_SRC +=                 $(test_sha256_check_SOURCES)
TW_ALL_SRC +=                 $(test_secp256k1_check_SOURCES)

all-local: tw_lic_check

tw_lic_check: $(TW_ALL_SRC)
	../scripts/check_licence.sh $(TW_ALL_SRC)
	touch tw_lic_check

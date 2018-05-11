AM_CFLAGS                    = -I$(top_srcdir)/include -I$(top_srcdir)/secp256k1/src -fvisibility=hidden -std=c99 -pedantic

CLEANFILES                   = tw_lic_check

lib_LTLIBRARIES		     = libtwineconsensus.la
libtwineconsensus_la_SOURCES = twineconsensus.c tw_u256.c tw_sha256.c tw_secp256k1.c tw_context.c
libtwineconsensus_la_LDFLAGS = -no-undefined -version-info @twcon_ver@:@twcon_rev@:@twcon_age@
libtwineconsensus_la_LIBADD  = ../secp256k1/libsecp256k1.la

include_HEADERS              = ../include/twineconsensus.h

all-local: tw_lic_check

install-exec-hook:
	../scripts/install_natives.sh $(host) $(prefix) @twcon_ver@ $(TW_NATIVE_PATH)

tw_lic_check: $(include_HEADERS) $(libtwineconsensus_la_SOURCES)
	../scripts/check_licence.sh $(include_HEADERS) $(libtwineconsensus_la_SOURCES)
	touch tw_lic_check

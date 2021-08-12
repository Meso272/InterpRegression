#AM_CFLAGS = -I./include -I../zlib
#LDFLAGS=-fPIC -shared

AUTOMAKE_OPTIONS=foreign
include_HEADERS=include/MatrixOperation.h include/ExtractData.h include/InterpRegression.h

lib_LTLIBRARIES=libinterpreg.la
libinterpreg_la_CFLAGS=-I./include -I../qcat/include
libinterpreg_la_LDFLAGS = -version-info  0:1:0
libinterpreg_la_LIDADD=../qcat/.libs/libqcat.a
libinterpreg_la_SOURCES=src/MatrixOperation.c src/ExtractData.c src/InterpRegression.c

libinterpreg_la_LINK= $(AM_V_CC)$(LIBTOOL) --tag=CC --mode=link $(CCLD) $(libinterpreg_la_CFLAGS) -O3 $(libinterpreg_la_LDFLAGS) -o $(lib_LTLIBRARIES)

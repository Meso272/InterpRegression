AUTOMAKE_OPTIONS=foreign
AM_CFLAGS = -I../qcat/include -I../zstd -I../interpReg/include

bin_PROGRAMS=lorenzoFix interpRegFix interpRegDyn1D4Points interpRegDyn3D6Points interpRegDyn3D8Points interpRegDyn3D12Points

lorenzoFix_SOURCES=lorenzoFix.c
lorenzoFix_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
interpRegFix_SOURCES=interpRegFix.c
interpRegFix_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a -lm
interpRegDyn1D4Points_SOURCES=interpRegDyn1D4Points.c
interpRegDyn1D4Points_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a ../interpReg/.libs/libinterpreg.a -lm
interpRegDyn3D6Points_SOURCES=interpRegDyn3D6Points.c
interpRegDyn3D6Points_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a ../interpReg/.libs/libinterpreg.a -lm
interpRegDyn3D8Points_SOURCES=interpRegDyn3D8Points.c
interpRegDyn3D8Points_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a ../interpReg/.libs/libinterpreg.a -lm
interpRegDyn3D12Points_SOURCES=interpRegDyn3D12Points.c
interpRegDyn3D12Points_LDADD=../qcat/.libs/libqcat.a ../zstd/.libs/libzstd.a ../interpReg/.libs/libinterpreg.a -lm

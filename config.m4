PHP_ARG_ENABLE(rdtsc, [whether to enable rdtsc support],
[  --enable-rdtsc          Enable rdtsc support])

if test "$PHP_RDTSC" = "yes"; then
  PHP_NEW_EXTENSION(rdtsc, php_rdtsc.c,$ext_shared,,$P2C_CFLAGS)
fi
AC_USE_SYSTEM_EXTENSIONS
AC_PROG_CC_STDC
AC_C_INLINE
AC_HEADER_TIME

AC_CHECK_HEADERS([sys/time.h c_asm.h intrinsics.h mach/mach_time.h x86intrin.h])

AC_CHECK_TYPE([hrtime_t],[
AC_DEFINE(HAVE_HRTIME_T, 1, [Define to 1 if hrtime_t is defined in <sys/time.h>])],,
[#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif])

AC_CHECK_DECL(__rdtsc, [AC_DEFINE([HAVE_RDTSC_BUILTIN],1,[have __rdtsc in GCC])], [], 
[#if HAVE_X86INTRIN_H
 #include <x86intrin.h> 
 #endif])

AC_CHECK_FUNCS([gethrtime read_real_time time_base_to_time clock_gettime mach_absolute_time])

dnl Cray UNICOS _rtc() (real-time clock) intrinsic
AC_MSG_CHECKING([for _rtc intrinsic])
   rtc_ok=yes
AC_TRY_LINK([#ifdef HAVE_INTRINSICS_H
#include <intrinsics.h>
#endif], [_rtc()], [AC_DEFINE(HAVE__RTC,1,[Define if you have the UNICOS _rtc() intrinsic.])], [rtc_ok=no])
   AC_MSG_RESULT($rtc_ok)

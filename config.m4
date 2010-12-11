PHP_ARG_ENABLE(rdtsc, [whether to enable rdtsc support],
[  --enable-rdtsc          Enable rdtsc support])

if test "$PHP_RDTSC" = "yes"; then
  PHP_NEW_EXTENSION(rdtsc, php_rdtsc.c,$ext_shared,,$P2C_CFLAGS)
fi

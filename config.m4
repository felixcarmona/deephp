PHP_ARG_ENABLE(deephp, whether to enable deephp support,
 [ --enable-deephp           Enable deephp support])

if test "$PHP_DEEPHP" = "yes"; then
  AC_DEFINE(HAVE_DEEPHP, 1, [Whether you want deephp support])
  PHP_NEW_EXTENSION(deephp, main.c, $ext_shared)
fi
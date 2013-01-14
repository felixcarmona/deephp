PHP_ARG_ENABLE(deephp,
    [Whether to enable the "deephp" extension],
    [  --enable-deephp      Enable "deephp" extension support])

if test $PHP_DEEPHP != "no"; then
    PHP_REQUIRE_CXX()
    PHP_SUBST(DEEPHP_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, DEEPHP_SHARED_LIBADD)
    PHP_NEW_EXTENSION(deephp, main.cpp, $ext_shared)
fi
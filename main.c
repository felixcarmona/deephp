#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_deephp.h"

ZEND_BEGIN_ARG_INFO_EX(func_args, 1, 0, 0)
ZEND_END_ARG_INFO()

#include "lib/function_entry.c"

zend_module_entry deephp_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
STANDARD_MODULE_HEADER,
#endif
PHP_DEEPHP_EXT_EXTNAME,
deephp_functions,
NULL,
NULL,
NULL,
NULL,
NULL,
#if ZEND_MODULE_API_NO >= 20010901
PHP_DEEPHP_EXT_VERSION,
#endif
STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_DEEPHP
ZEND_GET_MODULE(deephp)
#endif

#include "lib/deephp_functions.c"

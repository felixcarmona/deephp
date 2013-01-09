#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_deephp.h"

ZEND_BEGIN_ARG_INFO_EX(func_args, 1, 0, 0)
ZEND_END_ARG_INFO()

static zend_function_entry deephp_functions[] = { // php 5.4+ zend_function_entry : else : function_entry
PHP_FE(get_memory_address, func_args)
{NULL, NULL, NULL}
};

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

PHP_FUNCTION(get_memory_address)
{
zval *var;
char r[100];
if( zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &var) == FAILURE ) {
RETURN_NULL();
}
sprintf(r, "%p", Z_ARRVAL_P(var));
RETURN_STRING(r, 1);
}
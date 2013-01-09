#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_deephp.h"

ZEND_BEGIN_ARG_INFO_EX(func_args, 1, 0, 0)
ZEND_END_ARG_INFO()

static zend_function_entry deephp_functions[] = { // php 5.4+ zend_function_entry : else : function_entry
PHP_FE(get_array_memory_address, func_args)
PHP_FE(whattype, func_args)
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








PHP_FUNCTION(get_array_memory_address)
{
zval *var;
char r[100];
if( zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &var) == FAILURE ) {
RETURN_NULL();
}
sprintf(r, "%p", Z_ARRVAL_P(var));
RETURN_STRING(r, 1);
}

PHP_FUNCTION(whattype)
{

    zval **arg;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Z", &arg) == FAILURE) {
        RETURN_NULL();
    }

    switch (Z_TYPE_PP(arg)) {
        case IS_NULL:
            RETVAL_STRING("NULL", 1);
            break;

        case IS_BOOL:
            RETVAL_STRING("boolean", 1);
            break;

        case IS_LONG:
            RETVAL_STRING("integer", 1);
            break;

        case IS_DOUBLE:
            RETVAL_STRING("double", 1);
            break;

        case IS_STRING:
            RETVAL_STRING("string", 1);
            break;

        case IS_ARRAY:
            RETVAL_STRING("array", 1);
            break;

        case IS_OBJECT:
            RETVAL_STRING("object", 1);
            break;

        case IS_RESOURCE:
             {
                 const char *type_name = zend_rsrc_list_get_rsrc_type(Z_LVAL_PP(arg) TSRMLS_CC);

                 if (type_name) {
                     RETVAL_STRING("resource", 1);
                     break;
                 }
             }

        default:
                RETVAL_STRING("unknown type", 1);
        }

}
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
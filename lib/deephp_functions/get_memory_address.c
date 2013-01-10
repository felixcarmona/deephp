PHP_FUNCTION(get_memory_address)
{
    zval *arg;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &arg) == FAILURE)
        RETURN_NULL();

    char r[100];
    switch (arg->type) {
        case IS_BOOL:
        case IS_LONG:
            sprintf(r, "%p", (void *)&arg->value.lval);
            break;
        case IS_DOUBLE:
            sprintf(r, "%p", (void *)&arg->value.dval);
            break;
        case IS_STRING:
            sprintf(r, "%p", (void *)arg->value.str.val);
            break;
        case IS_ARRAY:
        case IS_OBJECT:
        case IS_RESOURCE:
        case IS_NULL:
        default:
            sprintf(r, "%p", (void *)arg);
            break;
    }
	RETURN_STRING(r, 1);
}
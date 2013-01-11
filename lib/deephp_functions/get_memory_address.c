PHP_FUNCTION(get_memory_address)
{
    zval *arg;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &arg) == FAILURE)
        RETURN_NULL();

    char r[100];
    get_memory_address(arg, r);
	RETURN_STRING(r, 1);
}
PHP_FUNCTION(is_referencing)
{
    zval *arg1, *arg2;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &arg1, &arg2) == FAILURE)
        RETURN_NULL();

    char r1[100];
    char r2[100];
    get_memory_address(arg1, r1);
    get_memory_address(arg2, r2);

    int i;
    for(i = 0; i <= 100; i++)
    {
        if(r1[i] != r2[i])
            RETURN_FALSE;
    }
	RETURN_TRUE;
}
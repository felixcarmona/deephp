PHP_FUNCTION(are_referenced)
{
    zval *arg1, *arg2;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &arg1, &arg2) == FAILURE)
        RETURN_NULL();

    std::string r1 = get_memory_address(arg1);
    std::string r2 = get_memory_address(arg2);

    if(r1 == r2)
    {
        RETURN_TRUE;
    }
	else
	{
	    RETURN_FALSE;
	}
}
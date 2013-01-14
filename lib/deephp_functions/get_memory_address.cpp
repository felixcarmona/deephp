PHP_FUNCTION(get_memory_address)
{
    zval *arg;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &arg) == FAILURE)
        RETURN_NULL();

    std::string r = get_memory_address(arg);

	RETURN_STRING(r . c_str(), 1);
}
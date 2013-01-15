ZEND_FUNCTION(set_memory_data)
{
	zval *arg1, *arg2, *arg3;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &arg1, &arg2) == FAILURE)
		RETURN_NULL();

    uintptr_t address;
    std::stringstream(arg1->value.str.val) >> std::hex >> address;
    std::string contents = arg2->value.str.val;

    memcpy((void *)address, contents.c_str(), contents.length());
    RETURN_NULL();
}
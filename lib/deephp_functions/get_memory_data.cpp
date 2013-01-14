ZEND_FUNCTION(get_memory_data)
{
	zval *arg;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &arg) == FAILURE)
		RETURN_NULL();

    unsigned long address; // TODO: 64-bit platforms needs use uintptr_t to accurately store a memory address
    std::stringstream(arg->value.str.val) >> std::hex >> address;
	std::string r = (char *)address;
    RETURN_STRING(r . c_str(), 1);
}
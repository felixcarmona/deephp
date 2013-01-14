ZEND_FUNCTION(get_memory_data)
{
	zval *arg;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &arg) == FAILURE)
		RETURN_NULL();

    uintptr_t address;
    std::stringstream(arg->value.str.val) >> std::hex >> address;
	std::string r = reinterpret_cast<char *>(static_cast<uintptr_t>(address));
    RETURN_STRING(r . c_str(), 1);
}
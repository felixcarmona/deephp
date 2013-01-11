static zend_function_entry deephp_functions[] = {
    PHP_FE(get_memory_address, func_args)
    PHP_FE(is_referencing, func_args)
    {NULL, NULL, NULL}
};
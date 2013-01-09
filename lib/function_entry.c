static zend_function_entry deephp_functions[] = {
    PHP_FE(get_array_memory_address, func_args)
    PHP_FE(whattype, func_args)
    {NULL, NULL, NULL}
};
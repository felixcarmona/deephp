static zend_function_entry deephp_functions[] = {
    PHP_FE(get_memory_address, func_args)
    PHP_FE(are_referenced, func_args)
    PHP_FE(get_memory_data, func_args)
    {NULL, NULL, NULL}
};
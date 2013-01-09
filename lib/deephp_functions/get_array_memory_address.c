PHP_FUNCTION(get_array_memory_address)
{
zval *var;
char r[100];
if( zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a", &var) == FAILURE ) {
RETURN_NULL();
}
sprintf(r, "%p", Z_ARRVAL_P(var));
RETURN_STRING(r, 1);
}
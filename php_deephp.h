#ifndef PHP_DEEPHP_H
#define PHP_DEEPHP_H 1

#define PHP_DEEPHP_EXT_VERSION "1.0"
#define PHP_DEEPHP_EXT_EXTNAME "deephp"

PHP_FUNCTION(get_memory_address);

extern zend_module_entry deephp_module_entry;
#define phpext_deephp_ptr &deephp_module_entry

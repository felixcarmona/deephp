#define PHP_DEEPHP_EXT_VERSION "1.0"
#define PHP_DEEPHP_EXT_EXTNAME "deephp"

#include "lib/function_list.h"

extern zend_module_entry deephp_module_entry;
#define phpext_deephp_ptr &deephp_module_entry
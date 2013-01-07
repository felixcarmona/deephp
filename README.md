install
=======
phpize it and compile (phpize && chmod u+x configure && ./configure && make) and add "extension=/path/deephp.so" in your php php.ini file

perform a variable pointer (for now only supports 'Z_ARRVAL_P')
============================================================
```php
<?php

$a = array(1, 2, 3, 4);
$b = array(6, 7, 8, 9);
$c = &$b;

var_dump(get_memory_address($a)); // string '0x123456' (length=8)
var_dump(get_memory_address($b)); // string '0x789abc' (length=8)
var_dump(get_memory_address($c)); // string '0x789abc' (length=8)
```

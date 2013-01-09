install
=======
phpize it and compile (phpize && ./configure && make) and add "extension=/path/deephp.so" in your php php.ini file

perform a variable pointer
==========================
```php
<?php

$a = array(1, 2, 3, 4);
$b = array(6, 7, 8, 9);
$c = &$b;

var_dump(get_memory_address($a)); // string(14) "0x7fc7f7559ff8"
var_dump(get_memory_address($b)); // string(14) "0x7fc7f7559ae0"
var_dump(get_memory_address($c)); // string(14) "0x7fc7f7559ae0"
```
(for now only supports 'Z_ARRVAL_P' (arrays))

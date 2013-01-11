install
=======
phpize it and compile (phpize && ./configure && make) and add "extension=/path/deephp.so" in your php php.ini file

perform a variable pointer
==========================
```php
<?php

$a = 'hello';
$b = array(6, 7, 8, 9);
$c = &$b;

var_dump(get_memory_address($a)); // string(14) "0x7fc7f7559ff8"
var_dump(get_memory_address($b)); // string(14) "0x7fc7f7559ae0"
var_dump(get_memory_address($c)); // string(14) "0x7fc7f7559ae0"
var_dump(is_referencing($a, $b)); // bool(false)
var_dump(is_referencing($c, $b)); // bool(true)
```

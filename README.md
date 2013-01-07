install
=======
phpize it and add "extension=/path/deephp.so" in the php php.ini file

perform a variable pointer
==========================
```php
<?php

$a = 12345;
$b = 67890;
$c = &$b;

var_dump(get_memory_address($a)); // string '0x123456' (length=8)
var_dump(get_memory_address($b)); // string '0x789abc' (length=8)
var_dump(get_memory_address($c)); // string '0x789abc' (length=8)
```

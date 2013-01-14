install
=======
phpize it and compile (phpize && ./configure && make) and add "extension=/path/deephp.so" in your php php.ini file


getting the memory address of a variable
-------
```php
$a = 'hello';
$b = array(1, 2, 3, 4);
$c = &$b;

var_dump(get_memory_address($a)); // string(14) "0x7fc7f7559ff8"
var_dump(get_memory_address($b)); // string(14) "0x7fc7f7559ae0"
var_dump(get_memory_address($c)); // string(14) "0x7fc7f7559ae0"
```

getting the memory data of a memory address
-------
```php
$a = 'hello';
$b = get_memory_address($a); // $b = "0x7fc7f7559ff8"

var_dump(get_memory_data($b)); // string(5) "hello"
```

check if two variables are in referencing
-------
```php
$a = 'hello';
$b = array(1, 2, 3, 4);
$c = &$b;

var_dump(are_referenced($a, $b)); // bool(false)
var_dump(are_referenced($c, $b)); // bool(true)
```

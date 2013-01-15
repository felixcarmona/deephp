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

reading the data of a memory address
-------
```php
$a = 'hello';
$b = get_memory_address($a); // $b = "0x7fc7f7559ff8"

var_dump(get_memory_data($b)); // string(5) "hello"
```

writing data in a memory address
-------
```php
$a = 'hello';
$b = get_memory_address($a); // $b = "0x7fc7f7559ff8"
$c = 'mynewcontent';

set_memory_data($b, $c);
var_dump($a); // string(5) "mynew" -> the PHP engine thinks $a lengths remain 5 ('hello') but the real length must be 12 ('mynewcontent')
var_dump(get_memory_data($b)); // string(12) "mynewcontent
"

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

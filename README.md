# C Utilities
## printutils.h
```C
/* VPRINT, verbose (debugging) print
 * VERBOSE must be defined, it currently is as 1
 */
 VPRINT("This is some verbose printing %s %d\n", "an additional string", 1234);
 ```
```
$ ./a.out
print_utils_test.c:5 (in function 'main'): This is some verbose printing an additional string 1234
$ 
```
```C
/* WARN
 * Print a warning to stderr
 */
 WARN("This is a warning %d %s\n", 1234, "it has another string...");
 ```
 ```
 $ ./a.out
 print_utils_test.c:5 (in function 'main'): This is some verbose printing an additional string 1234
 WARNING print_utils_test.c:6 (in function 'main'): This is a warning 1234 it has another string..."
 $ echo $?
 0
 $ 
 ```
 ```C
 /* FATAL
  * Print a message to stderr and exit(EXIT_FAILURE)
  */
FATAL("This is a fatal message %d %d %s\n", 12, 34, "string");
```
```
$ ./a.out
 print_utils_test.c:5 (in function 'main'): This is some verbose printing an additional string 1234
 WARNING print_utils_test.c:6 (in function 'main'): This is a warning 1234 it has another string..."
 FATAL print_utils_test.c:7 (in function 'main'): This is a fatal message %d %d %s\n", 12, 34, "string");
 $ echo $?
 1

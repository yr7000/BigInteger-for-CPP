# BigInteger-for-CPP
#### BigInteger-for-cpp is a C++ library, which can be used to perform various operations on very large numbers which may exceed the integer range.This tool will be helpful in competitive coding contest problems which has something to deal with very large numbers.
---

## How to use this in C++?
Download the [BigInteger.h](https://github.com/yr7000/BigInteger-for-CPP/blob/master/BigInteger.h) file and include it in your C++ program.
```c++
#include "BigInteger.h"     // Make sure that your file path is correct
```
---
## Declaration and Initialization.
Declaration is done by creating an object of bigint class.And initialization can be done by passing string or integer or long type at object creation time.
```c++
bigint x("325789823758324578945458743298598342523"); // Initialization with string 
bigint y(234533252153325);                           // Intialization with long type
```
---
## The Arithmetic Operations that can be performed with 2 or more bigint objects.
-  #### Addition
-  #### Subtraction
-  #### Multiplication
-  #### Division
-  #### Mod
-  ####Increment and decrement operators 
---
## Comparision Operations.
- #### Two bigint objects can be compared with the help of : >,<,>=,<=,==,!=
---
 
 ## In-Built Functions
 - #### to_bigint(), which takes one argument as string or int or long long type and returns a bigint          
 - #### big_abs(), which takes bigint as one argument and returns the absoulute value of it in bigint format itself.           
 - #### big_max(), which takes two bigint's as arguments and returns the maximum bigint.
 - #### big_min(), which takes two bigint's as arguments and returns the minimum bigint.
 - #### big_pow(), which takes two bigint's as arguments and returns first argument bigint to the power second argument bigint
 - #### big_sqrt(), which takes one bigint as argument and returns the square root of it in bigint format.
 - #### big_swap(), which takes two bigint's as arguments and swaps them.
 - #### big_gcd(), which takes two bigint's as arguments and returns the gcd of them in bigint format.
 - #### big_lcm(), which takes two bigint's as arguments and returns the lcm of them in bigint format.
 - #### bid_fact(), which takes one bigint as argument and returns the factorial of it in bigint format.
 - #### big_reverse(), which takes one bigint as argument and returns a bigint with reversed digits of argument.

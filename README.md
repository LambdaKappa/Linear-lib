# Description #

Linear Algebra library inspired by Python's 'Numpy' library. I am planning to restucture it completely and add much more to it in the following week.

# Examples of use #

You can include library in your code file like this:
```C++
#include "Linear.hpp"
```

#### Create a new Array ####

Library's "Matrix" class supports a variety of data types and has different constructors _(Currently choice is not that big)._

```C++
ln::Matrix<int> Matrix = {{1, 2, 3, 4, 5}}; 
```
```Ruby
Output:
[1, 2, 3, 4, 5]
```

#### Fill array with a value ####

```C++
ln::Matrix<double> values = ln::fill<double>(5, 5, ln::PI); // Creates a 5x5 array filled with pi
```

```Ruby
Output:
[[3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159]]
```

#### Find Matrix transpose ####

```C++
std::cout << Matrix;
```

```Ruby
Output:
[[1, 2],
 [5, 6],
 [2, 3]]
```

```C++
std::cout << Matrix.T();
```

```Ruby
Output:
[[1, 5, 2],
 [2, 6, 3]]
```

#### And much more. ####

Operations like Matrix multiplication are not well optimized and Numpy should handle big Matrices faster. 


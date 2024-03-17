# Description #

Linear Algebra library inspired by Python's 'Numpy' library. I am planning to restucture it completely in the following week.

# Examples of use #

You can include header of the library into your code file like this:
```C++
#include "Linear.hpp"
```

# Create a new Array #

Library's "Matrix" class supports a variety of data types and has different constructors _(Currently choice is not that big)._

```C++
ln::Matrix<int> Matrix = {{1, 2, 3, 4, 5}}; 
```
```Ruby
Output:
[1, 2, 3, 4, 5]
```

Fill array with a value

```C++
ln::Matrix<double> values = ln::fill<double>(5, 5, ln::PI); // Creates 5x5 array filled with pi
```

```Ruby
Output:
[[3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159],
 [3.14159, 3.14159, 3.14159, 3.14159, 3.14159]]
```


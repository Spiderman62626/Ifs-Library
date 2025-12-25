# Ifs Library

This library creates an organized and easily legible way to assign values with conditions.
**Note**: This library is for learning purposes only as many compilers already have optimizations for branching and the performance difference is mostly negligible.

## Features

- A function "ifs_" that returns a single value given conditions and values, similar to if-else chains but without branching.
- A function "ifs" that achieves the same as "ifs_" but with branching for cases where short-circuiting is helpful.

## Explanation

- Here is a simple and easy-to-read way to assign a variable depending on conditions:
  ```cpp
  int x;
  if (a == 0) { x = 0; } else if (a == 1) { x = 2; } else { x = 1; }
  ```
  However, this method creates branching that isn't handled by compilers and uses multiple lines.

- Next, ternary operators can be used to achieve the same result:
  ```cpp
  int x = (a == 0) ? 0 : ((a == 1) ? 2 : 1);
  ```
  This type of branching is handled by compilers and this statement is more compact. However, this can be difficult to read as it is less organized.

- This library includes a way to have these statements all in one line:
  ```cpp
  int x = ifs(
    1 // default value
    {a == 0, 0}, // {condition, value} format
    {a == 1, 2}
  );
  ```
  While the nature of it being a function will create some overhead, it is more organized than with ternary operators.

- This can also be done purely with calculations:
  ```cpp
  int x = (a == 0) * 0 + (a == 1) * 2 + (!(a == 0) * !(a == 1)) * 1;
  ```
  While this eliminates branching, it is still not very organized and can be difficult to read.

- Finally, this library uses the same formula as above but hide the calculations to keep organization:
  ```cpp
  int x = ifs_(
    1 // default value
    {a == 0, 0}, // {condition, value} format
    {a == 1, 2}
  );
  ```
  Here, the variable is assigned in an organized way while also using raw calculations to avoid branching.

- While the library can create organization, there can be further performance optimizations such as this:
  ```cpp
  int x = 1 - (a == 0) + (a == 1);
  ```
  However, finding these formulas can be tedious and unnecessary for many programs. In that case, this library hopes to simplify the process and organize conditional value assignments.

## Installation

- Put the library file in the project folder and the compiler will automatically find it when it sees this line:
  ```cpp
  #include "branchless.hpp"
  ```

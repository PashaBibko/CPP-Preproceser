# LX Syntax

### Variable declaration

LX is a staticly typed language. Similar to C++ you can declare a variable without defining it.

```C++
int var1 = 0;
int var2; // Undefined
```

### Types

##### Basic types:
- int (whole number)
- float (decimal value)
- char (single ASCII character)
- bool (true or false)
- void (empty)
- string (a list of characters)

When defining a variable using a type you can modify attributes of the type using the operator[].

This is how you mark a variable as const. Const variables must be defined at declaration and cannot be reassigned.

```C++
// Const integer worth 5
int[C] constVar = 5;
```

This is also how you define references to variables
```C++
// Integer worth 7
int var = 7;

// Creating a reference to it
int[R] ref = var;

// Modifying the reference
ref = ref + 1;

// Var is now worth 8
```

Int and float types have extra two attributes (signed, size).

```C++
// Simple declaration
int var;

// Unsigned int declaration
int[U] var;

// Small int declaration
int[S] var;

// There are 3 size:
// S(Small), N(Normal), L(Large)

// Creates a unsigned small int
int[ S, U ] var;
```

Char only can be signed and unsigned

### Simple Control Flow

If statement conditions are not required to be in brackets but must be followed by a colon. The following code must be in Braces. If no braces are found it will assume the next line of code is the contents.

```C++
if true:
    console::print("Condition is true");

console::print("This will not be in the if statement");
```

LX also supports elif and else

```C++
if false:
    console::print("This wont run");

elif true:
    console::print("But this will");

else:
    console::print("This also won't run");
```

### While loops

Similar to if-else statements while loops do not require brackets around the statement. The contents of the 

```C++
while True:
{
    console::print("Who else loves infinite loops");
}
```

You can also chain else off a while statement. The else statement will only run if the loop is never run.

```C++
while False:
{
    console::print("Loop never runs");
}

else
{
    console::print("But this does");
}
```

### For loops

LX takes inspiration from python for its for loops.

```Python
// Iterates upto 5
for i in [5]:
{
    console::print(i, "\t");
}

// Output:
// 0    1   2   3   4

```

You can modify what it starts iterating from and what it iterates by like this:
```C++
// Starts on 2
// Ends on 5
// Iterates 0.5 every loop
for i in [2, 5, 0.5]:
```

##### Range based for loops

You can iterate over items in a array/list/vector. The iterator(item in the example) will be a reference to the variable in the large data type. This means any modifications to it will also change the variable in the large data type.

```Python
for item in largeDataType:
{
    console::print(item);
}
```

### Logical operators

Logical operators can either be written as thier operator or word form. For example this:
``` C++
|| && !
```
Is the same as:
``` Python
or and not
```

### Function definition/declaration

LX has two types of functions: procedure and standard

Standard functions are defined as such:

```C++
func<int> main()
{
    return 0;
}
```

Procedure function calls are replaced with the function code (similar to inline functions in C++). For highest performace they are best used for frequently called simple functions. Such as setters and getters.

```C++
proc<int> getVar()
{
    return var;
}
```

Similiar to if statements if no braces are found it will assume the next line of code is the contents

```C++
proc<int> getVar()
    return var;
```

If no type is chosen the preprocessor will asume void.

Unlike in C++ you must provide a definition with the declaration. The preprocessor will make sure that there are no errors.
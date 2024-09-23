# Unique Valid Identifier

Define of the patterns of SPL identifiers using regular definitions/expressions:

```
[A-Za-z_][A-Za-z0-9_]*
```

Design a transition diagram for identifier recognition:

![img](idRecog.drawio.svg)

> WS means whitespace;
>
> OP means operators or brankets: `';',',','=','<','>','!','+','-','*','/','&','|','(',')','[',']','{','}'`

## Implementation

We use C++ to implement the analyzer. Please compile `uvi.cpp` with a compiler that supports C++20 or higher standard.

```
$ clang++ uvi.cpp -o analyzer -std=c++2a
```

Run the analyzer with

```
$ ./analyzer filename
```

in which filename is the input source code.

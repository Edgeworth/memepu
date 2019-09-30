#### Notes
Compound literals
Pointer arithmetic
Destructors
Modules

Operator overloading:
return of binary operators add, sub, mul, div must be same type as left


## Built-in types
i8, i16, i32, i64, u8, u16, u32, u64, bool, f32, f64

## Literals

## Operators and precedence

## Scoping

## Pointers and arrays

## Const

## Tagged unions

## Control flow
### If statement
### Match statement
### For loop
### ? operator

## Functions

## Templates

## Interfaces

## Structs
### Static functions

## Modules
### Visibility
names ending with _ are private, otherwise public.

## Inline assembly

## Compiler magic
### Indexable
### ConvertibleFrom
### Destructible
### LessThan
### Equals
### Auto
### Zero sized types


Compiler magic:
[u]int(8|16|24) satisfy Integral interface
Functions satisfy Callable
Indexable
Movable:

Copyable - available for everything, but can't override?
Iterable ?
LessThan -> defines other comparisons based on this? what about equals?
Equals

Generated impls: Destructible, Movable, Copyable

Need to generate destructor for stuff anyway.

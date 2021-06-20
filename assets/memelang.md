#### Notes
Compound literals
Pointer arithmetic
Destructors
Modules

Operator overloading:
return of binary operators add, sub, mul, div must be same type as left

function resolution:
first search for matching impl by implementing type. match using lowest distance.
then tries to perform deduction for the function call
todo: how to select intf when it depends on what the deduction for the fn call should be

scopes:
namespace, struct, enum, function, impl all have scope
scope has wildcard mapping. mapping can be to invalid type (no mapping yet)


typename: for defining a type
type: for instantiating a type defined by a typename

some constructs have both types and values - e.g. enum variants are types, but numbered variants
also may be treated as a value.
defining functions defines a type for that function, but referencing it in a function call
treats it as a value. but parsing e.g. malloc<u8> requires treating it as a type

these two are 'typevalues' - types that are treated as values. Typevalues must be unqualified.

ref: identifies a variable or a typevalue.

mappings:
several layers of mappings. e.g. for regular function calls:
function ref level mapping: malloc<u8> => T = u8
parameter level deduction mapping: memcpy(a, b, count): T = type of a
e.g. for impl calls for a struct

e.g. for interface impl calls

difficult parsing cases:
malloc<u8>();  // malloc<u8> is a bit like a type, but it's being used as a value
value: malloc<u8> = {};  // can't use it like this
e < d[3];  // this shouldn't try to ref e and think < starts template params
*something;  // parsing depends on whether something is a valid type or not

references - affect binding only

coercions - (const, ref) + ones for string / custom ones? interaction with type deduction
and what template types are resolved to

## Built-in types
i8, i16, i32, i64, u8, u16, u32, u64, bool, f32, f64

Can convert between built-in types explicitly using e.g. i16(var).

## Literals
signed and unsigned literals: 128, 128u => i32, u32

"string literal" => *u8

## Operators and precedence

## Expressions
### Member access
Member access can either be value.value or type.function.

## Scoping
Not allowed to declare variables shadowing another variable.

## Pointers and arrays

Arrays can be indexed by either signed or unsigned ints.

## Const

## References

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

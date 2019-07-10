
## Built-in types
i8, i16, i32, u8, u16, u32, bool, bit

## Literals
struct_lit : type LBRACE (IDENT ':' expr ',')* RBRACE ;
array_lit : '[]' | '[' expr (',' expr)* ']';
literal : STRING_LIT | CHAR_LIT | INTEGER_LIT | float_lit | bool_lit | struct_lit | array_lit;

## Operators and precedence
binary_op : '*' | '/' | '%' | '+' | '-' | '>' '>' | '<' '<' | '<=' | '>=' | '<' | '>'
    | '==' | '!=' |  '&' | '^' | '|' | '&&' | '||';
prefix_op : '~' | '-' | '!' | '&' | '*' ;
postfix_op : '++' | '--' ;
expr '[' expr ']'  // Array subscript
    | fn_call  // Function call
    | expr '.' (fn_call | IDENT)  // Member access
    | expr '?'  // Result syntactic sugar
<assoc=right> expr '?' expr ':' expr  // Ternary expression
    | <assoc=right> expr '=' expr  // Assignment
    | '(' expr ')' // Grouped expression

## Scoping
lexical scoping

## Pointers and arrays
pointer arithmetic

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
### Interface resolution

struct structA<T> {}
struct structB {}
intf intfA<T> {}
intf intfB {}

Defines an interface implementation for the set of types structA<T>.
impl<T> intfB for structA<T> {}

Defines a set of interface implementations intf<T> for structA<T>, where the
type T must be the same. The appropriate interface to use can be deduced from
the type of structA<T>.
impl<T> intfA<T> for structA<T> {}

Defines an interface implementation for a single type structB. Unambiguous.
impl intfB for structB {}

Defines a set of interface implementations intfA<T> for a single type structB.
Which interface to use must be inferred from the context.
impl<T> intfA<T> for structB {}

If we further define a specialisation, then there may be multiple options
impl intfA<u32> for structB {}


impl<T> intfA<u32> for structA<T> {}

impl intfA<u32> for structA<u32> {}

## Structs
### Static functions
### Bitfields

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
return optional for zero sized types

TODO:
casts
type coercions via interfaces e.g. ConvertibleFrom<type> for type
destructuring
 - structs
 - tuples
tuples

Maybe?
template values (dependent types)
pointers can't be null?
varargs?
trait bounds?
memory allocation (new)

No features:
- Multiple declarations in one line.
- Inheritance
- "->" operator
- Global variables
- Exceptions
- Type deduction based on return types / full unification
- Lambdas, closures
- Function overloading
- Default arguments
- Automatic decay into pointers
- slices

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

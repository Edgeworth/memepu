
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

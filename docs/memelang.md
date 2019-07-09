int8, uint8, int16, uint16, int32, uint32, pointers, f32, f64


Yes features:
functions - not first class
interfaces
strongly typed + type deduction
auto
structs
tagged unions (enums)
matching
generics
explicit implement interface
const
names ending with _ are private, otherwise public.
lexical scoping
inline assembly
package/modules
pointer arithmetic
destructors
postincrement
lexical scoping
zero sized types
 - return optional for zero sized types
static functions inside structs
operator overloading via magic interfaces
error handling: ? operator

arrays
destructuring
 - structs
 - tuples
tuples


Maybe?
template values (dependent types)
pointers can't be null?
varargs?
bitfields?
trait bounds?
slices?
type coercions?
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

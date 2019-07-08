int8, uint8, int16, uint16, int32, uint32, pointers, f32, f64


Yes features:
functions - not first class

interfaces

strongly typed + type deduction
auto

structs
Tagged unions (enums) + matching - switch case

generics - can be qualified with interfaces (?)
 - implies having first class functions? what if they are passed
template values

const
automatic decay into pointers
ending struct member var with _ makes it private. otherwise public.
lexical scoping

package/modules

const

inline assembly
pointer arithmetic

destructors

arrays

postincrement

lexical scoping

Maybe?
destructuring
default arguments
explicit implement interface
private/public stuff inside modules
error handling: tagged union result, ? operator
lambdas
varargs?
pointers can't be null?
bitfields?
static functions inside structs?
trait bounds?
operator overloading via magic interfaces
slices?
type coercions?
memory allocation (new)
zero sized types?
tuples? or just meme it with templates

No features:
- Multiple declarations in one line.
- Inheritance
- "->" operator
- Global variables
- Exceptions
- Type deduction based on return types / full unification
- Lambdas, closures
- Function overloading

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

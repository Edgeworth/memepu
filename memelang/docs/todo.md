notes for language - C like: memelang
data types:
int8, uint8, int16, uint16, int24, uint24, pointer

modules:
? visibility etc

Yes features:
functions - not first class
structs + unions(?)
generics - can be qualified with interfaces (?)
 - implies having first class functions? what if they are passed
strongly typed + type deduction
interfaces
 - kind of overlap generics?
function overloading
also need overload based on generic matching
const
automatic decay into pointers
ending struct member var with _ makes it private. otherwise public.
lexical scoping

No features:
lambdas - no; can be accomplished using interfaces + empty structs somehow or w/e
closures - no
inheritance - no
NO int, uint by themselves.
NO type coercions ?
NO multiple declaration in one go.


example code:
myfunc(int8 a, int8 b) int16 {
  return 15;
}

interface Readable<Val> {
  read() Val;
}

interface Destructible {
  destroy();
}

struct mystruct {
  int8 t;
}

struct mygenericstruct<T> {
  T t;

  read(int8 a) int8 {}
}

const mystruct m;

mygenericfunc<First: Integral, Second: Readable<int8>>(First a, Second b) int16 {
  return 16;
}

interface Iterator<T> {
  next() T*;
}

interface Iterable<T> {
  iter() Iterator<T>;
}

struct vector_iter<T> {
  vector<T>* vec_;
  int16 idx_;

  next() T* {
    if (idx_ == vec_.size()) {
      return nullptr;
    }
    return vec_[idx_++];
  }

  static new(vector<T>* vec) vector_iter<T> {
    return vector_iter<T> {
      vec_: vec;
      idx_: 0
    };
  }
}

struct vector<T> {
  T* data_;
  int16 size_;
  int16 capacity_;
  
  index(int16 index) T* {
    return data_[index];
  }

  push(T val) {
    if (size_ == capacity_) {
      capacity_ *= 2;
      T* newdata = malloc(capacity_ * sizeof(T));
      for (int16 i = 0; i < size_; i++) {
        newdata[i] = data_[i].move();
      }
      free(data_);
      data_ = newdata;
    }
    
    data_[size_++] = val;
  }

  pop() T {
    return data_[--size_].move();
  }

  size() int16 {
    return size_;
  }
  
  destroy() {
    for (int16 i = 0; i < size; i++) {
      data_[i].destroy();
    }
    free(data_);
  }

  move() vector<T> {
    vector<T> tmp = copy();
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
    return tmp;
  }

  iter() vector_iter<T> {
    return vector_iter<T>::new(this);
  }

  static new(int16 size) vector<T> {
    // Unspecified stuff set to 0 automatically for structs?
    // Structs with at least 1 private field can't be created except from static fn?
    return vector<T>{
      data_: nullptr,
      size_: 0,
      capacity_: 0,
    }.move();  // auto .move() for returns? but what if returning member var.
  }
}

swap<T>(T* a, T* b) {
  T c = a.move();
  a = b.move();
  b = c.move();
}

bubblesort<T>(vector<T>* v) {
  for (int16 i = 0; i < v.size(); ++i) {
    for (int16 j = 0; j < v.size() - 1; ++j) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

auto v = vector<int8>::new();
v.push(4);
v.push(3);
v.push(1);
bubblesort(v);

for (auto val : v) {
  // varargs?
  print(val);
}


Compiler magic:
[u]int(8|16|24) satisfy Integral interface
Functions satisfy Callable
Indexable
Movable ?
Copyable - available for everything, but can't override?
Iterable ?
LessThan -> defines other comparisons based on this? what about equals?
Equals

Generated impls: Destructible, Movable, Copyable

Need to generate destructor for stuff anyway.

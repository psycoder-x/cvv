# C++ vice versa

C++ features implemented in C

## C++ features

### Libraries

C++ standard libraries (not including C libraries of course).

Some functions, most likely overloads, are not implemented or implemented with a different signature

Libraries:
 * string

### Reference &

Each reference `&` will be replaced with a pointer `*`.
But each that pointer will be defined by name `CVV_REF` to save "reference meaning".
However, each const reference like `const T &` will be replaced with `T` for simplicity

### .t.h

C headers that contain templates have the extension `.t.h`

### cvv_max_size

The value of `max_size()` for all C++ classes

### cvv_npos

The value of `npos` for all C++ classes

### size_type

Is always `size_t` for simplicity

### Constructors and destructors

Suffix `_new` is used to specify a constructor

Suffix `_delete` is used to specify a destructor

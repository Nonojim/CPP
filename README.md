CppBible : https://en.cppreference.com/

In cpp "<<" is not just syntax : https://stackoverflow.com/questions/12772076/what-is-the-operator-for-in-c

Effective c++ by scott Meyers : https://dl.e-bookfa.ir/freebooks/Effective%20C++,%203rd%20Edition%20by%20Scott%20Meyers%20%28e-bookfa.ir%29.pdf

previous edition : https://ananyapam7.github.io/resources/C++/Scott_Meyers_Effective_Modern_C++.pdf

things to remember by Scott Meyers :
✦ Rules for effective C++ programming vary, depending on the part of
C++ you are using.

✦ For simple constants, prefer const objects or enums to #defines.
✦ For function-like macros, prefer inline functions to #defines.
✦ Declaring something const helps compilers detect usage errors. const
can be applied to objects at any scope, to function parameters and
return types, and to member functions as a whole.
✦ Compilers enforce bitwise constness, but you should program using
logical constness.
✦ When const and non-const member functions have essentially identi
cal implementations, code duplication can be avoided by having the
non-const version call the const version.

✦ Manually initialize objects of built-in type, because C++ only some
times initializes them itself.
✦ In a constructor, prefer use of the member initialization list to as
signment inside the body of the constructor. List data members in
the initialization list in the same order they’re declared in the class.
✦ Avoid initialization order problems across translation units by re
placing non-local static objects with local static objects.
✦ Compilers may implicitly generate a class’s default constructor, copy
constructor, copy assignment operator, and destructor.
✦ To disallow functionality automatically provided by compilers, de
clare the corresponding member functions private and give no imple
mentations. Using a base class like Uncopyable is one way to do this.

✦ Polymorphic base classes should declare virtual destructors. If a
class has any virtual functions, it should have a virtual destructor.
✦ Classes not designed to be base classes or not designed to be used
polymorphically should not declare virtual destructors.
✦ Destructors should never emit exceptions. If functions called in a
destructor may throw, the destructor should catch any exceptions,
then swallow them or terminate the program.
✦ If class clients need to be able to react to exceptions thrown during
an operation, the class should provide a regular (i.e., non-destruc
tor) function that performs the operation.
✦ Don’t call virtual functions during construction or destruction, be
cause such calls will never go to a more derived class than that of
the currently executing constructor or destructor.
✦ Have assignment operators return a reference to *this.
✦ Make sure operator= is well-behaved when an object is assigned to
itself. Techniques include comparing addresses of source and target
objects, careful statement ordering, and copy-and-swap.
✦ Make sure that any function operating on more than one object be
haves correctly if two or more of the objects are the same.
✦ Copying functions should be sure to copy all of an object’s data
members and all of its base class parts.
✦ Don’t try to implement one of the copying functions in terms of the
other. Instead, put common functionality in a third function that
both call.

✦ To prevent resource leaks, use RAII objects that acquire resources
in their constructors and release them in their destructors.
✦ Two commonly useful RAII classes are tr1::shared_ptr and auto_ptr.
tr1::shared_ptr is usually the better choice, because its behavior when copied is intuitive. Copying an auto_ptr sets it to null.
✦ Copying an RAII object entails copying the resource it manages, so
the copying behavior of the resource determines the copying behav
ior of the RAII object.
✦ Common RAII class copying behaviors are disallowing copying and
performing reference counting, but other behaviors are possible.

✦ APIs often require access to raw resources, so each RAII class
should offer a way to get at the resource it manages.
✦ Access may be via explicit conversion or implicit conversion. In general, explicit conversion is safer, but implicit conversion is more convenient for clients.

✦ If you use [] in a new expression, you must use [] in the corresponding delete expression. If you don’t use [] in a new expression, you mustn’t use [] in the corresponding delete expression.
✦ Store newed objects in smart pointers in standalone statements.
Failure to do this can lead to subtle resource leaks when exceptions
are thrown.

✦ Good interfaces are easy to use correctly and hard to use incorrectly.
You should strive for these characteristics in all your interfaces.
✦ Ways to facilitate correct use include consistency in interfaces and
behavioral compatibility with built-in types. 
✦ Ways to prevent errors include creating new types, restricting opera
tions on types, constraining object values, and eliminating client re
source management responsibilities.
✦ tr1::shared_ptr supports custom deleters. This prevents the cross
DLL problem, can be used to automatically unlock mutexes (see
Item 14), etc.

✦ Class design is type design. Before defining a new type, be sure to
consider all the issues.

✦ Prefer pass-by-reference-to-const over pass-by-value. It’s typically
more efficient and it avoids the slicing problem. 
✦ The rule doesn’t apply to built-in types and STL iterator and func
tion object types. For them, pass-by-value is usually appropriate.

✦ Never return a pointer or reference to a local stack object, a refer
ence to a heap-allocated object, or a pointer or reference to a local
static object if there is a chance that more than one such object will
be needed.

✦ Declare data members private. It gives clients syntactically uniform
access to data, affords fine-grained access control, allows invariants
to be enforced, and offers class authors implementation flexibility.
✦ protected is no more encapsulated than public.

✦ Prefer non-member non-friend functions to member functions. Do
ing so increases encapsulation, packaging flexibility, and functional
extensibility

✦ If you need type conversions on all parameters to a function (includ
ing the one that would otherwise be pointed to by the this pointer),
the function must be a non-member.

✦ Provide a swap member function when std::swap would be inefficient
for your type. Make sure your swap doesn’t throw exceptions.
✦ If you offer a member swap, also offer a non-member swap that calls
the member. For classes (not templates), specialize std::swap, too.
✦ When calling swap, employ a using declaration for std::swap, then call
swap without namespace qualification.
✦ It’s fine to totally specialize std templates for user-defined types, but
never try to add something completely new to std.

✦ Postpone variable definitions as long as possible. It increases pro
gram clarity and improves program efficiency.

✦ Avoid casts whenever practical, especially dynamic_casts in perfor
mance-sensitive code. If a design requires casting, try to develop a
cast-free alternative. 
✦ When casting is necessary, try to hide it inside a function. Clients
can then call the function instead of putting casts in their own code.
✦ Prefer C++-style casts to old-style casts. They are easier to see, and
they are more specific about what they do.

✦ Avoid returning handles (references, pointers, or iterators) to object
internals. Not returning handles increases encapsulation, helps
const member functions act const, and minimizes the creation of
dangling handles.

✦ Exception-safe functions leak no resources and allow no data struc
tures to become corrupted, even when exceptions are thrown. Such
functions offer the basic, strong, or nothrow guarantees.
✦ The strong guarantee can often be implemented via copy-and-swap,
but the strong guarantee is not practical for all functions.
✦ A function can usually offer a guarantee no stronger than the weak
est guarantee of the functions it calls.

✦ Limit most inlining to small, frequently called functions. This facili
tates debugging and binary upgradability, minimizes potential code
bloat, and maximizes the chances of greater program speed.
✦ Don’t declare function templates inline just because they appear in
header files.

✦ The general idea behind minimizing compilation dependencies is to
depend on declarations instead of definitions. Two approaches
based on this idea are Handle classes and Interface classes.
✦ Library header files should exist in full and declaration-only forms.
This applies regardless of whether templates are involved.

✦ Public inheritance means “is-a.” Everything that applies to base
classes must also apply to derived classes, because every derived
class object is a base class object.

✦ Names in derived classes hide names in base classes. Under public
inheritance, this is never desirable. 
✦ To make hidden names visible again, employ using declarations or
forwarding functions.

✦ Inheritance of interface is different from inheritance of implementa
tion. Under public inheritance, derived classes always inherit base
class interfaces.
✦ Pure virtual functions specify inheritance of interface only. 
✦ Simple (impure) virtual functions specify inheritance of interface
plus inheritance of a default implementation. 
✦ Non-virtual functions specify inheritance of interface plus inherit
ance of a mandatory implementation.

✦ Alternatives to virtual functions include the NVI idiom and various
forms of the Strategy design pattern. The NVI idiom is itself an ex
ample of the Template Method design pattern.
✦ A disadvantage of moving functionality from a member function to a
function outside the class is that the non-member function lacks ac
cess to the class’s non-public members.
✦ tr1::function objects act like generalized function pointers. Such ob
jects support all callable entities compatible with a given target sig
nature.

✦ Never redefine an inherited non-virtual function.

✦ Never redefine an inherited default parameter value, because default
parameter values are statically bound, while virtual functions — the
only functions you should be redefining — are dynamically bound.

✦ Composition has meanings completely different from that of public
inheritance. 
✦ In the application domain, composition means has-a. In the imple
mentation domain, it means is-implemented-in-terms-of.

✦ Private inheritance means is-implemented-in-terms of. It’s usually
inferior to composition, but it makes sense when a derived class
needs access to protected base class members or needs to redefine
inherited virtual functions.
✦ Unlike composition, private inheritance can enable the empty base
optimization. This can be important for library developers who strive
to minimize object sizes.

✦ Multiple inheritance is more complex than single inheritance. It can
lead to new ambiguity issues and to the need for virtual inheritance. 
✦ Virtual inheritance imposes costs in size, speed, and complexity of
initialization and assignment. It’s most practical when virtual base
classes have no data.
✦ Multiple inheritance does have legitimate uses. One scenario in
volves combining public inheritance from an Interface class with
private inheritance from a class that helps with implementation.


✦ Both classes and templates support interfaces and polymorphism. 
✦ For classes, interfaces are explicit and centered on function signa
tures. Polymorphism occurs at runtime through virtual functions. 
✦ For template parameters, interfaces are implicit and based on valid
expressions. Polymorphism occurs during compilation through tem
plate instantiation and function overloading resolution.

✦ When declaring template parameters, class and typename are inter
changeable.
✦ Use typename to identify nested dependent type names, except in
base class lists or as a base class identifier in a member initializa
tion list.

✦ In derived class templates, refer to names in base class templates
via a “this->” prefix, via using declarations, or via an explicit base
class qualification.

✦ Templates generate multiple classes and multiple functions, so any
template code not dependent on a template parameter causes bloat.
✦ Bloat due to non-type template parameters can often be eliminated
by replacing template parameters with function parameters or class
data members.
✦ Bloat due to type parameters can be reduced by sharing implemen
tations for instantiation types with identical binary representations.

✦ Use member function templates to generate functions that accept all
compatible types.
✦ If you declare member templates for generalized copy construction
or generalized assignment, you’ll still need to declare the normal
copy constructor and copy assignment operator, too.

✦ When writing a class template that offers functions related to the
template that support implicit type conversions on all parameters,
define those functions as friends inside the class template.

✦ Traits classes make information about types available during com
pilation. They’re implemented using templates and template special
izations. 
✦ In conjunction with overloading, traits classes make it possible to
perform compile-time if...else tests on types.

✦ Template metaprogramming can shift work from runtime to com
pile-time, thus enabling earlier error detection and higher runtime
performance.
✦ TMP can be used to generate custom code based on combinations of
policy choices, and it can also be used to avoid generating code in
appropriate for particular types.

✦ set_new_handler allows you to specify a function to be called when
memory allocation requests cannot be satisfied.
✦ Nothrow new is of limited utility, because it applies only to memory
allocation; associated constructor calls may still throw exceptions.

✦ There are many valid reasons for writing custom versions of new and
delete, including improving performance, debugging heap usage er
rors, and collecting heap usage information.

✦ operator new should contain an infinite loop trying to allocate mem
ory, should call the new-handler if it can’t satisfy a memory request,
and should handle requests for zero bytes. Class-specific versions
should handle requests for larger blocks than expected.
✦ operator delete should do nothing if passed a pointer that is null.
Class-specific versions should handle blocks that are larger than ex
pected.

✦ When you write a placement version of operator new, be sure to write
the corresponding placement version of operator delete. If you don’t,
your program may experience subtle, intermittent memory leaks.
✦ When you declare placement versions of new and delete, be sure not
to unintentionally hide the normal versions of those functions.

✦ Take compiler warnings seriously, and strive to compile warning
free at the maximum warning level supported by your compilers.
✦ Don’t become dependent on compiler warnings, because different
compilers warn about different things. Porting to a new compiler
may eliminate warning messages you’ve come to rely on.

✦ The primary standard C++ library functionality consists of the STL,
iostreams, and locales. The C89 standard library is also included.
✦ TR1 adds support for smart pointers (e.g., tr1::shared_ptr), general
ized function pointers (tr1::function), hash-based containers, regular
expressions, and 10 other components.
✦ TR1 itself is only a specification. To take advantage of TR1, you need
an implementation. One source for implementations of TR1 compo
nents is Boost.

✦ Boost is a community and web site for the development of free, open
source, peer-reviewed C++ libraries. Boost plays an influential role
in C++ standardization.
✦ Boost offers implementations of many TR1 components, but it also
offers many other libraries, too.

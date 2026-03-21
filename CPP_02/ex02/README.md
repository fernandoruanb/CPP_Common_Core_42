
<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-cpp-bonus.png" alt="CPP 02 cover" width="100%">
</p>

<h1 align="center">
  <a href="https://github.com/fernandoruanb/CPP-02">
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/cppm.png" alt="CPP 02 badge" width="200">
  </a>
  <br>
  CPP Module 02
  <br>
</h1>

<h4 align="center">
  A deeper exploration of <a href="https://isocpp.org/" target="_blank">C++</a> through orthodox canonical form, operator overloading, and fixed-point arithmetic at École 42.
</h4>

<p align="center">
  <img src="https://img.shields.io/badge/Final%20Score-80%2F100-00C853?style=for-the-badge" alt="Final Score 80/100">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus" alt="Language C++">
  <img src="https://img.shields.io/badge/Module-CPP%2002-blueviolet?style=for-the-badge" alt="CPP 02">
  <img src="https://img.shields.io/badge/Bonus-Not%20Included-lightgrey?style=for-the-badge" alt="No Bonus">
</p>

<p align="center">
  <a href="#about-the-module">About</a> •
  <a href="#ex00-my-first-class-in-orthodox-canonical-form">ex00: My First Class in Orthodox Canonical Form</a> •
  <a href="#ex01-towards-a-more-useful-fixed-point-number-class">ex01: Towards a more useful Fixed-Point number class</a> •
  <a href="#ex02-now-were-talking">ex02: Now we're talking</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#team">Team</a>
</p>

---

## About the Module

**CPP Module 02** is where C++ starts demanding more discipline from the programmer.

If the previous module introduced memory allocation, references, file handling, and dispatch mechanisms, this one shifts the focus toward **control over object behavior**, **copy semantics**, and **numeric representation**.

The module revolves around three major ideas:

- the **Orthodox Canonical Form**
- **operator overloading**
- the concept of **fixed-point numbers**

At first glance, these topics may seem disconnected.

But together, they teach something deeper:

> a class is not only about storing data — it is also about defining exactly how an object is created, copied, assigned, compared, transformed, and interpreted.

That is one of the first major mindset upgrades in C++.

### Why the Orthodox Canonical Form matters

One of the central lessons of this module is understanding why it is so important to explicitly define how a class behaves in the following situations:

- default construction
- destruction
- copy construction
- copy assignment

If we do not define that behavior ourselves, the compiler may generate it automatically.

And while that can sometimes work, it also means we are no longer fully deciding what happens to our objects.

That loss of explicit control can become dangerous when the class evolves, especially if it starts managing resources directly or indirectly.

The Orthodox Canonical Form exists to prevent that kind of passivity.

It encourages the programmer to take responsibility for the object's lifecycle and copying rules from the start.

That alone already makes it an important mental shift.

### Operators and class expressiveness

Another major part of the module is learning that operators are not magical built-in actions that classes must accept blindly.

In C++, we can teach the language how an object should behave when operators are used with it.

That means we can define what should happen when we write expressions such as:

- `a + b`
- `a > b`
- `++a`
- `a++`

This is powerful because it allows our classes to behave in a natural and expressive way, while still remaining under programmer control.

Used correctly, operator overloading makes code clearer and more intuitive.

### Fixed-point numbers

The final major concept of the module is **fixed-point arithmetic**.

In many situations, we work with:

- integers
- floating-point values

But floating-point representations can introduce precision issues depending on the context.

A fixed-point number offers another strategy.

Instead of storing the value as a raw floating-point number, we store it internally as an **integer**, while reserving a fixed number of bits to represent the fractional part.

In this module, the chosen fractional precision is based on **8 bits**.

That means:

- the internal storage remains integer-based
- the value still represents fractional quantities
- conversion logic allows us to move between integer, float, and fixed-point representations

This idea is especially relevant in areas such as:

- graphics
- games
- embedded logic
- systems where predictable numeric representation matters

So even though the module is still introductory, the core concept behind it connects directly to practical computing.

---

## ex00: My First Class in Orthodox Canonical Form

The first exercise introduces the class in its most foundational disciplined form.

This is the moment where the module says:

> do not leave the lifecycle of your objects to vague assumptions.

The exercise focuses on implementing the class with the expected canonical members:

- default constructor
- copy constructor
- copy assignment operator
- destructor

### Why this matters

This structure is important because objects are constantly being:

- created
- copied
- assigned
- destroyed

If the programmer does not explicitly think about those transitions, the compiler may still allow the program to run, but the object's behavior becomes less intentional.

In a simple exercise, that may appear harmless.

In a larger project, that can become the root of subtle bugs and poor design decisions.

So the real lesson of **ex00** is not only “write these four members.”

It is:

**understand that object control begins at the lifecycle level.**

### A key mindset shift

This exercise is also one of the first times where the student starts seeing class design not as “just putting functions inside a type,” but as defining a behavioral contract.

That contract answers questions such as:

- How does this object start existing?
- What happens when one object becomes a copy of another?
- What exactly does assignment mean for this class?
- What should happen when the object dies?

Those are serious design questions, and **CPP 02** makes them explicit.

---

## ex01: Towards a more useful Fixed-Point number class

The second exercise introduces the real conceptual heart of the module:

**fixed-point representation**.

Now the class stops being only a structural exercise and starts representing a meaningful numeric abstraction.

### What fixed-point means here

Instead of storing a floating-point value directly, the class stores an integer that represents the number with a fixed fractional scaling.

In practice, that means:

- the raw internal value is an integer
- part of its bits represent the fractional precision
- conversion functions reconstruct the equivalent numeric meaning

With **8 fractional bits**, a value is effectively scaled before storage.

That lets the class preserve fractional information while keeping an integer-based internal representation.

### Why this is useful

This is important because floating-point arithmetic, while powerful, is not always the best representation when we want more predictable control over stored values.

A fixed-point model can be preferable when we want:

- stable scaled values
- predictable internal representation
- tighter control over conversion behavior

So this exercise is not just about implementing setters and getters.

It is about understanding that numbers themselves can be modeled in different ways depending on what the program needs.

### What the exercise reinforces

Here, the student starts connecting multiple concepts at once:

- canonical form
- raw internal representation
- integer-to-fixed conversion
- float-to-fixed conversion
- fixed-to-float reconstruction
- fixed-to-int extraction

That makes **ex01** one of the first modules where abstraction starts feeling genuinely technical rather than merely syntactic.

---

## ex02: Now we're talking

The final exercise expands the fixed-point class into something much more expressive.

Now the class must behave more like a real numeric type.

And this is where **operator overloading** becomes central.

### Teaching the class how to behave

In this exercise, we define how the fixed-point object should react to operations such as:

- comparison
- arithmetic
- increment
- decrement
- min / max selection

This is the point where the class stops being only a container for a value and becomes a proper participant in expressions.

That matters a lot.

Because from the programmer's point of view, writing code such as:

```cpp
Fixed a;
Fixed b;

if (a < b)
	std::cout << "a is smaller" << std::endl;
````

feels natural.

But that natural appearance only exists because the programmer explicitly taught the class what `<` means.

### Why this is powerful

Operator overloading gives the programmer a much higher level of expressiveness.

Instead of forcing every action into awkward method calls, we can make the code resemble the intent of normal arithmetic and comparison.

That makes the class:

* easier to use
* easier to read
* more intuitive in expressions
* closer to the behavior of built-in numeric types

But that power also comes with responsibility.

A badly overloaded operator can make code confusing.

A well-designed one makes the abstraction elegant.

That balance is one of the great lessons of this exercise.

### The deeper lesson

The final exercise of the module shows that C++ classes are not passive boxes.

They can be designed to integrate directly with the language's syntax and behavior model.

That is a major step forward.

It means the programmer is no longer just using the language.

He is actively shaping how the language interacts with his own types.

---

## How To Use

Each exercise lives in its own folder and can be compiled independently.

### ex00

Compile:

```bash
make
```

Run:

```bash
./fixed
```

### ex01

Compile:

```bash
make
```

Run:

```bash
./fixed
```

### ex02

Compile:

```bash
make
```

Run:

```bash
./fixed
```

---

## Team

**CPP Module 02** is an individual project at **École 42**.

So all exercises in this module were developed individually by me.

---

## Final Note

**CPP 02** is one of those modules that looks small on the surface, but changes the way we think about classes.

It teaches that a class must not only exist.

It must define:

* how it is born
* how it is copied
* how it is assigned
* how it stores meaning
* how it behaves inside expressions

Through the Orthodox Canonical Form, operator overloading, and fixed-point representation, this module strengthens the student's control over both **object design** and **numeric abstraction**.

For me, **CPP 02** was the point where C++ started to feel less like “C with classes” and more like a language where types can be shaped with real precision.

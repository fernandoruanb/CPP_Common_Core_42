<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-cpp-bonus.png" alt="CPP 01 cover" width="100%">
</p>

<h1 align="center">
  <a href="https://github.com/fernandoruanb/CPP-01">
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/cppm.png" alt="CPP 01 badge" width="200">
  </a>
  <br>
  CPP Module 01
  <br>
</h1>

<h4 align="center">
  A deeper introduction to <a href="https://isocpp.org/" target="_blank">C++</a> through memory allocation, references, file handling, and function dispatch at École 42.
</h4>

<p align="center">
  <img src="https://img.shields.io/badge/Final%20Score-100%2F100-00C853?style=for-the-badge" alt="Final Score 100/100">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus" alt="Language C++">
  <img src="https://img.shields.io/badge/Module-CPP%2001-blueviolet?style=for-the-badge" alt="CPP 01">
  <img src="https://img.shields.io/badge/Bonus-Completed-brightgreen?style=for-the-badge" alt="Bonus Completed">
</p>

<p align="center">
  <a href="#about-the-module">About</a> •
  <a href="#ex00-braiiiiiinnnzzzZ">ex00: BraiiiiiiinnnzzzZ</a> •
  <a href="#ex01-moar-brainz">ex01: Moar brainz!</a> •
  <a href="#ex02-hi-this-is-brain">ex02: HI THIS IS BRAIN</a> •
  <a href="#ex03-unnecessary-violence">ex03: Unnecessary violence</a> •
  <a href="#ex04-sed-is-for-losers">ex04: Sed is for losers</a> •
  <a href="#ex05-harl-20">ex05: Harl 2.0</a> •
  <a href="#ex06-harl-filter">ex06: Harl filter</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#bonus">Bonus</a> •
  <a href="#team">Team</a>
</p>

---

## About the Module

**CPP Module 01** is the moment where the C++ journey starts becoming more concrete.

If **CPP 00** introduced the first contact with classes, streams, and object-oriented structure, **CPP 01** pushes that understanding further by focusing on topics that are fundamental for real control over program behavior:

- stack and heap allocation
- dynamic memory management
- constructors and destructors
- references and pointers
- file input and output
- dispatching behavior without relying on long chains of `if`

This module feels like a bridge.

On one side, it still carries the discipline learned from C:
manual reasoning, memory awareness, explicit control.

On the other side, it reveals how C++ can provide cleaner abstractions and more expressive tools once we understand how to use them correctly.

During this module, I deepened my understanding of:

- object lifetime
- persistent vs temporary allocation
- when `new` and `delete` matter
- the difference between pointers and references
- file manipulation with standard C++ libraries
- cleaner ways to dispatch behavior through function pointers to member functions

One interesting side note is that static member functions could conceptually solve some problems by allowing behavior to be called without a ready-made object. Even so, to stay as aligned as possible with the spirit of the subject and the learning goals of the module, I preferred not to rely on that approach where it was unnecessary.

That made **CPP 01** more than just a syntax exercise.

It became a module about understanding **why an object lives where it lives**, **how long it survives**, and **how different forms of access change the design of a program**.

---

## ex00: BraiiiiiiinnnzzzZ

The first exercise introduces one of the most important topics in C++:

**memory allocation and object lifetime**.

The challenge revolves around creating Zombies in two different ways:

- one allocated dynamically on the **heap**
- one created locally on the **stack**

This immediately creates an important design question:

> When is it useful to create an object that persists beyond the current scope, and when is it better to keep it local and automatic?

### Heap vs Stack

A Zombie allocated on the heap is created with dynamic allocation and remains alive until we explicitly destroy it.

That means:

- it can be returned
- it can be shared with other parts of the program
- it survives beyond the local function scope
- but it also creates the responsibility of calling `delete` correctly

A Zombie created on the stack behaves differently:

- it lives only inside its scope
- it is destroyed automatically when the function ends
- its destructor is called by the system at the right moment
- it is simpler and safer when persistence is not needed

That is the heart of the exercise.

If the Zombie needs to outlive the function and be used elsewhere, heap allocation makes sense.

If not, stack allocation is often the cleaner and safer choice.

This exercise is small, but it teaches a foundational lesson:

**not every object should live the same way**.

And understanding that distinction is one of the first real steps toward writing better C++.

---

## ex01: Moar brainz!

In the second exercise, the idea expands from a single Zombie to an entire **Zombie horde**.

Now the challenge is not just to create one object correctly, but to allocate and organize many of them together and later free them properly.

This exercise makes dynamic allocation feel more practical, because we start thinking in terms of collections instead of isolated instances.

### Building a horde

The goal is to create multiple Zombies in a contiguous dynamic allocation and initialize them correctly.

This reinforces several ideas at once:

- allocation of arrays of objects
- calling constructors across a sequence
- managing object identity inside a group
- cleaning everything safely afterward

In C, something like this would often feel more manual and more fragile.

In C++, the language still requires responsibility, but the object model makes the design much clearer.

### Extra care in my implementation

I used a more playful style in this exercise to make the program more enjoyable for whoever tests it.

For example:

- more stylized outputs
- a light narrative tone
- comments to guide the reader
- a magician-like interaction to make the horde creation more fun to observe

I also decided to implement my own `ft_atoi`.

This was not a strict subject requirement, but it was a deliberate robustness choice.

Many C++ projects I evaluated suffered from overflow and underflow problems because the conversion step was trusted too easily. I preferred to treat that more carefully and keep the code safer and more controlled.

So while the official goal was about Zombie hordes, the practical lesson for me was broader:

**when input exists, robustness matters**.

---

## ex02: HI THIS IS BRAIN

This exercise is the first direct study of **pointers and references**.

And even though the code itself is short, the concept behind it is central to all future C++ work.

The exercise shows the same string being accessed in three ways:

- directly
- through a pointer
- through a reference

That comparison helps reveal how each mechanism behaves.

### Pointers

Pointers:

- store addresses
- have their own address
- can be reassigned
- can be null
- can be dereferenced to access the object they point to

Because of that, pointers are flexible, but they also require more care.

### References

References behave differently.

A reference is an alias to an existing object.

That means:

- it must be bound to something valid
- it is not meant to be null
- it does not act like an independent reseatable pointer
- operating through it affects the original object directly

This makes references feel more stable and more constrained.

And that constraint is often exactly what makes them expressive.

### A subtle but important distinction

One of the useful mindset shifts from this exercise is understanding that pointers and references are not just two syntaxes for the same thing.

They communicate different intentions.

A pointer often says:

> this association may change, may be missing, or may require explicit checking

A reference often says:

> this object must exist, and I want another name for it

That distinction becomes very important in the next exercise.

---

## ex03: Unnecessary violence

This exercise transforms the pointer/reference discussion into a small weapon system.

We are introduced to:

- `Weapon`
- `HumanA`
- `HumanB`

And the real lesson is hidden in how each human stores access to its weapon.

### HumanA

`HumanA` uses a **reference** to a weapon.

That means it must always have a valid weapon from the very beginning.

It cannot exist in an unarmed state through that member relationship.

This is a design that communicates certainty.

### HumanB

`HumanB` uses a **pointer** to a weapon.

That means it can:

- start without a weapon
- receive one later
- change weapons over time
- conceptually represent the absence of a weapon

This makes `HumanB` more flexible, but also more dependent on checking whether the pointer is valid before use.

### Why this exercise matters

This is a very elegant exercise because it turns an abstract concept into behavior you can immediately observe.

It shows that the difference between references and pointers is not just technical.

It changes the design of a class.

One communicates:

- guaranteed association

The other communicates:

- optional association

And that is a design lesson that extends far beyond this module.

---

## ex04: Sed is for losers

This exercise shifts the focus toward **file manipulation**.

Now the challenge is to open a file, read its content, replace occurrences of one string with another, and write the result to a new output file.

This is the moment where C++ starts showing very clearly how much expressive power it can offer compared to C.

### File handling with C++

To solve this exercise, we work with tools such as:

- `std::ifstream`
- `std::ofstream`
- `find`
- string slicing and concatenation

With these tools, a task that would usually feel significantly more manual in C becomes far more manageable.

That contrast was one of the most interesting parts of the exercise for me.

It reminded me of solving harder logic problems in competitive programming: sometimes the language does not solve the reasoning for you, but it gives you much better tools to express the solution once you understand it.

That was exactly the feeling here.

### Why the exercise is memorable

The title jokes that “sed is for losers,” but the deeper lesson is this:

once you understand the standard library, C++ can let you solve substantial problems with surprisingly little code.

Not because the problem is trivial.

But because the abstraction power is stronger.

That is one of the first moments in the C++ modules where the language starts feeling not only different from C, but strategically powerful.

---

## ex05: Harl 2.0

In this exercise, we work with **Harl**, a character that reacts differently depending on a complaint level.

At first, this may look like a small dispatch problem.

And that is exactly what it is.

But the interesting part is how we choose to organize that dispatch.

### Fighting repetitive `if`s

Instead of creating long repetitive conditional chains, this exercise can be structured with a cleaner dispatch style using **pointers to member functions**.

This creates something close to a manual routing table:

- we receive an input
- we compare it against known levels
- we choose the corresponding function to call

This approach is valuable because it makes the code:

- easier to extend
- easier to read
- less repetitive
- more aligned with structured design

So the important lesson here is not just making Harl complain.

It is discovering that behavior selection can be modeled more elegantly than stacking `if` after `if`.

---

## ex06: Harl filter

The last exercise expands the previous one.

If **ex05** was about selecting one behavior, **ex06** goes further by using the same dispatch idea to execute **multiple levels in sequence** depending on the chosen input.

This makes the design feel more powerful.

Instead of simply saying:

- call one function

we now reason more like this:

- find the starting point
- execute this level and the ones that follow

That transforms the dispatch mechanism into something closer to a filtered escalation system.

### What this exercise reinforces

This exercise strengthens the same lesson from **ex05**:

a structured dispatch mechanism can be much cleaner and more expressive than repetitive chains of conditions.

And more importantly, it expands our sense of what this technique can do.

It is no longer just a cleaner replacement for `if`.

It becomes a way to organize behavior in layers.

That is why this final exercise feels like a small expansion of consciousness inside the module: the same idea, when understood well, can do much more than it first seemed to promise.

---

## How To Use

Each exercise lives in its own folder and can be compiled independently.

### ex00

Compile:

```bash
make
````

Run:

```bash
./zombie
```

### ex01

Compile:

```bash
make
```

Run:

```bash
./zombieHorde
```

### ex02

Compile:

```bash
make
```

Run:

```bash
./brain
```

### ex03

Compile:

```bash
make
```

Run:

```bash
./violence
```

### ex04

Compile:

```bash
make
```

Run:

```bash
./replace <filename> <s1> <s2>
```

Example:

```bash
./replace input.txt hello world
```

### ex05

Compile:

```bash
make
```

Run:

```bash
./harlFilter "DEBUG"
```

### ex06

Compile:

```bash
make
```

Run:

```bash
./harlFilter "WARNING"
```

---

## Bonus

This module was completed in full, with **bonus**, and the final result was:

```text
100 / 100
```

That score is satisfying, of course.

But the true gain of **CPP 01** was the conceptual expansion it brought.

This module deepened my understanding of:

* memory lifetime
* heap vs stack
* dynamic allocation and cleanup
* references vs pointers
* file manipulation with standard C++ tools
* structured function dispatch

If **CPP 00** introduced the first mindset shift toward object-oriented programming, **CPP 01** made that shift more concrete by showing how memory, access, and behavior design interact in practice.

---

## Team

**CPP Module 01** is an individual project at **École 42**.

So all exercises in this module were developed individually by me.

---

## Final Note

CPP 01 may still look like an early module.

But it teaches some of the most fundamental ideas in all of C++.

It shows that writing in C++ is not only about creating classes.

It is about understanding:

* where an object lives
* how long it survives
* who owns it
* how it is accessed
* and how behavior can be routed cleanly

Through Zombies, weapons, file replacement, and Harl's complaints, this module builds a stronger foundation for everything that comes next.

For me, **CPP 01** was the module where C++ started to feel not only different from C, but strategically richer.


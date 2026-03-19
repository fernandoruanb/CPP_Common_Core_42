<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-cpp-bonus.png" alt="CPP 00 cover" width="100%">
</p>

<h1 align="center">
  <a href="https://github.com/fernandoruanb/CPP-00">
    <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/cppm.png" alt="CPP 00 badge" width="200">
  </a>
  <br>
  CPP Module 00
  <br>
</h1>

<h4 align="center">
  A first introduction to <a href="https://isocpp.org/" target="_blank">C++</a> through streams, classes, objects, and basic program design at École 42.
</h4>

<p align="center">
  <img src="https://img.shields.io/badge/Final%20Score-100%2F100-00C853?style=for-the-badge" alt="Final Score 100/100">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus" alt="Language C++">
  <img src="https://img.shields.io/badge/Module-CPP%2000-blueviolet?style=for-the-badge" alt="CPP 00">
  <img src="https://img.shields.io/badge/Bonus-Completed-brightgreen?style=for-the-badge" alt="Bonus Completed">
</p>

<p align="center">
  <a href="#about-the-module">About</a> •
  <a href="#ex00-megaphone">ex00: Megaphone</a> •
  <a href="#ex01-phonebook">ex01: PhoneBook</a> •
  <a href="#ex02-the-lost-account">ex02: The Lost Account</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#bonus">Bonus</a> •
  <a href="#team">Team</a>
</p>

---

## About the Module

**CPP Module 00** is the first step into the C++ world at **École 42**.

After spending so much time dealing with C, low-level reasoning, manual control, and procedural logic, this module introduces a new mindset:

- streams instead of `printf`
- classes instead of plain structures
- encapsulation instead of open access
- object-oriented design instead of only function-based organization

At first glance, the exercises look simple.

But that simplicity is deceptive.

This module is not really about building large systems yet.  
It is about learning how to **think in C++** for the first time.

And that shift matters.

Through these three exercises, I had my first practical contact with:

- C++ syntax and compilation
- `std::cout` and `std::getline`
- classes and objects
- private attributes and public getters
- formatting and data display
- validation of user input
- reproducing exact outputs through reverse engineering

That is what makes **CPP 00** such an important starting point.

---

## ex00: Megaphone

The first exercise is a very small program, but it already introduces useful reasoning.

The goal is to simulate a **megaphone**.

If no argument is passed, the program prints the default message required by the subject.

If one or more arguments are passed, the program converts lowercase ASCII letters into uppercase and prints the result as a louder version of the input.

In essence, the expected transformation is simple:

```text
hello world
````

becomes:

```text
HELLO WORLD
```

But there is an important detail here.

The focus is on **standard English ASCII letters**.
So this is not about handling every possible extended character or multibyte encoding. Characters such as `ç`, for example, are outside the intended scope of this exercise.

### A small extra care in my implementation

One interesting detail in my version of **ex00** is that I also implemented a special treatment for escaped sequences such as:

```text
oi\n\toi
```

So instead of just printing the raw backslashes, the program can interpret that input and produce:

* an uppercase `OI`
* followed by a newline
* then a tab
* then another `OI`

This was a refinement commented on by **Alexei aprotoce**, one of the most respected evaluators at **42 São Paulo**, and I decided to include it in my implementation.

During this phase, I was still very cautious about relying too much on ready-made functions.
Because of how strict earlier projects had trained my mindset, I tried to build as much as possible by hand, based on my own reasoning and analysis, avoiding native C++ helpers whenever I could.

Only later did I discover that some of those conveniences were actually allowed.

That made the exercise even more interesting, because it became not just a syntax introduction, but also a moment of transition in mentality.

---

## ex01: PhoneBook

The second exercise is where the module starts to feel more structural.

In **ex01**, the challenge is to build a small **phone book application** that stores up to **8 contacts**.

This is not a fully dynamic system.
It is intentionally constrained.

And that limitation is part of the learning process.

### Core behavior

The program supports a small command-line interaction flow where the user can:

* add contacts
* search existing contacts
* display selected contact details

When a contact is added successfully, it is stored in the phone book.

When the user types `SEARCH`, the program displays a table with summary information only.

That means the list view does **not** show:

* phone number
* darkest secret

To see the full contact data, the user must choose a valid index.

### Display formatting

One of the most characteristic rules of this exercise is the formatting constraint:

If a field contains more than **10 characters**, the visible output is truncated and the last displayed character becomes a `.`

So the display does not simply overflow.
It obeys a strict fixed-width presentation rule.

That detail may seem small, but it teaches precision.

### Validation and robustness

A lot of care in this project comes from input validation.

Some of the rules I treated in my version were:

* rejecting empty inputs
* validating the chosen index correctly
* preventing invalid text input where a number is expected
* avoiding values outside the `INT_MAX` / `INT_MIN` range
* treating `CTRL + D` properly to avoid infinite loops with `getline`

That last point is especially important.

Because the program behaves like a small prompt-driven interface, EOF handling matters a lot.
Without that care, the interaction can become unstable very quickly.

### Class design

This exercise introduces two core classes:

* `PhoneBook`
* `Contact`

Their attributes are expected to be **private**, which already enforces the idea of encapsulation from the beginning.

At this stage, using public getters that can be accessed by `main` or by `PhoneBook` is still acceptable and natural for the learning level of the module.

This project is not yet about inheritance, `protected`, or more advanced friendship rules.
It is about understanding the first clean separation between:

* stored data
* controlled access
* organized behavior

### Contact replacement logic

Another important subject rule is that the phone book only stores **8 contacts**.

So once it becomes full, adding a new contact must replace the oldest one.

This gives the program a circular replacement behavior instead of uncontrolled growth.

### Practical refinement

Beyond just meeting the subject, I also took care to improve the overall usability:

* clearer success and error messages
* prompt-oriented interaction
* data cleanup and formatting refinements
* visual styling improvements

In this exercise, AI was also used as support for:

* visual styling ideas
* colors
* discovery of useful functions
* examples of usage

So while the logic and structure were built as part of my learning process, tooling assistance helped refine presentation and ergonomics.

---

## ex02: The Lost Account

The third exercise is one of the most memorable in the module.

In **ex02**, we are asked to reconstruct a banking program based on an existing output log.

The subject introduces this with a humorous scenario:
the company was supposedly so outdated that it used pen drives instead of GitHub, and we were hired because we knew how to install Adobe Reader quickly enough to save the day.

Behind the joke, though, the core challenge is serious:

we must reproduce the **exact behavior** expected by the bank logs.

### What is the real task?

This exercise is basically a reverse engineering challenge.

We are given the expected output behavior, and then we must rebuild the logic method by method until our program produces the exact same result.

That means understanding:

* account creation
* deposits
* withdrawals
* status displays
* global statistics
* static attributes
* constructor and destructor effects
* exact output formatting

So the real difficulty is not “inventing any bank system.”

It is reproducing **this** bank system precisely.

### How to verify correctness

A very practical way to validate the implementation is to compare the official company log with the output generated by our own program.

For example:

```bash
cat companyLog.log | cut -d " " -f 2 > official.txt
cat account | cut -d " " -f 2 > test.txt
diff official.txt test.txt
```

If `diff` produces no output, then both files match.

That means the generated log is equivalent to the expected one.

This is a very clean way to test whether the reverse engineering work was successful.

### Important implementation notes

There are a few subtleties that matter here.

One of them is that the **destructor order** may vary depending on the environment, and the subject itself warns about that.

In most cases, this does not create a major problem.

Another important point is output consistency.

If `stdout` and `stderr` are mixed, visible differences may appear in the final generated file, which can break the comparison even if the logic is correct.

So for this exercise, it is much safer to keep everything on **stdout**.

### What this exercise teaches

This project is a surprisingly strong introduction to several C++ concepts at once:

* static class members
* object lifecycle
* precise formatting
* deterministic output
* behavior reconstruction from logs
* testing through output comparison

It feels simple on the surface.

But once you really start matching every line exactly, you realize how much attention to detail is required.

---

## How To Use

Each exercise lives in its own folder and can be compiled independently.

### ex00

Compile:

```bash
make
```

Run without arguments:

```bash
./megaphone
```

Run with arguments:

```bash
./megaphone "hello world"
```

### ex01

Compile:

```bash
make
```

Run:

```bash
./phonebook
```

Then use the available commands inside the program, such as:

```text
ADD
SEARCH
EXIT
```

### ex02

Compile:

```bash
make
```

Run:

```bash
./account
```

To compare your output with the reference log:

```bash
cat companyLog.log | cut -d " " -f 2 > official.txt
cat account | cut -d " " -f 2 > test.txt
diff official.txt test.txt
```

---

## Bonus

This module was completed with **bonus**, and the final result was:

```text
100 / 100
```

That score matters, of course.

But more important than the grade itself was what this module introduced.

**CPP 00** was my first real transition from C-style thinking into C++ structure.

It was where I started dealing with:

* objects
* encapsulation
* organized interfaces
* formatted output through streams
* class-based reasoning

So even though this is only the beginning of the C++ journey, it is already a meaningful turning point.

---

## Team

**CPP Module 00** is an individual project at **École 42**.

So all exercises in this module were developed individually by me.

---

## Final Note

CPP 00 may look like a small introductory module.

But it teaches something fundamental:

moving from C to C++ is not just changing syntax.

It is changing the way we organize logic.

Through a megaphone, a phone book, and a reconstructed bank logger, this module introduces the first pieces of a new programming mindset:

* structure
* encapsulation
* formatted interaction
* controlled access to data
* attention to object behavior

For me, **CPP 00** was not just an introduction to C++.

It was the first step toward thinking in a more organized and object-oriented way.


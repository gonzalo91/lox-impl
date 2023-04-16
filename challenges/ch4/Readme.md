1. The lexical grammars of Python and Haskell are not
regular. What does that mean, and why aren’t they?

R: Regular grammars are a class of formal languages that can be described by regular expressions. These grammars are characterized by a set of rules that define a regular language, which can be recognized by finite automata, such as deterministic or nondeterministic finite automata.

The lexical grammars of programming languages like Python and Haskell are not regular. This means that the rules that define the syntax of these languages are more complex than what can be described by regular expressions.

The syntax of programming languages like Python and Haskell is context-free, meaning that the grammar rules allow for nested structures and recursive definitions. This is necessary to define complex language constructs such as functions, classes, and data structures.

In short, the syntax of Python and Haskell is more expressive than what can be captured by regular expressions, which is why their lexical grammars are not regular.
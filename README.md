# Arbitrary_Precision_Calculator
A C-based Arbitrary Precision Calculator (APC) that performs addition, subtraction, multiplication, and division on unlimited-digit integers using Doubly Linked Lists. Designed to handle big-number arithmetic beyond standard data type limits with accurate carry/borrow management and a modular, menu-driven structure.
🚀 Overview

Modern programming languages impose limits on integer size (e.g., 2^31−1 for int in C). This calculator bypasses those limits by implementing big-number arithmetic manually.
Each number is represented as a Doubly Linked List, allowing:

Efficient forward & backward traversal

Simplified carry/borrow handling

Unlimited digit storage

Better memory efficiency

The system is designed to be modular, scalable, and easy to extend.

🔧 Key Features
✔ Arbitrary-Length Integer Support

Handles numbers with any number of digits — even thousands — limited only by system memory.

✔ Core Arithmetic Operations

Addition (digit-wise with carry)

Subtraction (digit-wise with borrow)

Multiplication (column-wise multiplication logic)

Division (long-division algorithm)

✔ Data Structure Used

Doubly Linked List for digit storage

Each node stores a single digit

Supports traversal from LSB → MSB and MSB → LSB

✔ Clean & Modular Architecture

The program is split into functional modules for:

Linked list creation & deletion

Input handling

Arithmetic operations

Display utilities

Menu-driven interface

✔ Linux & GCC Compatible

Designed and tested on Linux using the GCC compiler.

🧠 Learning Outcomes

Building this project strengthened understanding of:

Pointer manipulation

Dynamic memory allocation

Custom big-number arithmetic logic

Linked list traversal & operations

Modular C programming

Error handling and boundary conditions


# **Code Execution Time Comparison: Python, C++, and Java**

This repository contains multiple code programs implemented in Python, C++, and Java. The main objective is to compare the execution time of these programs across three different types of languages: a compiled language (C++), an interpreted language (Python), and a hybrid language (Java). 

## **Programs Included**

1. **Calculator**
    - A basic calculator that performs addition, subtraction, multiplication, and division.
  
2. **Sudoku Solver**
    - A program that solves Sudoku puzzles using a backtracking algorithm.

Each of these programs has been implemented in the following languages:
- **Python**: An interpreted language known for its simplicity and readability.
- **C++**: A compiled language renowned for its performance and efficiency.
- **Java**: A hybrid language that is compiled to bytecode, which is then interpreted by the Java Virtual Machine (JVM).

## **Objective**

The goal of this repository is to analyze and compare the execution time of the same algorithms when implemented in different types of programming languages. This comparison will help in understanding the performance trade-offs between compiled, interpreted, and hybrid languages.

## **Structure**

The repository is organized as follows:

```
├── Python
│   ├── Calculadora.py
│   └── Sudoku.py
│
├── C++
│   ├── Calculadora.cpp
│   └── Sudoku.cpp
│
├── Java
│   ├── Calculadora.java
│   └── Sudoku.java
│
└── README.md
```

### **Python**
- **Calculator**: `Calculadora.py`
- **Sudoku Solver**: `Sudoku.py`

### **C++**
- **Calculator**: `Calculadora.cpp`
- **Sudoku Solver**: `Sudoku.cpp`

### **Java**
- **Calculator**: `Calculadora.java`
- **Sudoku Solver**: `Sudoku.java`

## **Execution Instructions**

### **Python**
To run the Python programs, use the following commands:
```bash
python Calculadora.py
python Sudoku.py
```

### **C++**
To run the C++ programs, first compile them using a C++ compiler like `g++`, then execute:
```bash
g++ -o Calculadora Calculadora.cpp
./calculator

g++ -o Sudoku Sudoku.cpp
./Sudoku
```

### **Java**
To run the Java programs, first compile them using `javac`, then execute:
```bash
javac Calculadora.java
java Calculadora

javac Sudoku.java
java Sudoku
```

## **Execution Time Measurement**

The execution time of each program can be measured using the following methods:

### **Python**
Use the built-in `time` module to measure the execution time:
```python
import time

start_time = time.time()
# Your function call here
end_time = time.time()
print(f"Execution Time: {{end_time - start_time}} seconds")
```

### **C++**
Use the `<chrono>` library to measure the execution time:
```cpp
#include <iostream>
#include <chrono>

// Your function call here

auto start = std::chrono::high_resolution_clock::now();
// Your function call here
auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> duration = end - start;
std::cout << "Execution Time: " << duration.count() << " seconds" << std::endl;
```

### **Java**
Use `System.nanoTime()` to measure the execution time:
```java
long startTime = System.nanoTime();
// Your function call here
long endTime = System.nanoTime();
long duration = (endTime - startTime);
System.out.println("Execution Time: " + duration + " nanoseconds");
```

## **Comparison and Analysis**

After running each program, compare the execution times and analyze the differences. The analysis should consider the nature of the language (compiled vs. interpreted vs. hybrid) and how it impacts the performance of the same algorithm.

## **Conclusion**

This repository aims to provide insight into the performance characteristics of different programming languages when implementing common algorithms. By comparing the execution times, developers can make more informed decisions about which language to use based on the specific needs of their projects.

## **Contributions**

Contributions are welcome! If you'd like to improve the code, add new algorithms, or refine the execution time analysis, feel free to submit a pull request.

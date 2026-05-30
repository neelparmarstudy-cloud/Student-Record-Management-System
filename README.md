# Student Record Management System

A structural command-line workstation utility built in C designed to catalog, validate, track, and re-order student academic databases. The application uses memory pointers and explicit runtime dynamic memory allocations (`malloc` / `free`) to manage dataset bounds efficiently based on user parameters.

## 🚀 Key Features

### 🔹 Database Operations (CRUD)
* **Dynamic Student Profiling:** Tracks student names, unique numerical roll numbers, total raw marks, and corresponding **Semester Performance Index (SPI)** scales.
* **Inline Input Validation Filters:** * Rejects student name input if it contains non-alphabetic characters or numbers.
  * Enforces strict boundary parameters on marks (accepting integers between `0` and `100` exclusively).
* **Automated Grade Point Evaluator:** Parses marks directly against standard university thresholds to assign an SPI value ranging between `1.0` and `10.0`.
* **Record Mutation Cleanup:** Permanently shifts and drops elements from memory matrices when matching a specific student roll number.

### 🔹 Algorithmic Sorting Routines
The system avoids mutating original primary indices during execution by cleanly cloning active memory chunks onto the heap before passing them to specific algorithmic workflows:
* **Bubble Sort (Alphabetical & Numerical Tally):**
  * Sorts student blocks alphabetically by name via sequential `strcmp` evaluations.
  * Sorts records descending by grades to quickly map performance tiers.
* **Selection Sort (Sequential Matrix Boundaries):**
  * Sorts records ascending by roll numbers using lookahead minimum-index tracking loops.

---

## 📁 Repository Structure
📁 Student-Record-Management/
│
├── 📄 Student_record_management_System.c  # Core C program containing algorithms and runtime structures
├── 📄 .gitignore                          # Excludes platform binaries and object files
├── 📄 LICENSE                             # MIT License open-source terms
└── 📄 README.md                           # Project deployment documentation

🛠️ Tech Stack
Language: C (C99 standard or higher recommended for array index mapping loops)
Core Libraries: <stdio.h>, <stdlib.h>, <string.h>

⚙️ Compilation & Run Guide
To compile and launch this command-line data structure simulation:

1. Clone the Repository
Bash
git clone [https://github.com/neelparmarstudy-cloud/Student-Record-Management.git](https://github.com/neelparmarstudy-cloud/Student-Record-Management-System.git)
cd Student-Record-Management

2. Compile the Source Code
Compile the code using a native terminal C compiler (such as gcc):
Bash
gcc -std=c99 Student_record_management_System.c -o StudentManager

3. Execute the Binary Workstation
On Windows Platforms:
DOS
Student_record_management_System.exe

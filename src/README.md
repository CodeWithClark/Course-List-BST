# CourseListBST (Binary Search Tree)
A very basic command line application created using C++.

## Requirements 🔧
- C++ 11 or higher
- C++ compiler (g++ for mac/linux; MinGW for Windows)
  
## Getting Started 

1. Press the **Fork** button (top right of the page) to save a copy to your account

2. Download repository files from download section or clone repo in terminal

```
git clone https://github.com/CodeWithClark/CourseList-BST.git
```


3. Import the files VS Code or any other C++ IDE or run the program from your command line.   

**For Mac/Linux:**

```
// Go to src file in your directory
cd ./src

// Compile
g++ -std=c++11 -o CourseListBST CourseListBST.cpp

// Run
./CourseListBST
```

**For Windows:**
```
// Go to the src file in your directory
cd path\to\your\src

// Compile
g++ -std=c++11 -o CourseListBST CourseListBST.cpp

// Run
CourseListBST.exe
```
---
## Project Structure
The current program gives you 4 options:

1. Load Data
2. Print Course List
3. Search by Course Number
4. Exit
   

**Select 1** to load the *CourseInformation.txt* file into the program.

**Select 2** to print the full course list, which includes course number and title.

**Select 3** to search a course number and view a course's prerequisites (if any).

**Select 4** to exit the program.

## Overview
The objective of designing this program was to understand the differences and similarities between common sorting algorithms. The intention of the program itself is to load data from `.txt` file, parse through it, attach data to chosen data structure, and utilize the structure to sort, search, & display the correct information. The *CourseInformation.txt* file contains a list of courses each containing: a course number, course title, and a list of perquisites (if applicable).

**Project 1** 
The *Jordan.Clark_CS300_Proj1.pdf* file contains the pseudocode & big(O) analysis for 3 algorithms: *quick sort, hash table, & binary search tree*. 

**Project 2** 
The source code file includes:  CourseInformation.txt, CourseList.cpp, and a copy of the README.

### Strategy / Approach

The initial idea was to extract the course numbers from the file, place them into a hash table, then chain the prerequisites on a linked list. I imagined a condition that would create the first chained node with a pointer pointing to the address of the item in the table. After building the hash table. I realized building the nodes with the address pointers was beyond my current reach. It also seemed too complicated for this kind of project.

I switched gears mid project, threw out the hash table and built the binary search tree instead. The reason being that its quicker to traverse a tree graph than cycle through a linked list. However, I ran into issues with duplicate printing and I suspect my pointers are to blame.


### Roadblocks

After comparing the projects hash tabe code with code provided by CS300 in weekly assignments and code I wrote from a YouTube tutorial, I discovered the chaining hash table idea was beyond my grasp at the moment because of time constraints. The hash function made it difficult to display the courses in an alphanumeric. I used a prime number verses the number of courses, but no luck. Then I thought about altering the hash function to hash the 1st and last 3 characters but since they are very similar, there will be overlap. By this time I had decided to use a binary search tree.

### Switching Data Structures

The ability to switch data structures was necessary for me to meet the project requirements within a given timeframe. I think the goal of the course was to proivde an understanding of the building blocks to provide freedom of choice.

### Design Choice

I went back and forth with how I wanted to design the software. I initially created a header/main.cpp/CourseListBST.cpp configuration; then I decided to include a CSVParser the home work assignments. However, it seemed unneccsary to separate all of this for a simple program. Ultimately, I decided on 1 file because the focus on this assignment was solving a problem with an algorithm.

Since this decision, I realize the importance of modularity. Separating the components and having them interact IS the design. This choice made its way on the list below.

## Current FIXME'S


- Refactor: Separate data types & functions from their definitions using header files 
- Pointers: The current iteration uses raw pointers, but could use smart pointers instead
- Fix duplicate printing for Selection (2); smart pointers might solve that problem
- Prompt user to strike key to load "CourseInformation.txt"
- Only allow the user to load data once
- Enhance UI: Add details to a few error messages
- Clearer formatting: Add comments and refactor method names to read code like a book/manual.
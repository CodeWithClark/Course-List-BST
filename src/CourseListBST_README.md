# CourseListBST (Binary Search Tree)

---

## Overview

The objective of this program is to load, read, sort, and print data from a provided text file. The file contains a list of courses, each with a course number, title, and a list of perquisites (if applicable). The client requests the program prints the full list in alphanumeric order and prints an individual course with its appropriate information. 

**Project 1** contains the initial solving the problem strategy, along with a runtime analysis of 3 algorithms: *Quick sort, hash table, & binary search tree*

**Project 2** contains the source code files which include:  CourseInformation.txt, CourseList.cpp, and a copy of the README.



## Project 1

### My approach

The initial idea was to extract the course numbers from the file, place them into a hash table, then chain the prerequisites on a linked list. I imagined a condition that would create the first chained node with a pointer pointing to the address of the item in the table. 

### Roadblocks

After going through a hash table tutorial from start to finish and comparing the code provided with the weekly assignments, I realized my idea was beyond my grasp at the moment if I want to get a grade for this. Aside from that hurdle, I was facing issues with alphanumerically printing out the course numbers as well. I thought about altering the hash function to hash the 1st and last 3 characters but since they are very similar, there will be overlap. By this time I had decided to use a binary search tree.



## Project 2

### Switching Data Structures

Understanding data structures allowed me to analyze the various solutions, pick the best run-time, and discover its not the right tool for the job. Each structure has a best and worst case, depending on the problem at hand.

### Design

I went back and forth with how I wanted to design the software. I initially created a header/main.cpp/CourseListBST.cpp configuration; then I decided to include a CSVParser the home work assignments. Ultimately, I decided on 1 file because the focus on this assignment was solving a problem with an algorithm.

### Roadblocks

Developing the parser method and menu functions with input validation went well. I used a switch/case in a try/catch block. This part of development went well because I added print statements along the way to test the functions. Once I began building the structures to hold & carry the data, I got a rush of, "Once I finish the next function, I will test... Ok, maybe the next" because I wanted to see it all flushed out. Then I compiled and reached a `segment default` error. I dove into trying to figure out why and discovered various cases for the error to emerge; all of which had nothing to do with the `=` I put in place of `==` while adding a node to the right side of my tree.

After the data loaded correctly and the algorithm came to life I tweaked the formats for the various outputs and settled on a alphanumerically sorted course list, with duplicate course numbers.

## Evolution

The work for this project lead me through the research, strategy, and implementation phases for vector sorting, hash tables, and binary search tree algorithms. I can now identify the cases in which utilizing multiple header and cpp files reduces redundant code. My choice to submit 1 file was a design choice because the source code could exist without duplication.
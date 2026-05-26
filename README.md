# Linked List C++

A simple C++ console application that uses a **doubly linked list** to manage a browser-style history of websites.

## Overview

This project demonstrates basic linked-list operations, including:

- Adding websites
- Displaying the full list
- Moving forward and backward through the current browsing position
- Searching for a website
- Deleting a website
- Releasing dynamically allocated memory in the destructor

The application is implemented in [Linked list C++.cpp](Linked%20list%20C++.cpp) and includes a Visual Studio solution file, [Linked list C++.sln](Linked%20list%20C++.sln).

## Features

- Stores each website with a name and URL
- Maintains `head`, `tail`, and `current` pointers
- Supports a menu-driven console interface
- Performs case-insensitive searches

## Project Files

- [Linked list C++.cpp](Linked%20list%20C++.cpp) — main program and linked-list implementation
- [Linked list C++.sln](Linked%20list%20C++.sln) — Visual Studio solution
- [Linked list C++.vcxproj](Linked%20list%20C++.vcxproj) — Visual Studio project file

## How to Run

### Using Visual Studio

1. Open [Linked list C++.sln](Linked%20list%20C++.sln) in Visual Studio.
2. Select the desired configuration (Debug or Release).
3. Build the solution.
4. Run the application.

### From the Command Line

If you have a C++ compiler installed and configured, compile the source file directly:

```sh
g++ "Linked list C++.cpp" -o linkedlist
./linkedlist
```

## Example Menu

The program presents a simple menu with options to:

1. Display the website list
2. Move forward
3. Move backward
4. Add a website
5. Delete a website
6. Find a website
7. Exit

## Notes

- The program currently uses dynamic memory allocation for linked-list nodes.
- The program includes a destructor to clean up nodes when the `BrowserHistory` object is destroyed.

## Author

- Chris Krawczyk

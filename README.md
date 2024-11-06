Library Management System

A simple, console-based Library Management System developed in C++. This project demonstrates fundamental C++ programming concepts, including classes, file handling, and basic data management. It allows users to add and manage books and users, register new users, and handle book borrowing and returns.

Features

Add, Delete, and Search Books: Easily manage a collection of books with unique ISBNs.
User Registration and Management: Register and search for users by unique IDs.
Borrow and Return Books: Track which books are borrowed and by whom.
Persistent Data Storage: Saves books and users to files so data persists between program sessions.
Menu-Driven Interface: Simple console-based menu for user interactions.
Project Structure

main.cpp: Main entry point that handles the menu and user interactions.
Book.h / Book.cpp: Defines the Book class with methods for managing individual books.
User.h / User.cpp: Defines the User class with methods for managing individual users.
Library.h / Library.cpp: Manages collections of books and users, handling core library functions.
Database.h / Database.cpp: Handles saving and loading data for books and users.
Utils.h / Utils.cpp: Contains helper functions for ID generation, input validation, and string manipulation.

Future Improvements

Add a graphical user interface (GUI) for easier user interaction.
Implement advanced search and filtering options for books and users.
Enhance data persistence with a database (e.g., SQLite) instead of text files.
Include user authentication to manage different user roles (e.g., admin vs. general user).

## Running Tests

To compile and run the tests, use the following commands in the project directory:

# Compile and run LibraryTest
g++ LibraryTest.cpp Library.cpp Book.cpp User.cpp Database.cpp Utils.cpp -o LibraryTest
./LibraryTest

# Compile and run BookTest
g++ BookTest.cpp Book.cpp -o BookTest
./BookTest

License

This project is open-source and available under the MIT License.
//Contains unit tests for the Library and Book classes to verify core functionalities.
#include <iostream>
#include <cassert>
#include "Book.h"

void testBorrowAndReturnBook() {
    Book book("Sample Title", "Sample Author", "98765");

    assert(!book.getStatus());

    book.setStatus(true);
    assert(book.getStatus());

    book.setStatus(false);
    assert(!book.getStatus());

    std::cout << "testBorrowAndReturnBook passed.\n";
}

int main() {
    testBorrowAndReturnBook();
    return 0;
}
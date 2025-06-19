# AddressBook
Project Title:Address Book Application in C

Description:

The Address Book Application is a menu-driven command-line project developed in the C programming language. It allows users to manage a contact list efficiently with features such as creating, searching, editing, deleting, viewing, and saving contacts to a file.

Each contact includes:

* Name
* 10-digit phone number
* Validated email address

This project emphasizes user input validation, file operations, and modular programming, ensuring both usability and reliability.

Key Functionalities:

* Create Contact – Add a new contact with validated phone and email.
* Search Contact – Lookup by name, number, or email.
* Edit Contact – Modify existing contact fields.
* Delete Contact – Remove a specific contact after confirmation.
* List Contacts – Display all contacts in a formatted view.
* Save & Exit – Persist contacts to `contacts.txt` and exit safely.

 Technical Highlights:

* Use of structures (`struct`) to store contact data.
* Modular design using multiple C files (`main.c`, `contact.c`, `file.c`, `populate.c`).
* Robust input validation for:

  * Phone number length and numeric check
  * Email format check with uniqueness constraint
* File I/O operations using standard C library (`fopen`, `fprintf`, `fscanf`) for data persistence.
* User prompts, error handling, and loop-driven menu system.


Technologies Used:

* Language: C
* IDE: VS Code
* Compiler: GCC
* OS: Linux/Windows


Learning Outcomes:

* Applied knowledge of pointers, arrays, functions, and conditional logic.
* Strengthened understanding of file handling in C.
* Practiced clean code principles with header files and separate compilation units.
* Developed better error-handling and user interface flow in terminal applications.


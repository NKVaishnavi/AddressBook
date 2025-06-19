#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include<ctype.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
int searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
int validate_phone(char *phone,AddressBook *addressBook,int operation);
int validate_email(char *email,AddressBook *addressbook,int option);
int read_phone_number(char *phone, AddressBook *addressBook, int oper);
#endif

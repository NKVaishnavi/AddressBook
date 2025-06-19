/*************************************************************************************************************************************************************************************************************************************** 
 Project        : ADDRESSBOOK
 Author         : N K Vaishnavi
 Submission Date: 04/06/2025

 Description    :This addressbook application allows the user to create, edit,search,delete,save and exit the contacts. 

*****************************************************************************************************************************************************************************************************************************************/
#include<stdio.h>
#include "contact.h"

int main() 
{
  AddressBook info;
  initialize(&info);
  int option;
  do
  {
  printf("----------CONTACT MENU---------- \n");
  printf("1. Creat Contact\n2. Search Contact\n3. Edit Contact\n4. Delete Contact\n5. List of Contacts\n6. Save and Exit\n");
  if(scanf("%d",&option)!=1){
       printf("Invalid input!\n");
       while(getchar() != '\n'); //checks for the invalid i/p for the switch options
       continue;
  }
  switch(option)
  {
   case 1:createContact(&info);
          break;
   case 2:searchContact(&info);
           break;
    case 3:editContact(&info);
           break;
    case 4:deleteContact(&info);
           break;
    case 5:listContacts(&info);
           break;
    case 6:printf("Changes saved successfully!\n Exit\n");
    saveContactsToFile(&info);
            return 0;
            break;
   default: printf("Invalid Option!\n");

  }

}while(option != 6);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"

void listContacts(AddressBook *addressBook) //gives the list of contacts 
{
    printf("<-----------------------CONTACT LIST--------------------------->\n");
    printf("\n%-5s %-20s %-15s %-30s\n","S.No","   Name","PhoneNumber","      Email");
    printf("---------------------------------------------------------------\n");
   for(int i=0;i<addressBook->contactCount;i++)
   {
    printf("%-5d %-20s %-15s %-30s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
   }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount=0;
   loadContactsFromFile(addressBook);//loads contact from the file
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)//creats new contact
{
    char newname[50];
    char number[15];
    char mail[50];
    printf("Enter the name: ");
    scanf(" %[^\n]",newname); //if there are any left over \n from previous input , the space in selective scanf cancels it
    strcpy(addressBook->contacts[addressBook->contactCount].name,newname); //copying the name
    if((read_phone_number(number,addressBook,0))!=-1) //Here, we are checking for validation
    {
    strcpy(addressBook->contacts[addressBook->contactCount].phone,number);//copying phone number
    }
     else
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone,"----------"); //input if phone number not entered 
    }    

    email:
    printf("Enter Email: ");
    scanf(" %[^\n]",mail);

    if((validate_email(mail,addressBook,0))!=1) //to check for duplicates
    {
        printf("Invalid email\n");
         printf("press (Y/y) to re-enter the email or (N/n) to exit program\n");
            char option;
            scanf(" %c",&option);
            switch(option)
            {
                case 'Y':
                case 'y':
                goto email;
                break;
                case 'n':
                case 'N':
                return;
                break;
            } 

    }
    else
    {
    strcpy(addressBook->contacts[addressBook->contactCount].email,mail);
    addressBook->contactCount++;
    printf("Contact created Successfully!!\n");
    }
   
}

int searchContact(AddressBook *addressBook) //search contact
{

    int search;
    char name[50];
    char num[15];
    char mailid[50];
    int found = -1; //if we initialize with 0, we can not access zeroth index. so, initialized with -1
printf("Select any one from the below to search:\n1.name\n2.number\n3.email\n"); //prompting the user to select a field with which they want to search
scanf("%d",&search);
switch (search)
{
    case 1: printf("Enter the name: "); //searching with name
            scanf(" %[^\n]",name);
            for(int i=0;i<addressBook->contactCount;i++)
            {
             if(strcmp(addressBook->contacts[i].name,name)==0)//comparing names
            {
             found = i; //if found,store that index value in variable found
             break;
            }
          }
           break;

           case 2: //search with phone number
            if((read_phone_number(num,addressBook,3))!=-1) //to skip checking duplicates

            {
            for(int i=0;i<addressBook->contactCount;i++)
            {
             if(strcmp(addressBook->contacts[i].phone,num)==0)//comparing numbers
            {
             found = i; //if found,store that index value in found
             break;
            }
          }
        }
           break;

           case 3: email:
           printf("Enter the email: "); //search with email
            scanf(" %[^\n]",mailid);
            if(validate_email(mailid,addressBook,3)!=1)
            {
             printf("enter valid email\n");
            printf("press Y/y to re-enter the email or N/n to exit program\n");
            char option;
            scanf(" %c",&option);
            switch(option)
            {
                case 'Y':
                case 'y':
                goto email;
                break;
                case 'n':
                case 'N':
                exit(0);
                break;
            } 
        }

            for(int i=0;i<addressBook->contactCount;i++)
            {
             if(strcmp(addressBook->contacts[i].email,mailid)==0)//comparing mailids
            {
             found = i;//if found, store that index value in found
             break;
            }
          }
           break;
           default : "Invalid Option!\n";
}
if(found!=-1) //print details, if the contact is found
{
    printf("Contact details: \n");
     printf("Name: %s\nPhone number: %s\nEmail ID: %s\n",addressBook->contacts[found].name,addressBook->contacts[found].phone,addressBook->contacts[found].email); 
}
if(found==-1)
{
  printf("Contact not found\n");  
}
if(found!=-1)
{
    return found;
}
return found;
    
}

void editContact(AddressBook *addressBook) //edit contact
{
    char name[50];
    char num[15];
    char mailid[50];
    int op;
    int found=searchContact(addressBook); //search the contact which you want to edit
    if(found==-1)
    {
        printf("Contact not found\n");
        return;
    }
    //printing the original details
    // printf("\nContact found \n");
    // printf("Name:  %s\n", addressBook->contacts[found].name);
    // printf("Phone: %s\n", addressBook->contacts[found].phone);
    // printf("Email: %s\n\n", addressBook->contacts[found].email);
 
    printf("What do you want to edit? \n");//prompting the user to select the field they want to edit
    printf("1.name\n2.number\n3.email\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1:{ //to edit name
             printf("Enter the name: ");
            scanf(" %[^\n]",name);
            strcpy(addressBook->contacts[found].name,name);
            printf("name updated\n");
            printf("%s\t%s\t%s\t\n",addressBook->contacts[found].name,addressBook->contacts[found].phone,addressBook->contacts[found].email);
            break;
        }
        case 2: { // to edit phone number
            if((read_phone_number(num, addressBook, 0)) != -1)
           strcpy(addressBook->contacts[found].phone,num);
           printf("phone number updated\n");
            printf("%s\t%s\t%s\t\n",addressBook->contacts[found].name,addressBook->contacts[found].phone,addressBook->contacts[found].email);
           break;
        }

        case 3: { //to edit email
            email:
            printf("Enter the email: ");
            scanf(" %[^\n]",mailid);
            if(validate_email(mailid,addressBook,0)!=1) 
        {
            printf("enter valid email\n");
            printf("\033[1;33mpress Y/y to re-enter the email or N/n to exit program\n\033[0m");
            char option;
            scanf(" %c",&option);
            switch(option)
            {
                case 'Y':
                case 'y':
                goto email;
                break;
                case 'n':
                case 'N':
                return;
                break;
            } 
        }

            strcpy(addressBook->contacts[found].email,mailid);
            printf("email updated\n");
            printf("%s\t%s\t%s\t\n",addressBook->contacts[found].name,addressBook->contacts[found].phone,addressBook->contacts[found].email);
            break;
        }
        default : printf("Invalid Option!\n");
           return;
    }
    
}

void deleteContact(AddressBook *addressBook)
{
    delete:
     int found=searchContact(addressBook); //searching for the contact
    if(found==-1)
    {
         enter:
        printf("Enter(Y/y) to search again\npress(N/n) to exit\n");
        char option;
        scanf(" %c",&option);
        switch(option)
        {
            case 'Y':
            case 'y': goto delete;
            break;
            case 'N':
            case 'n': return;
            break;
            default :printf("Enter the valid option!\n");
            goto enter;
        }
        
    }
    if(found!=-1){
    printf("Do you really want to delete the selected contact?\n"); 
    printf("press (y/Y) to delete the selected contact or (n/N) to exit:\n");
    char option;
    scanf(" %c",&option);

    if(option=='y' || option=='Y')
    {
    for(int i=found;i<addressBook->contactCount-1;i++)
    {
        addressBook->contacts[i]=addressBook->contacts[i+1];
    }
    printf("\033[1;31mContact deleted\033[0m\n");
    addressBook->contactCount=addressBook->contactCount-1;
    }
     else if(option=='n' || option=='N') // checking for No
    {
        printf("cancelled\n");
    }
    }
   
}
int validate_phone(char *phone,AddressBook *addressBook,int operation)
{
    if(strlen(phone)!=10)     //to check if the number has 10 digits or not
    {
        printf("phone number should be of 10 digits\n");
        return 0;
    }
    for(int i=0;i<10;i++)
    {
        if(!isdigit(phone[i]))
        {
            printf("number should contain only the digits\n");
            return 0;
        }
    }
    if(operation!=3) //check for duplicates
    {
    for(int i=0;i<addressBook->contactCount;i++)
    {
        if((strcmp(phone,addressBook->contacts[i].phone))==0)
        {
            printf("duplicates are not allowed\n");
            return 0;
        }
    }
    }
    return 1;
   
}

int validate_email(char *email,AddressBook *addressbook,int option)
{
    int i;
    int len=strlen(email);
     char *at  = strchr(email,'@');
    char *com = strstr(email,".com");
    if(!(at) || !(com)) // to check for @ and .com 
    {
        return 0;
    }
    if(at>com) //to check the presence of @ before .com
    {
        return 0;
    }
    if((com-at)<=1) //to check is there anything in between the @ and .com
    {
        return 0;
    }
    if(!islower(email[0]))
    {
        return 0;
    }
    int first=0;
    int second=0;
    for(int i=0;i<len;i++)
    {
        if(email[i]=='@')  //checking for @
        {
            first++;
        }
        if(email[i]=='.') //checking for .
        {
            second++;
        }
    }
    if(first!=1)
    {
        return 0;
    }
    if(second!=1)
    {
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        if((islower(email[i])) || (email[i]>='0' && email[i]<='9') || (email[i]=='@') || (email[i]=='.'))    //upper case and space checking in the mail
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    if(option!=3)
    {
    for(int i=0;i<addressbook->contactCount;i++)
    {
        if((strcmp(addressbook->contacts[i].email,email)==0))   //checking for the duplicates
        {
            return 0;
        }
    }
}
    return 1;
}

/* this funcion gives prompts after phone number validation to the user*/
int read_phone_number(char *phone, AddressBook *addressBook, int oper)
{
    printf("Enter the phone number: "); 
    scanf(" %[^\n]",phone);
    if((validate_phone(phone,addressBook,oper))==0)
    {
        printf("invalid phone number\n");
        printf("press y/Y to re-enter the phone number or press n/N to exit\n");
        char option;
        getchar();
        scanf("%c",&option);
        if(option=='n' || option=='N')
        {
            printf("Exiting from read phone number...\n");
            return -1;
        }
        else if(option!='y' || option!='Y')
        {
           read_phone_number(phone, addressBook, oper);
        }
        else
        {
            printf("Invalid Option!\n");
            read_phone_number(phone, addressBook, oper);
        } 
    }
    return 1;
}


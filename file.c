#include <stdio.h>
#include "file.h"
#include"contact.h"

void saveContactsToFile(AddressBook *addressBook) //saving contacts into the file
{
    FILE *fpw=fopen("contacts.txt","w");
    if(fpw==NULL)
    {
        fprintf(stderr,"No such file!\n");
    }
    fprintf(fpw,"%d\n",addressBook->contactCount);
   
    for(size_t i = 0; i<addressBook->contactCount;i++)
    {
        fprintf(fpw,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fpw);
  
}

void loadContactsFromFile(AddressBook *addressBook) //loading contacts from the files
{
    FILE *fp=fopen("contacts.txt","r");
    if(fp==NULL)
    {
        fprintf(stderr,"File did not open\n");
        return;
    }
    fscanf(fp,"%d\n",&addressBook->contactCount);
    printf("count--->%d\n",addressBook->contactCount);

    for(size_t i = 0; i<addressBook->contactCount;i++)
    {
        fscanf(fp, "%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    fclose(fp);
}

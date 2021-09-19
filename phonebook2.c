// Calls Libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Creates New Data Type Called Person
typedef struct
{
    char *name;
    char *location;
    char *number;
}
person;

// Number Of People (NOP) That File Will Save
const int NOP = 5;

int main(void)
{
    // Opens New File
    FILE *file = fopen("phonebook.csv", "a");
    
    // If There Is No Fill, Program Quits
    if (file == NULL)
    {
        return 1;
    }
    
    // Creates An Array For NOP
    person people[NOP];
    
    // Asks User For Phonebook Data To Store In File
    for (int i = 0; i < NOP; i++)
    {
        people[i].name = get_string("What's the name? ");
        people[i].location = get_string("Where do they live? ");
        people[i].number = get_string("What's their number? ");
        fprintf(file, "%s,%s,%s\n", people[i].name, people[i].location, people[i].number);
    }
    
    // Closes File
    fclose(file);
}
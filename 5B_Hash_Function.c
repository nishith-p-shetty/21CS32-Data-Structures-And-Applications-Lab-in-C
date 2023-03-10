/*
    QUESTION :
        Design and develop a program in C that uses Hash Function H:K->L as H(K)=K mod m(reminder
        method) and implement hashing technique to map a given key K to the address space L. Resolve
        the collision (if any) using linear probing.

    OUTPUT :
        ...... HASH FUNCTION MENU........
        1:Insert, 2:Display, 3:Exit
        Enter your choice : 1
        Enter employee ID : 23
        Enter employee name : asd
        ...... HASH FUNCTION MENU........
        1:Insert, 2:Display, 3:Exit
        Enter your choice : 1
        Enter employee ID : 45
        Enter employee name : fgh
        ...... HASH FUNCTION MENU........
        1:Insert, 2:Display, 3:Exit
        Enter your choice : 1
        Enter employee ID : bnn
        Enter employee name : ...... HASH FUNCTION MENU........
        1:Insert, 2:Display, 3:Exit
        Enter your choice : 2
        Contents of hash table :
        H_value Emp_id  Emp_name
        23      23      asd
        45      45      fgh
        46      45      bnn
        ...... HASH FUNCTION MENU........
        1:Insert, 2:Display, 3:Exit
        Enter your choice : 3
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define pf printf
#define sf scanf
#define HASH_SIZE 100

typedef struct employee
{
    int id;
    char name[20];
}EMPLOYEE;

void initialize_hash_table(EMPLOYEE a[])
{
    int i;
    for(i = 0 ; i < HASH_SIZE ; i++)
    {
        a[i].id = 0;
    }
}

int H(int k)
{
    return (k % HASH_SIZE);
}

void insert_hash_table(int id, char name[], EMPLOYEE a[])
{
    int i, index, h_value;
    h_value = H(id);
    for(i = 0 ; i < HASH_SIZE ; i++)
    {
        index = (h_value + i) % HASH_SIZE;
        if( a[index].id == 0)
        {
            a[index].id = id;
            strcpy(a[index].name, name);
            break;
        }
    }
    if(i == HASH_SIZE)
        pf("Hash Table Full!\n");
}

void display_hash_table(EMPLOYEE a[])
{
    int k, i;
    pf("H_value\tEmp_id\tEmp_name\n");
    for(i = 0 ; i < HASH_SIZE ; i++)
    {
        if(a[i].id != 0)
            pf("%d\t%d\t%s\n", i, a[i].id, a[i].name);
    }
}

int main()
{
    EMPLOYEE a[HASH_SIZE];
    char name[20];
    int id, choice;
    initialize_hash_table(a);
    while(1)
    {
        pf("...... HASH FUNCTION MENU........\n");
        pf("1:Insert, 2:Display, 3:Exit\n");
        pf("Enter your choice : ");
        sf("%d",&choice);
        switch(choice)
        {
            case 1:
                    pf("Enter employee ID : ");
                    sf("%d",&id);
                    pf("Enter employee name : ");
                    sf("%s", name);
                    insert_hash_table(id, name, a);
                    break;
            case 2:
                    pf("Contents of hash table :\n");
                    display_hash_table(a);
                    break;
            case 3:
                    exit(0);
                    break;
            default :
                    pf("Invalid Choice\n");
        }
    }
    return 0;
}

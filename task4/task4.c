//2110646, anton.zagzin@gmail.com, 4 uzduotis, 2 variantas

//Programa sudaro vienpusį sutvarkytą sąrašą (elemementai eina didėjimo tvarka) ir įterpia į sąrašą naują elemementa

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "funkcijos.h"

void ValidateNumber(int *number)
{
    char character;
    while (scanf("%d%c", number, &character) == 0 || character != '\n')
    {
        scanf("%*[^\n]");
        printf ("Neteisinga ivestis. Bandykite is naujo\n");
    }
}

char *FileName()
{
    char *name = (char*)malloc(sizeof(char)*255);

    printf ("Iveskite failo pavadinima:\n");
    scanf("%s", name);

    assert (name != NULL);

    return name;
}

int Input(List **first, List **last)
{
    int number;

    ValidateNumber(&number);
    while (number < 0 || number > 3)
    {
        printf("Jusu ivestas skaicius nera nuo 0 iki 3. Bandykite dar karta\n");
        ValidateNumber(&number);
    }

    printf ("Jus pasirinkote %d\n", number);

    switch(number)
    {
        case 0:
            printf ("Sukuriamas sarasas is duoto duomenu failo\n");
            char *data;
            FILE *fp;
            data = FileName();
            fp = fopen(data, "r");
            SortTextForList(&fp, first, last);
            return 1;
        case 1:
            printf("Isspaudinamas sarasas:\n");
            PrintList(*first);
            return 1;
        case 2:
            printf ("Iveskite skaiciu:\n");
            ValidateNumber(&number);
            InputElementInAList(first, last, number);
            return 1;
        case 3:
            printf ("Iseinama is programos\n");
            exit(0);
        default:
            return 0;
    }

}

void PrintMenu()
{
    printf ("\nPrograma sudaro vienpusi sutvarkyta sarasa is int elementu, kurie yra faile ir eina didejimo tvarka bei iterpia i sarasa nauja elementa.\n");
    printf ("Pasirinkite, ka toliau norite daryti su programa:\n");
    printf ("Paspauskite 0 tam, kad sukurti sarasa is duoto duomenu failo\n");
    printf ("Paspauskite 1 tam, kad isspaudinti sarasa\n");
    printf ("Paspauskite 2 tam, kad iterpti i sarasa nauja elementa\n");
    printf ("Paspauskite 3 tam, kad iseiti is programos\n");
}

int main(){

    List *first = NULL, *last = NULL;
    int open = 1;

    while(open)
    {
        PrintMenu();
        open = Input(&first, &last);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "funkcijos.h"

void TusciasSarasas (List **first, List **last)
{
	InputElementInAList(first, last, 7);
    assert((*first)->next == NULL);
    assert((*first)->number == 7);
    printf ("skaicius %d sekmingai iterptas i tuscia sarasa\n", 7);
}

void Galas(List **first, List **last)
{
	InputElementInAList(first, last, 11);
    assert((*last)->next == NULL);
    assert((*last)->number == 11);
    printf ("skaicius %d sekmingai iterptas i gala\n", 11);
}

void Pradzia(List **first, List **last)
{
	InputElementInAList(first, last, -5);
    assert((*first)->number == -5);
    assert(((*first)->next->number) > ((*first)->number));
    printf("skaicius %d sekmingai iterptas i pradzia\n", -5);
}

void Viduris (List **first, List **last)
{
	int wrong = 0;
	InputElementInAList(first, last, 9);
    List *temp = *first;
    while (temp != NULL)
    {
        if(temp->next != NULL && ((temp->number) > (temp->next->number)))
        {
            wrong++;
        }
        temp = temp->next;
    }
    assert(wrong == 0);
    printf("skaicius %d sekmingai iterptas i saraso viduri\n", 9);
}

int main()
{
	
    List *first = NULL, *last = NULL;

	printf ("Sis kodas patikrina itraukima i saraso funkcija\n");

	TusciasSarasas(&first, &last);

    Galas(&first, &last);

	Pradzia(&first, &last);
	
	Viduris(&first, &last);

    printf("Sarasas yra:\n");
    PrintList(first);
    return 0;
}

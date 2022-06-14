// funkcijos.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

typedef struct element
{
    int number;
    struct element *next;
}List;
List *NewListNumber(int newNumber);
void InputElementInAList(List **first, List **last, int newNumber);
int IsTextADigit (char *text);
void SortTextForList(FILE **fp, List **first, List **last);
void PrintList(List *first);

#endif

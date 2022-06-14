#include "funkcijos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

List *NewListNumber(int newNumber)
{
    List *temp =(List*)malloc(sizeof(List));

    assert (temp != NULL);

    temp->number = newNumber;
    temp->next = NULL;

    return temp;
}

void SortTextForList(FILE **fp, List **first, List **last)
{
    char *line = calloc(255, sizeof(char)), *text;

    assert (line != NULL);

    int newNumber, truth;

    while (fgets(line, 255,*fp) != NULL)
    {
        text = strtok(line, " \n");

        if (text != NULL)
            {
                truth = IsTextADigit(text);
                if(truth)
                {
                    newNumber = atoi(text);
                    assert (newNumber < INT_MAX);
                    assert (newNumber > INT_MIN);
                    InputElementInAList(first, last, newNumber);
                }
            }

        do
        {
            text = strtok(NULL, " \n");
            if (text != NULL)
            {
                truth = IsTextADigit(text);
                if(truth)
                {
                    newNumber = atoi(text);
                    InputElementInAList(first, last, newNumber);
                }

            }
        }while (text != NULL);

    }

    free(line);
}

int IsTextADigit (char *text)
{
    if (strspn(text, "0123456789") == strlen(text)) return 1;
    else if (text[0] == '-')
    {
        if (strspn(text, "0123456789") == strlen(text)-1)
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void InputElementInAList(List **first, List **last, int newNumber)
{
    List *newNumberPointer = NewListNumber(newNumber);

    if ((*first) == NULL)
    {
        (*first) = newNumberPointer;
        (*last) = newNumberPointer;
        return;
    }

    if ((newNumberPointer->number) < ((*first)->number))
    {
        newNumberPointer->next = (*first);
        (*first) = newNumberPointer;
        return;
    }

    if ((newNumberPointer->number) > ((*last)->number))
    {
        //newNumberPointer->next = NULL;
        (*last)->next = newNumberPointer;
        (*last) = newNumberPointer;
        return;
    }

    List *temp1 = (*first)->next;
    List *temp2 = *first;
    while ((temp1->number) < (newNumberPointer->number))
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp2->next = newNumberPointer;
    newNumberPointer->next = temp1;

    return;
}

void PrintList(List *first)
{
    if (first == NULL)
    {
        return;
    }
    printf("%d ", first->number);
    PrintList(first->next);
}

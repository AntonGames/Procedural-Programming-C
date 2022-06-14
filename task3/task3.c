//2110646, anton.zagzin@gmail.com, 3 uzduotis, 6 variantas

//Parašyti funkciją, kuri duoto teksto kiekvienos eilutės žodžius perrašo atvirkščia tvarka
//(simbolių tvarka žodyje nesikeičia, bet keičiasi žodžių tvarka; tarpų skaičius turi likti nepakitęs).

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"
void function(char Words[300][300], int const_int, char output_path[], int Number[]);

int main()
{
    FILE *fin;
    char Words[300][300] = {0};
    int Number[300] = {0};
    char input_path[256] = "";
    printf("Enter full path to the input file:\n");
    scanf("%s",&input_path);
    if ((fin=fopen(input_path, "r")) == NULL) {
        printf("Opening file error");
        return 1;
    }
    char output_path[255]="";
    printf("Enter full path to the output file and its name:\n");
    scanf("%s", &output_path);
    char temp_char;
    int temp_int;
    do{
        int howManySymbols = 0;
        while((fgetc(fin)) != '\n' && !feof(fin))
        {
            ++howManySymbols;
        }
        if (feof(fin))
        {
            fseek(fin, -howManySymbols, SEEK_CUR);
        }
        else
        {
            fseek(fin, -(howManySymbols+2), SEEK_CUR);
        }
        char *word = calloc(sizeof(char),howManySymbols+1);
        if(word == NULL)
            {
                printf("Out of memory");
                return 1;
            }
        word[0] = '\0';
        temp_int = 0;
        while((temp_char = fgetc(fin)) != '\n'){
            word[temp_int] = temp_char;
            temp_int++;
            if(temp_int > 254){
                break;
            }
            if(feof(fin)){
                word[temp_int - 1] = '\0';
                break;
            }
        }
        word[temp_int] = '\0';
        if(temp_int >= 255){
            while((temp_char = fgetc(fin)) != '\n'){
            }
        }
        int j = 1;
        int const_int = 0;
        int noMoreZero = 0;
        int wasZero = 0;
        for (int i = 0; i < strlen(word); ++i)
        {
            if (word[i] == ' ')
            {
                if (noMoreZero == 0)
                {
                    if (wasZero != 1)
                    {
                        Words[const_int][j] = word[i];
                        Number[const_int] = 2;
                        j = 1;
                        wasZero = 1;
                    }
                    else
                    {
                        ++j;
                        Words[const_int][j] = word[i];
                        Number[const_int] = j+1;
                        wasZero = 1;
                    }
                }
                else
                {
                    if (wasZero != 1)
                    {
                        Number[const_int] = j;
                        ++const_int;
                        j = 1;
                        Words[const_int][j] = word[i];
                        Number[const_int] = 2;
                        wasZero = 1;
                    }
                    else
                    {
                        ++j;
                        Words[const_int][j] = word[i];
                        Number[const_int] = j+1;
                        wasZero = 1;
                    }
                }
            }
            else
            {
                if (wasZero == 1)
                {
                    ++const_int;
                    wasZero = 0;
                    j = 1;

                }
                 Words[const_int][j] = word[i];
                 ++j;
                 noMoreZero = 1;
                 Number[const_int] = j;
            }
        }
        function(Words, const_int, output_path, Number);
        memset(Words, 0, sizeof(Words[0][0])*300*300);
        memset(Number, 0, sizeof(Number));
        free(word);
        word = NULL;
    }while(!feof(fin));
    fclose(fin);
    return 0;
}

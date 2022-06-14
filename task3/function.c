#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <unistd.h>

void function(char Words[300][300], int const_int, char output_path[], int Number[])
{
    FILE *fout;
    if ((fout=fopen(output_path, "a+")) == NULL) {
        printf("Output file error");
    }
    int k = const_int;
    for (int i = 0; i <= const_int; ++i)
    {
        if (Words[i][1] == ' ')
        {
            for (int j = 1; j < Number[i]; ++j)
            {
                fprintf(fout, "%c", Words[i][j]);
            }
        }
        else
        {
            for (int m = k; m >= 0; --m)
            {
                if (Words[m][1] != ' ')
                {
                    for (int j = 1; j < Number[m]; ++j)
                    {
                        fprintf(fout, "%c", Words[m][j]);
                    }
                    k=k-2;
                    break;
                }
            }
        }
    }
    fprintf(fout, "\n");
    fclose(fout);
}

//2110646, anton.zagzin@gmail.com, 2 uzduotis, 9 variantas

//Įvesti sveiką skaičių N. Įvesti N sveikų skaičių, kurie sudarys vektorių.
//Rasti didžiausią atstumą (matuojant elementų pozicijomis) tarp šio vektoriaus ekstremumų.
//Ekstremumu laikomas toks vektoriaus elementas, iki kurio yra didėjanti seka,
//o po jo yra mažėjanti seka, arba, atvirkščiai, iki jo yra mažėjanti seka,
//o po jo yra didėjanti seka. Programa turėtų išvesti elementų numerius ir atstumą tarp jų.

#include <stdlib.h>
#include <stdio.h>
int getValidInt()
{
    int x;
    int teisingaiNuskaitytiSkaiciai = scanf("%d", &x);
        while (!teisingaiNuskaitytiSkaiciai || getchar() != '\n')
        {
            printf("Bloga ivestis, irasykite skaiciu: ");
            while(getchar() != '\n')
                ;
            teisingaiNuskaitytiSkaiciai = scanf("%d", &x);
        }
    return x;
}
int teigiamuSkaiciuValidavimas()
{
    int x = getValidInt();
    while (x <= 0)
    {
        printf("Bloga ivestis, irasykite teigiama skaiciu: ");
        x = getValidInt();
    }
    return x;
}
void arEkstremumas(int Vector[], int i, int EkstremumuNumeriai[], int *ekstremumuSkaicius)
{
    if (((Vector[i-2] > Vector[i-1]) && (Vector[i] > Vector[i-1]))||
            ((Vector[i-2] < Vector[i-1]) && (Vector[i] < Vector[i-1])))
        {
            //Ekstremumai[ekstremumuSkaicius] = Vector[i-1];
            EkstremumuNumeriai[*ekstremumuSkaicius] = i;
            (*ekstremumuSkaicius)++;
        }
}
int main()
{
    int N;
    printf("Irasykite skaiciu N: ");
    N = teigiamuSkaiciuValidavimas();
    while (N <= 2)
    {
        printf("Ekstremumu nera skaiciu sekoje is 2 ar maziau elementu\n");
        printf("Irasykite skaiciu N: ");
        N = teigiamuSkaiciuValidavimas();
    }
    int Vector[N];
    int Ekstremumai[N], ekstremumuSkaicius = 0;
    int EkstremumuNumeriai[N];
    printf("Irasykite skaicius: \n");
    Vector[0] = getValidInt();
    Vector[1] = getValidInt();
    for (int i = 2; i < N; ++i)
    {
        Vector[i] = getValidInt();
        arEkstremumas(Vector, i, EkstremumuNumeriai, &ekstremumuSkaicius);
    }
    //printf("Ekstremumai %d \n", ekstremumuSkaicius);
    if (ekstremumuSkaicius < 2)
    {
        printf("Ekstremumu nera skaiciu sekoje arba ju maziau nei 2\n");
        return 0;
    }
    int pirmoEkstremumoNumeris = EkstremumuNumeriai[0];
    int antroEkstremumoNumeris = EkstremumuNumeriai[1];
    int maxAtstumas = EkstremumuNumeriai[1] - EkstremumuNumeriai[0];
    for (int i = 0; i < ekstremumuSkaicius - 1; ++i)
    {
        if (maxAtstumas < EkstremumuNumeriai[i + 1] - EkstremumuNumeriai[i])
        {
            maxAtstumas = EkstremumuNumeriai[i + 1] - EkstremumuNumeriai[i];
            pirmoEkstremumoNumeris = EkstremumuNumeriai[i];
            antroEkstremumoNumeris = EkstremumuNumeriai[i + 1];
        }
    }
    printf("Elementu numeriai yra %d ir %d \n", pirmoEkstremumoNumeris, antroEkstremumoNumeris);
    printf("Atstumas tarp ju yra %d \n", maxAtstumas);
    return 0;
}

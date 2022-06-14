//2110646, anton.zagzin@gmail.com, 1 uzduotis, 4 variantas

//Įvedinėti sveikų teigiamų skaičių seką tol, 
//kol maksimalus įvestas skaičius netaps du ar daugiau kartų didesnis už minimalų. 
//Išvesti šiuos skaičius (maksimalų ir minimalų) bei įvestų narių skaičių.

#include <stdio.h>
int main()
{
    int nr = 0, sk = 0, maks = 0, minim = 10, i = 0;
    printf("Irasykite skaiciu seka (po kiekvieno skaiciaus spausti ENTER): \n");
    while(maks < 2 * minim)
    {
        int teisingaiNuskaitytiSkaiciai = scanf("%d", &sk);
        while (sk <= 0 || !teisingaiNuskaitytiSkaiciai || getchar() != '\n')
        {
            printf("Irasykite teigiama skaiciu: \n");
            while(getchar() != '\n')
                ;
            teisingaiNuskaitytiSkaiciai = scanf("%d", &sk);
        }
        if(i == 0)
        {
            i++;
            minim = sk;
        }
        if (sk > maks)
        {
            maks = sk;
        }
        if (sk < minim)
        {
            minim = sk;
        }
        nr++;
    }


    {
        printf("Maksimalus skaicius: %d \n", maks);
        printf("Minimalus skaicius: %d \n", minim);
        printf("Nariu skaicius: %d", nr);
    }
    return 0;
}

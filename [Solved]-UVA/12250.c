#include <stdio.h>
#include <string.h>

main()
{
    char a[15];
    char eng[6]="HELLO", spa[5]="HOLA", ger[6]="HALLO";
    char fra[8]="BONJOUR", ita[5]="CIAO", rus[13]="ZDRAVSTVUJTE";
    int i=0;
    while(gets(a))
    {
        i++;
        if(a[0]==35)
        {
            break;
        }
        else if(strcmp(a,eng)==0)
        {
            printf("Case %d: ENGLISH",i);
        }
        else if(strcmp(a,spa)==0)
        {
            printf("Case %d: SPANISH",i);
        }
        else if(strcmp(a,ger)==0)
        {
            printf("Case %d: GERMAN",i);
        }
        else if(strcmp(a,fra)==0)
        {
            printf("Case %d: FRENCH",i);
        }
        else if(strcmp(a,ita)==0)
        {
            printf("Case %d: ITALIAN",i);
        }
        else if(strcmp(a,rus)==0)
        {
            printf("Case %d: RUSSIAN",i);
        }
        else
        {
            printf("Case %d: UNKNOWN",i);
        }
        printf("\n");
    }
    return 0;
}

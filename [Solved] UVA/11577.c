#include <stdio.h>
#include <string.h>

main()
{

    char a[501];
    int sum,s[26];
    int test,i,j,k,l;
    scanf("%d",&test);
    getchar();
    for(k=0;k<test;k++)
    {
        sum=0;
        gets(a);
        l=strlen(a);
        for(i=0;i<26;i++)
        {
            s[i]=0;
        }
        for(i=0;i<l;i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                j=a[i]-65;
                s[j]++;
                if(s[j]>sum)
                {
                    sum=s[j];
                }
            }
            else if(a[i]>='a' && a[i]<='z')
            {
                j=a[i]-97;
                s[j]++;
                if(s[j]>sum)
                {
                    sum=s[j];
                }
            }
        }
        for(i=0;i<26;i++)
            {
                if(s[i]==sum)
                printf("%c",i+97);
            }

            printf("\n");
    }
    return 0;
}

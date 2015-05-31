#include <stdio.h>
#include <string.h>

main()
{
    char a[100000];
    int small[26],big[26],sum,l,i,j,k;
    while(gets(a))
    {
        l=strlen(a);
        for(i=0;i<26;i++)
        {
            small[i]=0;
            big[i]=0;
        }
        sum=0;
        for(i=0;i<l;i++)
        {
            if(a[i]>='A' && a[i]<='Z')
            {
                j=a[i]-65;
                big[j]++;
                if(big[j]>sum)
                {
                    sum=big[j];
                }
            }
            else if(a[i]>='a' && a[i]<='z')
            {
                j=a[i]-97;
                small[j]++;
                if(small[j]>sum)
                {
                    sum=small[j];
                }
            }
        }
        for(i=0;i<26;i++)
        {
            if(big[i]==sum)
            {
                printf("%c",i+65);
            }
        }
        for(i=0;i<26;i++)
        {
            if(small[i]==sum)
            {
                printf("%c",i+97);
            }
        }
        printf(" %d\n",sum);
    }
    return 0;
}

#include <cstdio>
#include <cstring>

long long div(char a[],long long n,char c[])
{
    int i,j,t=0,l,d=0,r=-1;
    long long rem=0;
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        rem=(rem*10)+a[i]-48;
        if(r>=0)
        {
            r++;
        }

        if(rem>=n)
        {
            j=rem/n;
            rem=rem%n;
            c[d]=j+48;
            d++;
            t=1;
            r=0;
        }
        else if(rem<n && r>0)
        {
            c[d]='0';
            d++;
        }
    }
    if(d==0)
    {
        c[d]='0';
        d++;
    }
    c[d]='\0';
    return rem;
}

main()
{
    long long n;
    char a[100000],c[100000];
    char ch;
    while(scanf("%s %c %lld",&a,&ch,&n)!=EOF)
    {
        if(ch=='%')
        {
            n=div(a,n,c);
            printf("%lld\n",n);
        }
        else if(ch=='/')
        {
            div(a,n,c);
            printf("%s\n",c);
        }
    }
    return 0;

}

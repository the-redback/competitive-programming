#include<cstdio>
#define Z 500003
long Sum[Z];
int main()
{
    long t,n,i,j;
    for(i=1;i<Z;i++)
    {
        for(j=2*i;j<Z;j+=i)
        Sum[j]+=i; 
    }
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        printf("%ld\n",Sum[n]); 
    }
    return 0;
}
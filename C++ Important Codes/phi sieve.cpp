unsigned long long a[NN+7];
void sieve(void)
{
    int i,j,k,n=2237;
    for(i=2;i<NN;i++)
        a[i]=i;
    for(i=2;i<NN;i+=2)
    {
        a[i]*=(2-1);
        a[i]/=2;
    }
    for(i=3;i<NN;i+=2)
        if(a[i]==i)
        {
            for(j=i;j<NN;j+=i)
            {
                a[j]*=(i-1);
                a[j]/=i;
            }
        }
}
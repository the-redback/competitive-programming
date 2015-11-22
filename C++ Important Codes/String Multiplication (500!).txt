
    char a[1001][10000];
void swap(char b[10000])
{
    int temp,i,j,l;
    l=strlen(b);
    for(i=0,j=l-1;i<l/2;i++,j--)
    {
        temp=b[i];
        b[i]=b[j];
        b[j]=temp;
    }
}
void work(char a[10000],char b[10000],int n)
{
    int i,j,onhand=0,k,l;
    l=strlen(a);
    for(i=l-1,j=0;i>=0;i--)
    {
        k=((a[i]-48)*n)+onhand;
        b[j]=(k%10)+48;
        onhand=k/10;
        j++;
    }
    while(onhand>0)
    {
        b[j]=(onhand%10)+48;
        onhand/=10;
        j++;
    }
    b[j]='\0';
    swap(b);
}

main()
{
    int i,j,n;
    strcpy(a[0],"1");
    strcpy(a[1],"1");
    for(i=2;i<1001;i++)
    {
        work(a[i-1],a[i],i);

    }
    while(scanf("%d",&n)==1)
    {
        printf("%d!\n%s\n",n,a[n]);

    }
    return 0;
}

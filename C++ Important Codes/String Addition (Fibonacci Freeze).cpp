const int max=1111;
char a[5001][max];

void add(char b[max],char b1[max],char b2[max])
{
    char c[max];
    int carry=0,i,k,j,m,n,l=0;
    m=strlen(b1);
    n=strlen(b2);
    for(i=m-1,k=n-1;i>=0 || k>=0 ;i--,k--)
    {
        if(i>=0 && k>=0)
        {
            j=b1[i]-48+b2[k]-48+carry;
            carry=j/10;
            c[l]=j%10+48;
            l++;
        }
        else if(i>=0)
        {
            j=b1[i]-48+carry;
            carry=j/10;
            c[l]=j%10+48;
            l++;
        }
        else
        {
            j=b2[k]-48+carry;
            carry=j/10;
            c[l]=j%10+48;
            l++;
        }
    }
    j=0;
    if(carry==1)
    {
        b[j]=49;
        j++;
    }
    for(i=l-1;i>=0;i--)
    {
        b[j]=c[i];
        j++;
    }
    b[j]='\0';
}

void check(void)
{
    int i;
    strcpy(a[0],"0");
    strcpy(a[1],"1");
    for(i=2;i<=5000;i++)
    {
        add(a[i],a[i-1],a[i-2]);
    }

}

main()
{
    check();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("The Fibonacci number for %d is %s\n",n,a[n]);

    }
    return 0;
}
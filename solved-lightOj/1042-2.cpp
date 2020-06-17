#include <iostream>
#include <algorithm>
using namespace std;

int swap(int a[],int x)
{
    int l,j,k;
    for(l=0,j=x-1;l<x/2;l++,j--)
        {
            k=a[j];
            a[j]=a[l];
            a[l]=k;
        }
}

int con(int a[],int n)
{
    int i=1,j,sum=0;
    for(j=0;j<n;j++)
    {
        if(a[j]==1)
        {
            sum+=i;
        }
        i*=2;
    }
    return sum;
}

main()
{
    int t,n,i,j,x,l,max;
    int a[100];
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        j=0;
        while(n>0)
        {
            a[j]=n%2;
            n=n/2;
            j++;
        }
        x=j;
        swap(a,x);
        if(next_permutation(a,a+x)!=0)
        {
            swap(a,x);
            max=con(a,x);
        }
        else
        {
            prev_permutation(a,a+x);
            a[x]=0;
            x++;

            for(j=x-1;j>=0;j--)
            {
                if(a[j]==1)
                {
                    a[j]=0;
                    a[x-1]=1;
                    break;
                }
            }
            max=con(a,x);
        }
        cout<<"Case "<<i<<": "<<max<<"\n";

    }
    return 0;
}

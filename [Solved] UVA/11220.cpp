#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;
char a[5000];
char b[5000][500];
main()
{
    int tc,i,j,k,l,m,ii,jj;
    char ch[100];
    scanf("%d",&tc);
    int t=1;
    getchar();
    getchar();
    while(tc--)
    {

        if(t!=1)
            puts("");
        printf("Case #%d:\n",t++);
        while(gets(a))
        {
            if(strlen(a)==0)
                break;
            k=0;
            i=0;
            int flag=0;
            l=strlen(a);
            for(j=0; j<=l; j++)
            {
                if(a[j]==' ' && flag==1||a[j]=='\0' && flag==1)
                {
                    jj=0;
                    for(ii=i; ii<j; ii++)
                    {
                        b[k][jj]=a[ii];
                        jj++;
                    }
                    b[k][jj]=0;
                    k++;
                    flag=0;
                }
                else if(flag!=1 && a[j]!='\0' && a[j]!=' ')
                {
                    flag=1;
                    i=j;
                }
            }
            j=0;
            for(i=0; i<k; i++)
            {
                l=strlen(b[i]);
                if(j+1<=l)
                {
                    ch[j]=b[i][j];
                    j++;
                }
            }
            ch[j]=0;
            puts(ch);
        }
    }
    return 0;
}

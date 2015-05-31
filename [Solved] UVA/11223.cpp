#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

main()
{
    char ch;
    int i=1,flag,t;
    string s;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        if(i!=1)
            puts("");
        printf("Message #%d\n",i++);
        s.erase();
        flag=0;
        while(ch=getchar())
        {
            if(ch==' ' && flag==1)
            {
                printf(" ");
                flag=0;
            }
            else if(ch==' ' || ch=='\n')
            {
                if( s==".-" )
                    printf("A");
                else if( s=="-..." )
                    printf("B");
                else if( s=="-.-." )
                    printf("C");
                else if( s=="-.." )
                    printf("D");
                else if( s=="." )
                    printf("E");
                else if( s=="..-." )
                    printf("F");
                else if( s=="--." )
                    printf("G");
                else if( s=="...." )
                    printf("H");
                else if( s==".." )
                    printf("I");
                else if(s==".---" )
                    printf("J");
                else if( s=="-.-" )
                    printf("K");
                else if( s==".-.." )
                    printf("L");
                else if( s=="--" )
                    printf("M");
                else if( s=="-." )
                    printf("N");
                else if( s=="---" )
                    printf("O");
                else if( s==".--." )
                    printf("P");
                else if( s=="--.-" )
                    printf("Q");
                else if( s==".-." )
                    printf("R");
                else if( s=="..." )
                    printf("S");
                else if( s=="-" )
                    printf("T");
                else if( s=="..-" )
                    printf("U");
                else if( s=="...-" )
                    printf("V");
                else if( s==".--" )
                    printf("W");
                else if( s=="-..-" )
                    printf("X");
                else if( s=="-.--" )
                    printf("Y");
                else if( s=="--.." )
                    printf("Z");
                else if( s=="-----" )
                    printf("0");
                else if( s==".----" )
                    printf("1");
                else if( s=="..---" )
                    printf("2");
                else if( s=="...--" )
                    printf("3");
                else if( s=="....-" )
                    printf("4");
                else if( s=="....." )
                    printf("5");
                else if( s=="-...." )
                    printf("6");
                else if( s=="--..." )
                    printf("7");
                else if( s=="---.." )
                    printf("8");
                else if( s=="----." )
                    printf("9");
                else if( s==".-.-.-" )
                    printf(".");
                else if( s=="--..--" )
                    printf(",");
                else if( s=="..--.." )
                    printf("?");
                else if( s==".----." )
                    printf("'");
                else if( s=="-.-.--" )
                    printf("!");
                else if( s=="-..-." )
                    printf("/");
                else if( s=="-.--." )
                    printf("(");
                else if( s=="-.--.-" )
                    printf(")");
                else if( s==".-..." )
                    printf("&");
                else if( s=="---..." )
                    printf(":");
                else if( s=="-.-.-." )
                    printf(";");
                else if( s=="-...-" )
                    printf("=");
                else if( s==".-.-." )
                    printf("+");
                else if( s=="-....-" )
                    printf("-");
                else if( s=="..--.-" )
                    printf("_");
                else if( s==".-..-." )
                    printf("\"");
                else if( s==".--.-." )
                    printf("@");
                flag=1;
                s.erase();
                if(ch=='\n')
                    break;
            }
            else
            {
                s+=ch;
                flag=0;
            }
        }
        printf("\n");
    }
    return 0;
}

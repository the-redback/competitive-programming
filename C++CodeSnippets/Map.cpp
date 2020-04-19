main()
{
    map<string,string>mp;
    string s,ss;
    char a[100010];
    char b[100010];
    char *token;
    int tc,t=1;
    while(gets(a))
    {
        if(strlen(a)==0)
            break;
        token=strtok(a," ");
        s=token;
        token=strtok(NULL," ");
        ss=token;
        mp[ss]=s;
    }                                      *=========[ Another way to search ]=============
    while(gets(a))                         * while(gets(a))   
    {                                      * {                
        s.assign(a);                       *     s.assign(a);        
        if(mp.find(s)==mp.end())           *     if(mp[s].length()==0)           
            printf("eh\n");                *         printf("eh\n");    
        else                               *     else                        
            printf("%s\n",mp[s].c_str());  *         printf("%s\n",mp[s].c_str());         
    }                                      * That means, if mp[s] doesn't exist,
    return 0;                              * then, mp[s]="";
}
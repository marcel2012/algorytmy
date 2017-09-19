#include <iostream>
#define p 128
#define m 89
int main()
{
    std::string a,b;
    std::cin>>a;
    std::cin>>b;
    if(b.length()>a.length())
        printf("0\n");
    else
    {
        int hash1=0,hash2=0;
        int i;
        int mn=1;
        for(i=0;i<b.length();i++)
        {
            hash1=(hash1*p+a[i])%m;
            hash2=(hash2*p+b[i])%m;
            if(i)
                mn=(mn*p)%m;
        }
        int wynik=0;
        if(hash1==hash2)
            wynik++;
        for(;i<a.length();i++)
        {
            hash1=((hash1-a[i-b.length()]*mn)*p+a[i])%m;
            if(hash1<0)
                hash1+=m;
            if(hash1==hash2)
                wynik++;
        }
        printf("%d\n",wynik);
    }
    return 0;
}

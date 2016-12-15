#include <cstdio>
#include <vector>
int time=1;
int korzen=0;
inline void dfs(std::vector <std::vector<int> > &dane,std::vector<bool> &uzyte,std::vector <int> &czas,std::vector <int> &low,std::vector<bool> &punkt,int start,int rodzic)
{
    uzyte.at(start)=true;
    czas.at(start)=time;
    int minimum=time;//czas wejscia
    time++;
    for(int i=0;i<dane.at(start).size();i++)
    {
        if(!uzyte.at(dane.at(start).at(i)))//dziecko
        {
            dfs(dane,uzyte,czas,low,punkt,dane.at(start).at(i),start);
            if(low.at(dane.at(start).at(i))<minimum)
                minimum=low.at(dane.at(start).at(i));
            if(start==0)
                korzen++;
            if(low.at(dane.at(start).at(i))>=czas.at(start))
                punkt.at(start)=true;
        }
        else
        {
            if(dane.at(start).at(i)!=rodzic)//krawedz powracajaca
                if(czas.at(dane.at(start).at(i))<minimum)
                    minimum=czas.at(dane.at(start).at(i));
        }
    }
    low.at(start)=minimum;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    std::vector <std::vector<int> > dane (n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        dane.at(b).push_back(a);
        dane.at(a).push_back(b);
    }
    std::vector <int> czas (n);
    std::vector <bool> uzyte (n);
    std::vector <int> low (n);
    std::vector <bool> punkt (n);
    dfs(dane,uzyte,czas,low,punkt,0,0);
    if(korzen>1)
        printf("0\n");
    for(int i=1;i<n;i++)
        if(punkt.at(i))
            printf("%d\n",i);
    return 0;
}

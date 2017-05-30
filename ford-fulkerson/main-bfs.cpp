//dfs lepszy
#include <cstdio>
#include <vector>
#include <queue>
int n,m,s,t;
int wynik=0;
bool bfs(std::vector<std::vector<int> > &graf,std::vector<std::vector<int> > &wagi)
{
    std::queue<int> kolejka;
    std::vector<bool> odwiedzone(n);
    std::vector<int> rodzic(n);
    rodzic[s]=-1;
    kolejka.push(s);
    bool znaleziono=false;
    while(!kolejka.empty())//szukaj ścieżek
    {
        int start=kolejka.front();
        if(start==t)
        {
            znaleziono=true;
            break;
        }
        odwiedzone[start]=true;
        kolejka.pop();
        for(int i=0;i<graf[start].size();i++)
            if(!odwiedzone[graf[start][i]])
                if(wagi[start][graf[start][i]])
                {
                    rodzic[graf[start][i]]=start;
                    kolejka.push(graf[start][i]);
                }
    }
    if(znaleziono)
    {
        int maxflow=1000000000;
        int now=t;
        while(rodzic[now]!=-1)//szukaj maksymalnego przeplywu na ścieżce
        {
            if(wagi[rodzic[now]][now]<maxflow)
                maxflow=wagi[rodzic[now]][now];
            now=rodzic[now];
        }
        now=t;
        while(rodzic[now]!=-1)//zapisz użyty przepływ
        {
            wagi[rodzic[now]][now]-=maxflow;
            wagi[now][rodzic[now]]+=maxflow;
            now=rodzic[now];
        }
        wynik+=maxflow;
        return true;
    }
    else
        return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    std::vector<std::vector<int> > graf(n);
    std::vector<int> tmp(n);
    std::vector<std::vector<int> > wagi(n,tmp);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c)
        {
            graf[a].push_back(b);
            graf[b].push_back(a);
            wagi[a][b]=c;
        }
    }
    scanf("%d%d",&s,&t);
    while(bfs(graf,wagi));
    printf("%d\n",wynik);
    return 0;
}

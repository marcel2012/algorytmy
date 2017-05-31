#include <cstdio>
#include <vector>
int wynik=0;
int s,t;
int dfs(std::vector<std::vector<int> > &graf,std::vector<std::vector<int> > &wagi,std::vector<bool> &odwiedzone,int start,int minflow)
{
    if(start==t)
    {
        wynik+=minflow;
        return minflow;
    }
    odwiedzone[start]=true;
    int w=0;
    for(int i=0;i<graf[start].size();i++)
        if(wagi[start][graf[start][i]])
            if(!odwiedzone[graf[start][i]])
            {
                int now=dfs(graf,wagi,odwiedzone,graf[start][i],std::min(minflow,wagi[start][graf[start][i]]));
                if(now)
                {
                    wagi[start][graf[start][i]]-=now;
                    wagi[graf[start][i]][start]+=now;
                    minflow-=now;
                    w+=now;
                }
                if(!minflow)
                    break;
            }
    odwiedzone[start]=false;
    return w;
}
int main()
{
    int n1,n2,m;
    scanf("%d%d%d",&n1,&n2,&m);
    std::vector<std::vector<int> > graf(n1+n2+2);
    std::vector<bool> odwiedzone(n1+n2+2);
    std::vector<int> tmp(n1+n2+2);
    std::vector<std::vector<int> > wagi(n1+n2+2,tmp);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        wagi[a][b]=1;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    s=n1+n2;
    t=s+1;
    for(int i=0;i<n1;i++)
    {
        wagi[s][i]=1;
        graf[s].push_back(i);
        graf[i].push_back(s);
    }
    for(int i=n1;i<n1+n2;i++)
    {
        wagi[i][t]=1;
        graf[t].push_back(i);
        graf[i].push_back(t);
    }
    while(dfs(graf,wagi,odwiedzone,s,10000000));
    printf("%d\n",wynik);
    return 0;
}

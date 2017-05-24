#include <cstdio>
#include <vector>
int n,m;
int s,t;
int dfs(std::vector<std::vector<int> > &dane,std::vector<bool> &odwiedzony,std::vector<std::vector<int> > &przeplyw,int start,int rodzic,int minflow)
{
    if(start==t)
        return minflow;
    for(int i=0;i<dane[start].size();i++)
        if(przeplyw[start][dane[start][i]]>0)
            if(!odwiedzony[dane[start][i]])
            {
                odwiedzony[dane[start][i]]=true;
                int maxflow=dfs(dane,odwiedzony,przeplyw,dane[start][i],start,std::min(minflow,przeplyw[start][dane[start][i]]));
                odwiedzony[dane[start][i]]=false;
                if(maxflow)
                {
                    przeplyw[start][dane[start][i]]-=maxflow;
                    przeplyw[dane[start][i]][start]+=maxflow;
                    return maxflow;
                }
            }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    std::vector<std::vector<int> > dane(n);
    std::vector<bool> odwiedzony(n);
    std::vector<int> tmp(n);
    std::vector<std::vector<int> > przeplyw(n,tmp);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dane[a].push_back(b);
        dane[b].push_back(a);
        przeplyw[a][b]=c;
    }
    scanf("%d%d",&s,&t);
    odwiedzony[s]=true;
    while(dfs(dane,odwiedzony,przeplyw,s,-1,100000000));
    int wynik=0;
    for(int i=0;i<dane[t].size();i++)
        wynik+=przeplyw[t][dane[t][i]];
    printf("wynik: %d\n",wynik);
    return 0;
}

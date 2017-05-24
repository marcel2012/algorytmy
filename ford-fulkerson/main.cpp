#include <cstdio>
#include <vector>
int n,m;
int s,t;
int wynik=0;
int dfs(std::vector<std::vector<int> > &sasiedzi,std::vector<bool> &odwiedzony,std::vector<std::vector<int> > &przeplyw,int start,int rodzic,int minflow)
{
    if(start==t)
    {
        wynik+=minflow;
        return minflow;
    }
    odwiedzony[start]=true;
    int maxflow=0;
    for(int i=0;i<sasiedzi[start].size();i++)
        if(przeplyw[start][sasiedzi[start][i]]>0)
            if(!odwiedzony[sasiedzi[start][i]])
            {
                int uzyte=dfs(sasiedzi,odwiedzony,przeplyw,sasiedzi[start][i],start,std::min(minflow,przeplyw[start][sasiedzi[start][i]]));
                if(uzyte)
                {
                    przeplyw[start][sasiedzi[start][i]]-=uzyte;
                    przeplyw[sasiedzi[start][i]][start]+=uzyte;
                    minflow-=uzyte;
                    maxflow+=uzyte;
                }
            }
    odwiedzony[start]=false;
    return maxflow;
}
int main()
{
    scanf("%d%d",&n,&m);
    std::vector<std::vector<int> > sasiedzi(n);
    std::vector<bool> odwiedzony(n);
    std::vector<int> tmp(n);
    std::vector<std::vector<int> > przeplyw(n,tmp);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        sasiedzi[a].push_back(b);
        sasiedzi[b].push_back(a);
        przeplyw[a][b]=c;
    }
    scanf("%d%d",&s,&t);
    while(dfs(sasiedzi,odwiedzony,przeplyw,s,-1,100000000));
    printf("wynik: %d\n",wynik);
    return 0;
}

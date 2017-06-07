#include <cstdio>
#include <vector>
bool wynik=false;
void dfs(std::vector<std::vector<int> > &graf,std::vector<bool> &odwiedzone,std::vector<bool> &przetworzone,int start)
{
    if(odwiedzone[start] && !przetworzone[start])
    {
        wynik=true;
        return;
    }
    if(!odwiedzone[start] && !przetworzone[start])
    {
        odwiedzone[start]=true;
        for(int i=0;i<graf[start].size();i++)
            dfs(graf,odwiedzone,przetworzone,graf[start][i]);
        przetworzone[start]=true;
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    std::vector<std::vector<int> > graf(n);
    std::vector<bool> odwiedzone(n);
    std::vector<bool> przetworzone(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        graf[a].push_back(b);
    }
    for(int i=0;i<n;i++)
        dfs(graf,odwiedzone,przetworzone,i);
    if(wynik)
        printf("cykliczny\n");
    else
        printf("acykliczny\n");
    return 0;
}

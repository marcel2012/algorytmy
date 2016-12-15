#include <cstdio>
#include <vector>
#include <algorithm>
struct krawedz
{
    int a,b,w;
};
struct wierzcholek
{
    int rodzic,wysokosc,id;
};
inline bool cmp(krawedz a,krawedz b)
{
    return a.w>b.w;
}
inline int korzen(std::vector <wierzcholek> &wierzcholki,int a)
{
    if(wierzcholki.at(a).id==wierzcholki.at(a).rodzic)
        return wierzcholki.at(a).id;
    return korzen(wierzcholki,wierzcholki.at(a).rodzic);
}
int main()
{
    int n,m,krawedzie_w_drzewie=0;
    scanf("%d%d",&n,&m);
    std::vector<krawedz> krawedzie(m);
    for(int i=0; i<m; i++)
        scanf("%d%d%d",&krawedzie.at(i).a,&krawedzie.at(i).b,&krawedzie.at(i).w);
    std::make_heap(krawedzie.begin(),krawedzie.end(),cmp);
    std::vector<wierzcholek> wierzcholki(n);
    for(int i=0; i<n; i++)
    {
        wierzcholki.at(i).rodzic=i;
        wierzcholki.at(i).wysokosc=0;
        wierzcholki.at(i).id=i;
    }
    do
    {
        int korzen1=korzen(wierzcholki,krawedzie.front().a);
        int korzen2=korzen(wierzcholki,krawedzie.front().b);
        if(korzen1!=korzen2)
        {
            printf("%d %d\n",krawedzie.front().a,krawedzie.front().b);
            if(wierzcholki.at(korzen1).wysokosc==wierzcholki.at(korzen2).wysokosc)
            {
                wierzcholki.at(korzen1).rodzic=korzen2;
                wierzcholki.at(korzen2).wysokosc++;
            }
            else if(wierzcholki.at(korzen1).wysokosc>wierzcholki.at(korzen2).wysokosc)
                wierzcholki.at(korzen2).rodzic=korzen1;
            else
                wierzcholki.at(korzen1).rodzic=korzen2;
            krawedzie_w_drzewie++;
        }
        std::pop_heap(krawedzie.begin(),krawedzie.end(),cmp);
        krawedzie.pop_back();
    }
    while(krawedzie_w_drzewie<n-1);
    return 0;
}

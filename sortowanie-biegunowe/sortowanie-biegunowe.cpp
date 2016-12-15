#include <cstdio>
#include <vector>
#include <algorithm>
struct punkt
{
    int x;
    int y;
};
inline int cwiartka(punkt a)
{
    if(a.x>=0)
        if(a.y>=0)
            return 1;
        else
            return 4;
    else if(a.y>=0)
        return 2;
    else
        return 3;
}
inline bool cmp(punkt a,punkt b)
{
    int ca=cwiartka(a);
    int cb=cwiartka(b);
    if(ca!=cb)
        return ca<cb;
    return a.y*(b.x+b.y)<b.y*(a.x+a.y);
}
int main()
{
    int n;
    scanf("%d",&n);
    std::vector <punkt> punkty(n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&punkty.at(i).x,&punkty.at(i).y);
    std::sort(punkty.begin(),punkty.end(),cmp);
    for(int i=0; i<n; i++)
        printf("%d %d\n",punkty.at(i).x,punkty.at(i).y);
    return 0;
}

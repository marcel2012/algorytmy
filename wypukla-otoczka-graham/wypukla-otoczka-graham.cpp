#include <cstdio>
#include <vector>
#include <algorithm>
int x0,y0;
inline double deg(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1 * y2 + x2 * y3 + x3 * y1 - y2 * x3 - y3 * x1 - y1 * x2;
}
inline bool cmp(std::pair <int,int>  a,std::pair <int,int>  b)
{
    return (a.first-x0)*(b.second-y0)>(b.first-x0)*(a.second-y0);
}
int main()
{
    int n,miny=0,mini=-2000000,i1=-1,i3,started=-1;
    scanf("%d",&n);
    std::vector <std::pair<int,int> > points(n);
    std::vector <int> otoczka;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&points.at(i).first,&points.at(i).second);
        if(i1==-1 || points.at(i).second<miny)
        {
            miny=points.at(i).second;
            i1=i;
        }
        else if(points.at(i).second==miny && points.at(i).first<points.at(i1).first)
        {
            //gdy y takie samo to wybieramy mniejszy x
            miny=points.at(i).second;
            i1=i;
        }
    }
    x0=points.at(i1).first;
    y0=points.at(i1).second;
    std::swap(points.at(i1),points.at(0));
    std::sort(points.begin()+1,points.end(),cmp);
    otoczka.push_back(0);
    otoczka.push_back(1);
    for(i3=2; i3<n; i3++)
    {
        otoczka.push_back(i3);
        while(otoczka.size()>2 && deg(points.at(otoczka.at(otoczka.size()-3)).first,points.at(otoczka.at(otoczka.size()-3)).second,points.at(otoczka.at(otoczka.size()-2)).first,points.at(otoczka.at(otoczka.size()-2)).second,points.at(otoczka.at(otoczka.size()-1)).first,points.at(otoczka.at(otoczka.size()-1)).second)<0)
        {
            //usuwamy przedostatni punkt tak długo jak idąc z przedprzedostatniedo do ostatniego przez przedostatni skręcamy w prawo
            otoczka.at(otoczka.size()-2)=otoczka.at(otoczka.size()-1);
            otoczka.resize(otoczka.size()-1);
        }
    }
    for(int i=0; i<otoczka.size(); i++)
        printf("%d %d\n",points.at(otoczka.at(i)).first,points.at(otoczka.at(i)).second);
    return 0;
}

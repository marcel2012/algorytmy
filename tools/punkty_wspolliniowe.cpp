#include <cstdio>
#include <vector>
inline double deg(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1 * y2 + x2 * y3 + x3 * y1 - y2 * x3 - y3 * x1 - y1 * x2;
}
int main()
{
    int n;
    scanf("%d",&n);
    std::vector <std::pair<int,int> > points(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&points.at(i).first,&points.at(i).second);
        for(int j=i-1;j>=0;j--)
            for(int k=j-1;k>=0;k--)
                if(!deg(points.at(i).first,points.at(i).second,points.at(j).first,points.at(j).second,points.at(k).first,points.at(k).second))
                {
                    printf("ERROR\n");
                    return -1;
                }
    }
    printf("OK\n");
    return 0;
}

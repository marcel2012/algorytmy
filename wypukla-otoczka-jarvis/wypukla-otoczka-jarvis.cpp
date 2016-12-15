#include <cstdio>
#include <vector>
inline double def(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1 * y2 + x2 * y3 + x3 * y1 - y2 * x3 - y3 * x1 - y1 * x2;
}
int main()
{
    int n,miny=0,mini=-2000000,i1=-1,i2,i3,started=-1;
    scanf("%d",&n);
    std::vector <std::pair<int,int> > points(n);
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
    //mamy wczytane punkty i mamy punkt o najmniejszym x wśród najmniejszego y
    printf("%d %d\n",points.at(i1).first,points.at(i1).second);
    while(true)
    {
        i2=i1==0;//i1 i i2 nie mogą być takie same
        for(i3=0; i3<n; i3++)
            if(i3!=i2 && i3!= i1)
            {
                float a=def(points.at(i1).first,points.at(i1).second,points.at(i2).first,points.at(i2).second,points.at(i3).first,points.at(i3).second);
                if(a<0)
                    i2=i3;
                else if(a==0)
                {
                    //współliniowość punktów - z pitagorasa wybieramy dalszy punkt
                    float pa,pb,pa2,pb2;
                    pa=points.at(i1).first-points.at(i2).first;
                    pb=points.at(i1).second-points.at(i2).second;
                    pa2=points.at(i1).first-points.at(i3).first;
                    pb2=points.at(i1).second-points.at(i3).second;
                    if(pa*pa+pb*pb<pa2*pa2+pb2*pb2)
                        i2=i3;
                }
            }
        if(started==-1)
            started=i1;
        i1=i2;
        if(started==i1)
            return 0;
        printf("%d %d\n",points.at(i2).first,points.at(i2).second);
    }
    return 0;
}

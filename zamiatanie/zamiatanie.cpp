#include <cstdio>
#include <vector>
#include <algorithm>
struct odcinek
{
    int x1,y1,x2,y2,index;
    bool poczatek;
};
inline int sgn(int wartosc)
{
    if(wartosc<0)
        return -1;
    else if(wartosc>0)
        return 1;
    else
        return false;
}
inline int deg(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2;
}
inline bool przecinanie(odcinek odc1,odcinek odc2)
{
    return (sgn(deg(odc1.x1,odc1.y1,odc1.x2,odc1.y2,odc2.x1,odc2.y1))==-1*sgn(deg(odc1.x1,odc1.y1,odc1.x2,odc1.y2,odc2.x2,odc2.y2)) && sgn(deg(odc2.x1,odc2.y1,odc2.x2,odc2.y2,odc1.x1,odc1.y1))==-1*sgn(deg(odc2.x1,odc2.y1,odc2.x2,odc2.y2,odc1.x2,odc1.y2)));
}
inline bool sorting(odcinek odc1,odcinek odc2)
{
    return odc1.x1<odc2.x1;
}
inline bool po_prawej(odcinek odc1,odcinek odc2)
{
    return deg(odc1.x1,odc1.y1,odc1.x2,odc1.y2,odc2.x1,odc2.y1)>0;
}
int szukaj(std::vector<int> &miotla,std::vector <odcinek> &dane,int start,int koniec,odcinek odc2)
{
    if(koniec==start)
        return koniec + po_prawej(dane.at(miotla.at(koniec)),odc2);
    int suma=koniec+start;
    int srodek=(suma+(suma&1))>>1;
    if(po_prawej(dane.at(miotla.at(srodek)),odc2))
        return szukaj(miotla,dane,srodek,koniec,odc2);
    return szukaj(miotla,dane,start,srodek-1,odc2);
}
int main()
{
    int n;
    scanf("%d",&n);
    std::vector <odcinek> dane(2*n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d%d",&dane.at(2*i).x1,&dane.at(2*i).y1,&dane.at(2*i).x2,&dane.at(2*i).y2);
        if(dane.at(2*i).x1>dane.at(2*i).x2)
        {
            std::swap(dane.at(2*i).x1,dane.at(2*i).x2);
            std::swap(dane.at(2*i).y1,dane.at(2*i).y2);
        }
        dane.at(2*i).poczatek=true;
        dane.at(2*i).index=i;
        dane.at(2*i+1).x1=dane.at(2*i).x2;
        dane.at(2*i+1).x2=dane.at(2*i).x1;
        dane.at(2*i+1).y1=dane.at(2*i).y2;
        dane.at(2*i+1).y2=dane.at(2*i).y1;
        dane.at(2*i+1).poczatek=false;
        dane.at(2*i+1).index=i;
    }
    sort(dane.begin(),dane.end(),sorting);
    std::vector <int> miotla;
    bool odp=false;
    for(int i=0; i<2*n && !odp; i++)
    {
        if(dane.at(i).poczatek)
            if(miotla.size())
            {
                int index=szukaj(miotla,dane,0,miotla.size()-1,dane.at(i));
                miotla.insert(miotla.begin()+index,i);
                if(index>0)
                    if(przecinanie(dane.at(miotla.at(index-1)),dane.at(miotla.at(index))))
                        odp=true;
                if(index<miotla.size()-1)
                    if(przecinanie(dane.at(miotla.at(index+1)),dane.at(miotla.at(index))))
                        odp=true;
            }
            else
                miotla.push_back(i);
        else
        {
            int index=0;
            while(dane.at(miotla.at(index)).index!=dane.at(i).index)
                index++;
            if(index>0 && index<miotla.size()-1)
                if(przecinanie(dane.at(miotla.at(index-1)),dane.at(miotla.at(index+1))))
                    odp=true;
            miotla.erase(miotla.begin()+index);
        }
    }
    if(odp)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    return 0;
}

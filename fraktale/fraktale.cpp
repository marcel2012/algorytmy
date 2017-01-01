#include <SFML/Graphics.hpp>
#include <cmath>
int w=1000;
int dokladnosc=8;
struct zespolona
{
    float r=-0.1,i=0.65;
};/*
struct zespolona
{
    float r=-0.390541,i=0.586788;
};*/
zespolona c;
inline zespolona kwadrat(zespolona a)
{
    zespolona tmp;
    tmp.r=a.r*a.r-a.i*a.i;
    tmp.i=2*a.r*a.i;
    return tmp;
}
inline zespolona dodawanie(zespolona a,zespolona b)
{
    zespolona tmp;
    tmp.r=a.r+b.r;
    tmp.i=a.i+b.i;
    return tmp;
}
inline int poziom(zespolona d,zespolona c)
{
    for(int i=0; i<dokladnosc*255; i++)
    {
        d=dodawanie(kwadrat(d),c);
        if(d.r*d.r+d.i+d.i>=4)
            return i/dokladnosc;
    }
    return 255;
}
inline void linia(int x1,int y1,int x2,int y2,sf::RenderWindow &window)
{
    sf::Vertex point[2];
    point[0].position=sf::Vector2f(x1,y1);
    point[1].position=sf::Vector2f(x2,y2);
    window.draw(point,2, sf::Lines);
}
inline void punkt(int x1,int y1,sf::RenderWindow &window,int color)
{
    //color=255-color;
    sf::Color col(color,color,color);
    sf::Vertex point[1];
    point[0]=sf::Vertex(sf::Vector2f(x1,y1),col);
    window.draw(point,1, sf::Points);
}
inline int po(int a,int b)
{
    int odp=1;
    while(b>=1)
    {
        odp*=a;
        b--;
    }
    return odp;
}
inline void kwadraty(int x,int y,int poziom,sf::RenderWindow &window)
{
    if(poziom<6)
    {
        linia(x,y,x+w/po(3,poziom-1),y,window);
        linia(x,y+w/po(3,poziom-1),x+w/po(3,poziom-1),y+w/po(3,poziom-1),window);
        linia(x+w/po(3,poziom-1),y,x+w/po(3,poziom-1),y+w/po(3,poziom-1),window);
        linia(x,y,x,y+w/po(3,poziom-1),window);
        kwadraty(x,y,poziom+1,window);
        kwadraty(x+w/po(3,poziom),y,poziom+1,window);
        kwadraty(x+2*w/po(3,poziom),y,poziom+1,window);
        kwadraty(x+2*w/po(3,poziom),y+w/po(3,poziom),poziom+1,window);
        kwadraty(x,y+w/po(3,poziom),poziom+1,window);
        kwadraty(x+w/po(3,poziom),y+2*w/po(3,poziom),poziom+1,window);
        kwadraty(x+2*w/po(3,poziom),y+2*w/po(3,poziom),poziom+1,window);
        kwadraty(x,y+2*w/po(3,poziom),poziom+1,window);
    }
}
inline void trojkaty(int x,int y,int poziom,sf::RenderWindow &window)
{
    if(poziom<6)
    {
        linia(x,y+w/po(2,poziom-1),x+w/po(2,poziom-1),y+w/po(2,poziom-1),window);
        linia(x+w/po(2,poziom),y,x+w/po(2,poziom-1),y+w/po(2,poziom-1),window);
        linia(x+w/po(2,poziom),y,x,y+w/po(2,poziom-1),window);
        trojkaty(x+w/po(2,poziom+1),y,poziom+1,window);
        trojkaty(x,y+w/po(2,poziom),poziom+1,window);
        trojkaty(x+w/po(2,poziom),y+w/po(2,poziom),poziom+1,window);
    }
}
inline void drzewo(int x,int y,int poziom,int kierunek,sf::RenderWindow &window)
{
    if(kierunek<-3)
        kierunek=4;
    if(kierunek>4)
        kierunek=-3;
    if(poziom<13)
    {
        int xtmp=x;
        int ytmp=y;
        if(kierunek==-1 || kierunek==-3)
            xtmp+=w/sqrt(2)/po(2,poziom);
        if(kierunek==-2)
            xtmp+=w/po(2,poziom);
        if(kierunek==1 || kierunek==3)
            xtmp-=w/sqrt(2)/po(2,poziom);
        if(kierunek==2)
            xtmp-=w/po(2,poziom);
        if(kierunek==-3 || kierunek==3)
            ytmp+=w/sqrt(2)/po(2,poziom);
        if(kierunek==4)
            ytmp+=w/po(2,poziom);
        if(kierunek==-1 || kierunek==1)
            ytmp-=w/sqrt(2)/po(2,poziom);
        if(kierunek==0)
            ytmp-=w/po(2,poziom);
        linia(x,y,xtmp,ytmp,window);
        drzewo(xtmp,ytmp,poziom+1,kierunek+1,window);
        drzewo(xtmp,ytmp,poziom+1,kierunek-1,window);
    }
}
inline void kantor(int x1,int x2,int poziom,sf::RenderWindow &window)
{
    if(poziom<10)
    {
        linia(x1,poziom*40,x2,poziom*40,window);
        kantor(x1,x1+(x2-x1)/3,poziom+1,window);
        kantor(x1+(x2-x1)*2/3,x2,poziom+1,window);
    }
}
int main()
{
    printf("%d",po(3,0));
    int odp;
    do
    {
        printf("Menu :\n\
               1. Dywan Sierpińskiego\n\
               2. Trójkąt Sierpińskiego\n\
               3. (X) Płatek Kocha\n\
               4. Drzewo binarne\n\
               5. Zbiór Cantora\n\
               6. Zbiór Julii\n\
               7. Koniec\n");
        scanf("%d",&odp);
        switch(odp)
        {
        case 1:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Fraktale");
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                kwadraty(0,0,1,window);
                window.display();
            }
        }
        break;
        case 2:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Fraktale");
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                trojkaty(0,0,1,window);
                window.display();
                window.setSize(sf::Vector2u(w,w*sqrt(3)/2));
            }
        }
        break;
        case 4:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Fraktale");
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                drzewo(w/2,w,1,0,window);
                window.display();
            }
            break;
        }
        case 5:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Fraktale");
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                kantor(0,w,1,window);
                window.display();
            }
        }
        break;
        case 6:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Fraktale");
            std::vector <int> linia(w,0);
            std::vector <std::vector<int> > pole(w,linia);
            int skala=3;
            float krok=skala/(float)w/(float)2;
            zespolona d;
            for(d.r=-1*skala; d.r<skala; d.r+=krok)
                for(d.i=-1*skala; d.i<skala; d.i+=krok)
                    if(d.r*w/skala+w/2>=0 && d.r*w/skala+w/2<w)
                        if(d.i*w/skala+w/2>=0 && d.i*w/skala+w/2<w)
                            pole.at(d.r*w/skala+w/2).at(d.i/skala*w+w/2)=poziom(d,c);
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                for(int i=0; i<w; i++)
                    for(int j=0; j<w; j++)
                        punkt(i,w-j,window,pole.at(i).at(j));
                window.display();
            }
        }
        break;
        case 7:
            printf("KONIEC");
            break;
        default :
            printf("zla odpowiedz");
            break;
        }
        printf("\n\n");
    }
    while(odp!=7);
    return 0;
}

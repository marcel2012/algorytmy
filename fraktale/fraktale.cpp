#include <SFML/Graphics.hpp>
#include <windows.h>
#include <cmath>
int w=500;
void linia(int x1,int y1,int x2,int y2,sf::RenderWindow &window)
{
    sf::Vertex point[2];
    point[0].position=sf::Vector2f(x1,y1);
    point[1].position=sf::Vector2f(x2,y2);
    window.draw(point,2, sf::Lines);
}
int po(int a,int b)
{
    int odp=1;
    while(b>=1)
    {
        odp*=a;
        b--;
    }
    return odp;
}
void kwadraty(int x,int y,int poziom,sf::RenderWindow &window)
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
void trojkaty(int x,int y,int poziom,sf::RenderWindow &window)
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
void drzewo(int x,int y,int poziom,int kierunek,sf::RenderWindow &window)
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
            xtmp+=x/sqrt(2)/po(2,poziom);
        if(kierunek==-2)
            xtmp+=x/po(2,poziom);
        if(kierunek==1 || kierunek==3)
            xtmp-=x/sqrt(2)/po(2,poziom);
        if(kierunek==2)
            xtmp-=x/po(2,poziom);
        if(kierunek==-3 || kierunek==3)
            ytmp+=y/sqrt(2)/po(2,poziom);
        if(kierunek==4)
            ytmp+=y/po(2,poziom);
        if(kierunek==-1 || kierunek==1)
            ytmp-=y/sqrt(2)/po(2,poziom);
        if(kierunek==0)
            ytmp-=y/po(2,poziom);
        linia(x,y,xtmp,ytmp,window);
        drzewo(xtmp,ytmp,poziom+1,kierunek+1,window);
        drzewo(xtmp,ytmp,poziom+1,kierunek-1,window);
            /*drzewo(x1,y1,(x1+x2)/3,(y1+y2)/3,window);
            drzewo(x1,y1,(x1+x2)/3,(y1+y2)/3,window);*/
    }
}
void kantor(int x1,int x2,int poziom,sf::RenderWindow &window)
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
    sf::RenderWindow window(sf::VideoMode(w,w), "Fraktale");
    do
    {
        printf("Menu :\n\
               1. Dywan Sierpińskiego\n\
               2. Trójkąt Sierpińskiego\n\
               3. Kocha\n\
               4. Drzewo binarne\n\
               5. Zbiór Cantora\n\
               6. Zbiór Julii\n");
        scanf("%d",&odp);
        system("cls");
        switch(odp)
        {
        case 1:
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
            break;
        case 2:
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
        break;
        case 4:
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
        case 5:
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
        break;
        case 7:
            window.close();
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

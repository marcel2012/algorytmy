#include <SFML/Graphics.hpp>
#include <cmath>
//#include <windows.h>
int w=800;//rozmiar okna
int dokladnosc=1;//dok³adnoœæ liczenia zbioru julii
int rekurencja_poziom=6;
unsigned int real_time=0;
struct zespolona
{
    //ustaw parametry zbioru Julii
    float r=-0.1,i=0.65;
};
zespolona c;
inline zespolona kwadrat(zespolona a)//potêgowanie liczb zespolonych
{
    zespolona tmp;
    tmp.r=a.r*a.r-a.i*a.i;
    tmp.i=2*a.r*a.i;
    return tmp;
}
inline zespolona dodawanie(zespolona a,zespolona b)//dodawanie liczb zespolonych
{
    zespolona tmp;
    tmp.r=a.r+b.r;
    tmp.i=a.i+b.i;
    return tmp;
}
inline int poziom(zespolona d,zespolona c)//sprawdzanie czy punkt po przekszta³ceniach d¹¿y do nieskoñczonoœci
{
    for(int i=0; i<dokladnosc*255; i++)
    {
        d=dodawanie(kwadrat(d),c);
        if(d.r*d.r+d.i+d.i>=4)
            return i/dokladnosc;
    }
    return 255;
}
inline void linia(int x1,int y1,int x2,int y2,sf::RenderWindow &window)//rysowanie linii
{
    sf::Vertex point[2];
    point[0].position=sf::Vector2f(x1,y1);
    point[1].position=sf::Vector2f(x2,y2);
    window.draw(point,2, sf::Lines);
    if(real_time)
        window.display();
}
inline void punkt(int x1,int y1,sf::RenderWindow &window,int color)//kolorowanie piksela
{
    sf::Color col(color,color,color);
    sf::Vertex point[1];
    point[0]=sf::Vertex(sf::Vector2f(x1,y1),col);
    window.draw(point,1, sf::Points);
    if(real_time)
        window.display();
}
inline int po(int a,int b)//potêgowanie takie, ¿e n^0==1
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
    if(poziom<rekurencja_poziom)
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
    if(poziom<rekurencja_poziom)
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
    //kierunwk :
    //0 góra
    //-1 prawo góra
    //-2 prawo
    //-3 prawo dół
    //1 lewo góra
    //2 lewo
    //3 lewo dół
    //4 dol
    if(kierunek<-3)
        kierunek=4;
    if(kierunek>4)
        kierunek=-3;
    if(poziom<rekurencja_poziom)
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
inline void koch(int x1,int y1,int x2,int y2,int poziom,sf::RenderWindow &window)
{
    int x4=x1-(x1-x2)/3,y4=y1-(y1-y2)/3,x5=x2-(x2-x1)/3,y5=y2-(y2-y1)/3;
    int x3=(x5-x4)*cos(M_PI/3)-(y5-y4)*sin(M_PI/3)+x4,y3=(x5-x4)*sin(M_PI/3)+(y5-y4)*cos(M_PI/3)+y4;
    if(poziom<rekurencja_poziom)
    {
        koch(x1,y1,x4,y4,poziom+1,window);
        koch(x5,y5,x2,y2,poziom+1,window);
        koch(x4,y4,x3,y3,poziom+1,window);
        koch(x3,y3,x5,y5,poziom+1,window);
    }
    else
    {
        linia(x4,y4,x3,y3,window);
        linia(x3,y3,x5,y5,window);
        linia(x1,y1,x2,y2,window);
    }
}
inline void kantor(int x1,int x2,int poziom,sf::RenderWindow &window)
{
    if(poziom<rekurencja_poziom)
    {
        linia(x1,poziom*40,x2,poziom*40,window);
        kantor(x1,x1+(x2-x1)/3,poziom+1,window);
        kantor(x1+(x2-x1)*2/3,x2,poziom+1,window);
    }
}
inline void zbior_julii(std::vector <std::vector<int> > &pole,sf::RenderWindow &window)
{
    for(int i=0; i<w; i++)
        for(int j=0; j<w; j++)
            if(pole.at(i).at(j))
                punkt(i,w-j,window,pole.at(i).at(j));
}
int main()
{
    int odp;
    printf("\n\n");
    while(true)
    {
        printf("Menu :\n\
                1. Dywan Sierpinskiego\n\
                2. Trojkat Sierpinskiego\n\
                3. (X) Platek Kocha\n\
                4. Drzewo binarne\n\
                5. Zbior Cantora\n\
                6. Zbior Julii\n\
                \n\
                Ustawienia dodatkowe\n\
                \n\
                Maksymalny poziom rekurencji : %d\n\
                Parametr c Zbioru Julii : %f %f\n\
                Dokladnosc liczenia Zbioru Julii: %d\n\
                Tryb rysowania : %s\n\
                \n\
                7. Edytuj maksymalny poziom rekurencji\n\
                8. Edytuj parametr c Zbioru Julii\n\
                9. Edytuj dokladnosc liczenia Zbioru Julii\n\
                10. Edytuj rodzaj rysowania\n\
                \n\
                11. Koniec\n\
                \n\
                Podaj liczbe : \
               ",rekurencja_poziom,c.r,c.i,dokladnosc,(real_time==0?"raz a dobrze":"w czasie rzeczywistym"));
        scanf("%d",&odp);
        system("cls");
        switch(odp)
        {
        case 1:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Dywan sierpinskiego");
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
            sf::RenderWindow window(sf::VideoMode(w,w), "Trojkat Sierpinskiego");
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
        case 3:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Koch");
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                window.clear();
                int x5=100,y5=w-200,x4=w-100,y4=w-200;
                int x3=(x5-x4)*cos(M_PI/3)-(y5-y4)*sin(M_PI/3)+x4,y3=(x5-x4)*sin(M_PI/3)+(y5-y4)*cos(M_PI/3)+y4;
                koch(x5,y5,x4,y4,0,window);
                koch(x4,y4,x3,y3,0,window);
                koch(x3,y3,x5,y5,0,window);
                window.display();
            }
        }
        break;
        case 4:
        {
            sf::RenderWindow window(sf::VideoMode(w,w), "Drzewo binarne");
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
            sf::RenderWindow window(sf::VideoMode(w,w), "Cantor");
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
            sf::RenderWindow window(sf::VideoMode(w,w), "Zbior Julii");
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
                zbior_julii(pole,window);
                window.display();
            }
        }
        break;
        case 7:
            system("cls");
            printf("Podaj maksymalny poziom rekurencji : ");
            scanf("%d",&rekurencja_poziom);
            break;
        case 8:
            system("cls");
            printf("Podaj parametry c Zbioru Julii : ");
            scanf("%f%f",&c.r,&c.i);
            break;
        case 9:
            system("cls");
            printf("Podaj dokladnosc liczenia Zbioru Julii : ");
            scanf("%d",&dokladnosc);
            break;
        case 10:
            system("cls");
            printf("0 - raz a dobrze (szybkie)\n1 - w czasie rzeczywistym (wolne): ");
            scanf("%d",&real_time);
            if(real_time>1)
            {
                printf("zla odpowiedz\nustawiono wartosc domyslna");
                real_time=0;
            }
            break;
        case 11:
            printf("KONIEC");
            return 0;
            break;
        default :
            printf("zla odpowiedz");
            break;
        }
        printf("\n\n");
    }
    return 0;
}

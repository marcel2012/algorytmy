#include <SFML/Graphics.hpp>
using namespace std;
int wx=800,wy=800;
int k_height=50;
int d_height=180;
void linia(int x1,int y1,int x2,int y2,sf::RenderWindow &window)
{
    sf::Vertex point[2];
    point[0].position=sf::Vector2f(x1,y1);
    point[1].position=sf::Vector2f(x2,y2);
    window.draw(point,2, sf::Lines);
}
void kantor(int x1,int x2,int y,sf::RenderWindow &window)
{
    if(y<wy)
    {
        linia(x1,y,x2,y,window);
        kantor(x1,x1+(x2-x1)/3,y+k_height,window);
        kantor(x1+(x2-x1)*2/3,x2,y+k_height,window);
    }
}
void kwadraty(int x,int y,int w,sf::RenderWindow &window)
{
    if(w>2)
    {
        linia(x,y,x+w,y,window);
        linia(x,y+w,x+w,y+w,window);
        linia(x+w,y,x+w,y+w,window);
        linia(x,y,x,y+w,window);
        kwadraty(x,y,w/3,window);
        kwadraty(x+w/3,y,w/3,window);
        kwadraty(x+w*2/3,y,w/3,window);
        kwadraty(x+w*2/3,y+w/3,w/3,window);
        kwadraty(x,y+w/3,w/3,window);
        kwadraty(x+w/3,y+w*2/3,w/3,window);
        kwadraty(x+w*2/3,y+w*2/3,w/3,window);
        kwadraty(x,y+w*2/3,w/3,window);
    }
}
void drzewo(int x,int y,int w,int h,sf::RenderWindow &window)
{
    if(h>20)
    {
        linia(x,y,x-w,y-h,window);
        linia(x,y,x+w,y-h,window);
        drzewo(x-w,y-h,w/2,h/2,window);
        drzewo(x+w,y-h,w/2,h/2,window);
    }
    else
    {
        sf::CircleShape shape(10.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(x-10,y-10);
        window.draw(shape);
    }
}
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(wx,wy), "SFML works!");
    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        
        //do wyboru
        
        //kantor(0,wx,1,window);
        //kwadraty(0,0,min(wx,wy),window);
        //drzewo(wx/2,wy-1,wx/4,d_height*2,window);
        window.display();
    }
    return 0;
}

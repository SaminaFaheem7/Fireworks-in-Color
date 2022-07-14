#include <iostream>
#include <cassert>
#include <array>
#include <vector>
#include "Pixel.h"
#include "Renderer.h"
#include <ctime>
int main()
{
    srand(time(nullptr));
    using namespace std;
    typedef vector<vector<char>> Art;
    typedef vector<Art> Arts;
    //Define a variable for the container with the firework arts.
    Arts fireworks;

    //Populate that container with four Art instances Use the ASCII art samples from the comment above.
    Art firework1 =
            {
                    {'.','*',' ','*','.',' '},
                    {' ', '*', '.', '.', '*'},
                    {' ', ' ', ' ', '*', ' '}
            };
    Art firework2=
            {
                    {'`', 'o', '`', 'o', '`', ' ', ' '},
                    {'o', '`', 'o', '`', 'o', '`', 'o'},
                    {' ', '`', 'o', '`', 'o', '`', ' '}
            };
    Art firework3=
            {
                    {' ',' ','^',',','^',',','^',' ',' '},
                    {'^',',','^',',','^',',','^',',','^'},
                    {'^',',','^',',','^',',','^',',','^'},
                    {' ',' ','^',',','^',',','^',' ',' '}
            };
    Art firework4=
            {
                    {' ',' ',' ','~','@','~','@','~',' ',' ',' '},
                    {'~','*','~','@','~','*','~','@','~','*','~'},
                    {'~','*','~','@','$','#','$','@','~','*','~'},
                    {'~','*','~','@','~','*','~','@','~','*','~'},
                    {' ',' ',' ','~','@','~','@','~',' ',' ',' '}
            };

    fireworks.push_back(firework1);
    fireworks.push_back(firework2);
    fireworks.push_back(firework3);
    fireworks.push_back(firework4);


    //Create an instance of the PixelBuffer.
    PixelBuffer b;

    //Create a container to store Renderers.
    vector<Renderer*> container;

    /*Add 3 instances of SolidColor renderers to the container with renderers. Use the following colors:
     * Pixel::Color::WHITE, Pixel::Color::CYAN, Pixel::Color::MAGENTA */
    SolidColor* WhiteRender   = new SolidColor(Pixel::Color::WHITE);
    SolidColor* CyanRender    = new SolidColor(Pixel::Color::CYAN);
    SolidColor* MagentaRender = new SolidColor(Pixel::Color::MAGENTA);

    container.push_back(WhiteRender);
    container.push_back(CyanRender);
    container.push_back(MagentaRender);

    //Add 2 instances of RandomColor renderers to the container with renderers.

    RandomColor*RandomRender1 = new RandomColor();
    RandomColor*RandomRender2 = new RandomColor();

    container.push_back(RandomRender1);
    container.push_back(RandomRender2);

    //Implement the user loop
    string Input;
    cout <<"Do you want to see the fireworks?(y/n)";
    cin>>Input;

    while(Input == "y"||Input=="yes")
    {
        b.init();

        int numberOfFireworks = rand() % 10 + 1;
        for(int i=0; i<numberOfFireworks; i++)
        {
            int RandomFirework = rand() % fireworks.size();
            int RandomRenderer = rand() % container.size();
            container.at(RandomRenderer)->render(fireworks.at(RandomFirework),b);
        }
        b.render();

        cout <<"Do you want to see the fireworks?(y/n)";
        cin>>Input;

    }
    //Cleanup whatever is needed
    for(auto & renderer: container)
    {
        delete renderer;
    }

    return 0;
}
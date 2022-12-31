#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

const int WINDOW_WIDTH = 800, WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "Breakout - https://github.com/arencoskun";
sf::Clock deltaClock;
sf::Time deltaTime;

void Update(float dt)
{
    std::cout << "Update. (" << dt << ")" << std::endl;
}

void Draw(sf::RenderWindow& wnd)
{
    wnd.clear();
    wnd.display();
}

void GameLoop(sf::RenderWindow& wnd)
{
    while (wnd.isOpen())
    {
        sf::Event event;
        while (wnd.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                wnd.close();
        }

        Update(deltaClock.restart().asSeconds());
        Draw(wnd);
    }
}

int main()
{
    sf::RenderWindow wnd(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    
    GameLoop(wnd);

    return 0;
}
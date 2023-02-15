// Задание workshop1.3  Котик
#include <SFML/Graphics.hpp>

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window)
{
    window.clear(sf::Color(0xFF, 0xFF, 0xFF));
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cat in the window");
    sf::Texture texture;
    texture.loadFromFile("cat.png");
    sf::Sprite sprite(texture);
    sprite.setPosition(400, 300);

    if (!texture.loadFromFile("cat.png"))
    {
        exit(1);
    }

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window);
        window.draw(sprite);
        window.display();
    }
}

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({130, 350}), "Traffic light");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({110, 330});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(0x80, 0x80, 0x80));
    window.draw(shape1);

    sf::CircleShape shape2(50);
    shape2.setPosition({15, 20});
    shape2.setFillColor(sf::Color(0x0, 0x80, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(50);
    shape3.setPosition({15, 125});
    shape3.setFillColor(sf::Color(0xFF, 0xD7, 0x0));

    window.draw(shape3);

    sf::CircleShape shape4(50);
    shape4.setPosition({15, 230});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}
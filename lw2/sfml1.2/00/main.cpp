#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({650, 400}), "My initials");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({630, 380});
    shape1.setPosition({10, 10});
    shape1.setFillColor(sf::Color(0x4B, 0x0, 0x82));
    window.draw(shape1);

    sf::CircleShape shape2(80);
    shape2.setPosition({68, 30});
    shape2.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape2);

    sf::CircleShape shape3(95);
    shape3.setPosition({58, 188});
    shape3.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape3);

    sf::CircleShape shape4(77);
    shape4.setPosition({79, 35});
    shape4.setFillColor(sf::Color(0x4B, 0x0, 0x82));
    window.draw(shape4);

    sf::CircleShape shape5(89);
    shape5.setPosition({58, 189});
    shape5.setFillColor(sf::Color(0x4B, 0x0, 0x82));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({10, 345});
    shape6.setPosition({280, 30});
    shape6.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({60, 10});
    shape7.setPosition({280, 185});
    shape7.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({10, 345});
    shape8.setPosition({340, 30});
    shape8.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({10, 358});
    shape9.setRotation(15);
    shape9.setPosition({485, 30});
    shape9.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({10, 358});
    shape10.setRotation(-15);
    shape10.setPosition({485, 30});
    shape10.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({90, 10});
    shape11.setPosition({445, 185});
    shape11.setFillColor(sf::Color(0xFF, 0xB6, 0xC1));
    window.draw(shape11);

    window.display();

    sf::sleep(sf::seconds(5));
}
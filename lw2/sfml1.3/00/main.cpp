#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({900, 700}), "The House");
    window.clear();

    //background
    sf::RectangleShape shape1;
    shape1.setSize({900, 700});
    shape1.setPosition({0, 0});
    shape1.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    window.draw(shape1);

    //walls
    sf::RectangleShape shape2;
    shape2.setSize({570, 300});
    shape2.setPosition({185, 375});
    shape2.setFillColor(sf::Color(0x4D, 0x2E, 0x0B));
    window.draw(shape2);

    //the door
    sf::RectangleShape shape3;
    shape3.setSize({95, 205});
    shape3.setPosition({245, 470});
    shape3.setFillColor(sf::Color(0x18, 0x17, 0x17));
    window.draw(shape3);

    //the roof
    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0x50, 0x16, 0x12));
    trapeze.setPosition(470, 250);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-160, 0});
    trapeze.setPoint(1, {+160, 0});
    trapeze.setPoint(2, {+320, 140});
    trapeze.setPoint(3, {-320, 140});
    window.draw(trapeze);

    //smoke
    sf::CircleShape shape4(23);
    shape4.setPosition({575, 158});
    shape4.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape4);

    sf::CircleShape shape5(25);
    shape5.setPosition({590, 115});
    shape5.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape5);

    sf::CircleShape shape6(30);
    shape6.setPosition({610, 80});
    shape6.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape6);

    sf::CircleShape shape7(32);
    shape7.setPosition({620, 40});
    shape7.setFillColor(sf::Color(0xC0, 0xC0, 0xC0));
    window.draw(shape7);

    //vertical part of the chimney
    sf::RectangleShape shape8;
    shape8.setSize({41, 73});
    shape8.setPosition({565, 225});
    shape8.setFillColor(sf::Color(0x59, 0x56, 0x56));
    window.draw(shape8);

    //horizontal part of the chimney
    sf::RectangleShape shape9;
    shape9.setSize({80, 40});
    shape9.setPosition({545, 200});
    shape9.setFillColor(sf::Color(0x59, 0x56, 0x56));
    window.draw(shape9);

    window.display();

    sf::sleep(sf::seconds(5));
}
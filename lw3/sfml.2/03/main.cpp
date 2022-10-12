#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Sinusoid motion");
    sf::Clock clockX;
    sf::Clock clockY;

    constexpr float BALL_SIZE = 40;
    sf::CircleShape ball(BALL_SIZE);

    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    sf::Vector2f position = {10.f, 0};

    float speedX = 200.f;
    float amplitudeY = 80.f;
    float periodY = 2;
    float levelY = 200;

    // Выполняем основной цикл программы
    while (window.isOpen())
    {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float deltaTimeY = clockY.getElapsedTime().asSeconds();
        const float deltaTimeX = clockX.restart().asSeconds();
        float wavePhase = float(2 * M_PI) * deltaTimeY;

        // Отскок от границ экрана
        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0))
        {
            speedX = -speedX;
        }
        if ((position.x < 0) && (speedX < 0))
        {
            speedX = -speedX;
        }

        position.x += speedX * deltaTimeX;
        position.y = amplitudeY * std::sin(wavePhase / periodY) + levelY;

        ball.setPosition(position);

        // Рисование текущего состояния
        window.clear();
        window.draw(ball);
        window.display();
    }
}
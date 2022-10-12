#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 100;
    constexpr int radiusSize = 200;
    constexpr float circleRadius = 150;
    float changedAngle = 0;
    sf::Clock clock;

    // Создаём окно с параметрами сглаживания
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Polar star",
        sf::Style::Default, settings);

    //Объявляем фигуру, которая будет выглядеть как эллипс
    sf::ConvexShape star;

    const sf::Vector2f starCenter = {400, 300};
    star.setFillColor(sf::Color(0xFF, 0x00, 0xFF));

    // Инициалиируем вершины псевдо-эллипса
    star.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float ellipseRadius = radiusSize * std::sin(6 * angle);
        sf::Vector2f point = {
            ellipseRadius * std::sin(angle),
            ellipseRadius * std::cos(angle)};
        star.setPoint(pointNo, point);
    }

    // Выполлняем основной цикл программы
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float dt = clock.restart().asSeconds();
        changedAngle += dt * 5; // dt * 5; 5 = Скорость   // -+ => вращение в другую сторону

        float x1 = starCenter.x + circleRadius * std::sin(changedAngle); // координата объекта по Х = коорд.центра по х + радиус * синус(углав радианах)
        float y1 = starCenter.y + circleRadius * std::cos(changedAngle); // (z* changedAngle); z = Скорость

        star.setPosition({x1, y1});

        // Рисование текущего состояния

        window.clear();
        window.draw(star);
        window.display();
    }
}
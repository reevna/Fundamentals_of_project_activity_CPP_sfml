#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

const sf::Vector2f leftEyeCenter = { 300, 300 };
const sf::Vector2f rightEyeCenter = { 470, 300 };
constexpr float circleRadius = 50;
float changedAngle = 0;

// Переводит радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обрабатывает событие MouseMove, обновляя позицию мыши
void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = { float(event.x), float(event.y) };
}

// Опрашивает и обрабатывает доступные события в цикле
void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow& window, sf::ConvexShape& leftPupil, sf::ConvexShape& rightPupil, sf::ConvexShape& leftEye, sf::ConvexShape& rightEye)
{
    window.clear();
    window.draw(leftEye);
    window.draw(rightEye);
    window.draw(leftPupil);
    window.draw(rightPupil);
    window.display();
}

// Рисует и выводит глаза
void inisialiseEyes(sf::RenderWindow& window, sf::ConvexShape& leftEye, sf::ConvexShape& rightEye, sf::ConvexShape& leftPupil, sf::ConvexShape& rightPupil)
{
    constexpr int pointCount = 100;
    const sf::Vector2f leftEyeRadius = { 80.f, 120.f };
    const sf::Vector2f rightEyeRadius = { 80.f, 120.f };
    const sf::Vector2f leftPupilRadius = { 20.f, 20.f };
    const sf::Vector2f rightPupilRadius = { 20.f, 20.f };

    //Объявляем левый глаз
    leftEye.setPosition({ 300, 300 });
    leftEye.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));
    //правый глаз
    rightEye.setPosition({ 470, 300 });
    rightEye.setFillColor(sf::Color(0xFF, 0xFF, 0XFF));

    // Инициалиируем вершины левого глаза
    leftEye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);

        sf::Vector2f point = {
            leftEyeRadius.x * std::sin(angle),
            leftEyeRadius.y * std::cos(angle)
        };
        leftEye.setPoint(pointNo, point);
    }

    // Инициалиируем вершины правого глаза
    rightEye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);

        sf::Vector2f point = {
            rightEyeRadius.x * std::sin(angle),
            rightEyeRadius.y * std::cos(angle)
        };
        rightEye.setPoint(pointNo, point);
    }

    // Объявляем левый зрачок
    leftPupil.setPosition({ 300, 300 });
    leftPupil.setFillColor(sf::Color(0x00, 0x00, 0XFF));
    //правый зрачок
    rightPupil.setPosition({ 470, 300 });
    rightPupil.setFillColor(sf::Color(0x00, 0x00, 0XFF));

    // Инициалиируем вершины leftPupil
    leftPupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);

        sf::Vector2f point = {
            leftPupilRadius.x * std::sin(angle),
            leftPupilRadius.y * std::cos(angle)
        };
        leftPupil.setPoint(pointNo, point);
    }

    // Инициалиируем вершины правого зрачка
    rightPupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);

        sf::Vector2f point = {
            rightPupilRadius.x * std::sin(angle),
            rightPupilRadius.y * std::cos(angle)
        };
        rightPupil.setPoint(pointNo, point);
    }
}

// Обновляет фигуру, указывающую на мышь
void updateLeft(const sf::Vector2f& mousePosition, sf::ConvexShape& leftPupil, float dt)
{
    const sf::Vector2f delta = mousePosition - leftPupil.getPosition();
    const float angle = atan2(delta.y, delta.x);
    const float angleDegrees = toDegrees(angle);
    // changedAngle += dt; // dt * 5; 5 = Скорость   // -+ => вращение в другую сторону

    float x1 = leftEyeCenter.x + circleRadius * std::sin(-angle); // координата объекта по Х = коорд.центра по х + радиус * синус(углав радианах)
    float y1 = leftEyeCenter.y + circleRadius * std::cos(-angle); // (z* changedAngle); z = Скорость

    //  leftPupil.setRotation(angleDegrees);
    leftPupil.setPosition({ x1, y1 });
}

void updateRight(const sf::Vector2f& mousePosition, sf::ConvexShape& rightPupil, float dt)
{
    const sf::Vector2f delta = mousePosition - rightPupil.getPosition();
    const float angle = atan2(delta.y, delta.x);
    const float angleDegrees = toDegrees(angle);
    // changedAngle += dt; // dt * 5; 5 = Скорость   // -+ => вращение в другую сторону

    float x2 = rightEyeCenter.x + circleRadius * std::sin(-angle); // координата объекта по Х = коорд.центра по х + радиус * синус(углав радианах)
    float y2 = rightEyeCenter.y + circleRadius * std::cos(-angle); // (z* changedAngle); z = Скорость

    //  leftPupil.setRotation(angleDegrees);

    rightPupil.setPosition({ x2, y2 });
    std::cout << "rightPupil = " << x2 << y2 << std::endl;
}

int main()
{

    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::Vector2f mousePosition;
    sf::Clock clock;

    sf::RenderWindow window(
        sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
        "Eyes follows mouse",
        sf::Style::Default,
        settings);

    sf::ConvexShape leftEye;
    sf::ConvexShape rightEye;
    sf::ConvexShape leftPupil;
    sf::ConvexShape rightPupil;
    inisialiseEyes(window, leftEye, rightEye, leftPupil, rightPupil);
    float dt = clock.restart().asSeconds();

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

        // Рисование текущего состояния
        window.clear();
        redrawFrame(window, leftPupil, rightPupil, leftEye, rightEye);
        pollEvents(window, mousePosition);
        updateLeft(mousePosition, leftPupil, dt);
        updateRight(mousePosition, rightPupil, dt);
    }
    window.display();
}
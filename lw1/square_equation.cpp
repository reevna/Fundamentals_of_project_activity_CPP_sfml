#include <cstdio>
#include <cmath>

int main()
{
    //1.prompt user to enter coefficients
    std::puts("please enter a, b and c for `ax^2 + bx + c = 0`:");

    //2. read coefficients for equation `ax + b = 0`
    float a = 0;
    float b = 0;
    float c = 0;
    std::scanf("%f %f %f", &a, &b, &c);

    // 3. solve equation `ax^2 + bx + c = 0`
    // D = b2 − 4ac
    // solution: `x1 = (-b + root from (b^2 - 4ac) ) /2a`
    // second solution: `x2 = (-b - root from (b^2 - 4ac) ) /2a`
    // get result from b^2
    float square = pow(b, 2);
    float discr = square - (4 * a * c);
    float discr1 = -b / 2 * a;
    float x1 = (-b + std::sqrt(square - 4 * a * c)) / (2 * a);
    float x2 = (-b - std::sqrt(square - 4 * a * c)) / (2 * a);
    if (discr < 0)
    {
        std::printf("There are no solutions to this equation");
    }
    else if (discr == 0)
    {
        std::printf("solution: %f\n", discr1);
    }
    else
    {
        std::printf("solutions are: %f and %f\n", x1, x2);
    }
}
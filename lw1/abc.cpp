#include <cstdio>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::scanf("%d %d %d", &a, &b, &c);
    int d = a + b + c;
    std::printf("The summ of the digits is %d", d);
}
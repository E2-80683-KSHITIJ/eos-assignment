
#include"circle.h"
#include"square.h"
#include"rectangle.h"



int main()
{
    float radius;
    int side,length,breadth;
    printf("Enter the radius of circle\n");
    scanf("%f", &radius);
    printf("\n");
    circle_area(radius);
    printf("\n");

    printf("Enter length of side of square\n");
    scanf("%d", &side);
    printf("\n");
    square(side);
    printf("\n");

    printf("Enter length and breadth of rectangle\n");
    scanf("%d %d", &length, &breadth);
    printf("\n");
    rectangle(length,breadth);
    printf("\n");

    return 0;
}
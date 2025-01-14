#include "Circle.h"
#include <cstdio>

//–ÊÏ‚ğŒvZ
double Circle::Size() const {
    return 3.14159 * radius_ * radius_;
}

//–ÊÏ‚ğ•\¦
void Circle::Draw() const {
    printf("‰~‚Ì–ÊÏ‚Í: %.2f\n", Size());
}
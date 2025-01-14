#include "Rectangle.h"
#include <cstdio>

//–ÊÏ‚ğŒvZ
double Rectangle::Size() const {
    return width_ * height_;
}

//–ÊÏ‚ğ•\¦
void Rectangle::Draw() const {
    printf("‹éŒ`‚Ì–ÊÏ‚Í: %.2f\n", Size());
}
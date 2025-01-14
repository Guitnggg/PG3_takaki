#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

int main()
{
    //インスタンスを作成
   
    // 円の半径
    Circle circle(3.0);
    
    // 矩形の幅
    Rectangle rectangle(5.0, 5.0);

    circle.Draw();
    rectangle.Draw();

    return 0;
}
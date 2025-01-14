#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
    //コンストラクタ
    Rectangle(double width, double height) : width_(width), height_(height) {}

    //面積を計算
    double Size() const override;

    //面積を表示
    void Draw() const override;

private:
    double width_;
    double height_;
};
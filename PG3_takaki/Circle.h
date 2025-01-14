#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
    //コンストラクタ
    Circle(double radius) : radius_(radius) {}

    //面積を計算
    double Size() const override;

    //面積を表示
    void Draw() const override;

private:
    double radius_;
};
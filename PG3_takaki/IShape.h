#pragma once

class IShape
{
public:
    //面積を計算
    virtual double Size() const = 0;

    //面積を表示
    virtual void Draw() const = 0;

    //デストラクタ
    virtual ~IShape() = default;
};
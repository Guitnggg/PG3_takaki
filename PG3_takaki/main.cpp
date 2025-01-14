#include <stdio.h>

// 抽象クラス IShape
class IShape {
public:
    virtual void Size() = 0; // 純粋仮想関数
    virtual void Draw() = 0; // 純粋仮想関数

protected:
    float size;   // 面積を保存
    float radius; // 半径または辺長を保存
};

// 円クラス
class Circle : public IShape {
public:
    void Size() override {
        radius = 5.0f; // 円の半径を設定
        printf("円の半径: %f\n", radius);
        size = radius * radius * 3.14f; // 面積を計算
    }

    void Draw() override {
        printf("円の面積: %f\n", size);
    }
};

// 四角形クラス
class Rectangle : public IShape {
public:
    void Size() override {
        radius = 5.0f; // 辺の半分の長さを設定
        printf("矩形の辺長: %f\n", radius * 2.0f);
        size = radius * 2.0f * radius * 2.0f; // 面積を計算
    }

    void Draw() override {
        printf("矩形の面積: %f\n", size);
    }
};

int main(void) {
    // IShape のポインタ配列に Circle と Rectangle を格納
    IShape* ishape[2] = { new Circle(), new Rectangle() };

    // 各オブジェクトの Size と Draw を呼び出し
    ishape[0]->Size();
    ishape[1]->Size();

    ishape[0]->Draw();
    ishape[1]->Draw();

    // メモリ解放
    delete ishape[0];
    delete ishape[1];

    return 0;
}

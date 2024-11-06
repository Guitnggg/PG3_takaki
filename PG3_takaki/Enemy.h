#include <stdio.h>

class Enemy {
public:
    //コンストラクタ
    Enemy();

    //更新
    void Update();

private:
    // 状態関数
    void Approach();
    void Shoot();
    void Retreat();

    //関数ポインタ定義
    using State = void (Enemy::*)();

    // 現在の状態
    State currentState;
};
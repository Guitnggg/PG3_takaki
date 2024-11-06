#include "Enemy.h"

//‰Šúó‘Ô‚ÍÚ‹ß
Enemy::Enemy() : currentState(&Enemy::Approach) {}

//XV
void Enemy::Update() {
    (this->*currentState)();
}

//Ú‹ß
void Enemy::Approach() {
    printf("“G‚ªÚ‹ß!\n");
    currentState = &Enemy::Shoot;
}
//ËŒ‚
void Enemy::Shoot() {
    printf("“G‚ªËŒ‚!\n");
    currentState = &Enemy::Retreat;
}
//—£’E
void Enemy::Retreat() {
    printf("“G‚ª—£’E!\n");
    currentState = &Enemy::Approach;
}
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// 動物の基底クラス
class Animal {
public:
    virtual void makeSound() const = 0; // 仮想関数
};

// 犬クラス
class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "ワンワン" << endl;
    }
};

// 猫クラス
class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "ニャー" << endl;
    }
};

// 鳥クラス
class Bird : public Animal {
public:
    void makeSound() const override {
        cout << "チュンチュン" << endl;
    }
};

int main() {
    vector<Animal*> animals = { new Dog(), new Cat(), new Bird() };

    for (const auto& animal : animals) {
        animal->makeSound(); // ポリモーフィズムにより異なる動物が適切な鳴き声を出す
    }

    // メモリ解放
    for (const auto& animal : animals) {
        delete animal;
    }

    return 0;
}

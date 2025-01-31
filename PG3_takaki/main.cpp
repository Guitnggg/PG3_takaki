#include <iostream>
#include <string>
#include <chrono>

int main() {
   
    std::string a(1000000, 'a');

    // コピーの時間を計測
    auto start_copy = std::chrono::high_resolution_clock::now();

    std::string b = a;  // コピー
 
    auto end_copy = std::chrono::high_resolution_clock::now();
    auto copy_time = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // 移動の時間を計測
    auto start_move = std::chrono::high_resolution_clock::now();
   
    std::string c = std::move(a);  // 移動
    
    auto end_move = std::chrono::high_resolution_clock::now();
    auto move_time = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();

    // 結果を表示
    std::cout << "コピーにかかった時間: " << copy_time << " μs" << std::endl;
    std::cout << "移動にかかった時間: " << move_time << " μs" << std::endl;

    return 0;
}

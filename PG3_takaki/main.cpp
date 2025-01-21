#include <iostream>
#include <list>

using namespace std;

void displayList(const list<const char*>& stations, const char* year) {
    cout << "\n--- Yamanote Line Stations in " << year << " ---" << endl;
    for (const auto& station : stations) {
        cout << station << endl;
    }
}

int main() {
    // 1970年の山手線のリスト
    list<const char*> stations1970 = {
        "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno",
        "Uguisudani", "Nippori", "Tabata", "Komagome",
        "Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba",
        "Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
        "Ebisu", "Meguro", "Gotanda", "Osaki", "Shinagawa",
        "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
    };

    // 1970年の駅を表示
    displayList(stations1970, "1970");

	// 西日暮里駅開業に伴い、2019年に西日暮里駅を追加
    list<const char*> stations2019 = stations1970;
    auto it2019 = stations2019.begin();
    for (; it2019 != stations2019.end(); ++it2019) {
        if (string(*it2019) == "Nippori") {
            ++it2019; 
            stations2019.insert(it2019, "Nishi-Nippori");
            break;
        }
    }

	// 高縄ゲートウェイ駅開業に伴い、2022年に高輪ゲートウェイ駅を追加
    list<const char*> stations2022 = stations2019;
    auto it2022 = stations2022.begin();
    for (; it2022 != stations2022.end(); ++it2022) {
        if (string(*it2022) == "Tamachi") {
            ++it2022; 
            stations2022.insert(it2022, "Takanawa Gateway");
            break;
        }
    }

    // 2019年の駅を表示
    displayList(stations2019, "2019");

	// 2022年の駅を表示
    displayList(stations2022, "2022");

    return 0;
}

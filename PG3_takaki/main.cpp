#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

int main() {
	// 初期の駅リストを定義
	list<const char*> rosen = { "田端", "日暮里", "西日暮里" };

	// 最初のリストを表示
	cout << "最初のリスト:" << endl;
	for (list<const char*>::iterator itr = rosen.begin(); itr != rosen.end(); itr++) {
		cout << *itr << endl;
	}

	// 駅を追加
	rosen.push_back("鶯谷");
	rosen.push_back("上野");

	// 追加後のリストを表示
	cout << "\n追加後のリスト1:" << endl;
	for (list<const char*>::iterator itr = rosen.begin(); itr != rosen.end(); itr++) {
		cout << *itr << endl;
	}

	// 駅をさらに追加
	rosen.push_back("御徒町");
	rosen.push_back("秋葉原");

	// さらに追加後のリストを表示
	cout << "\n追加後のリスト2:" << endl;
	for (list<const char*>::iterator itr = rosen.begin(); itr != rosen.end(); itr++) {
		cout << *itr << endl;
	}

	return 0;
}

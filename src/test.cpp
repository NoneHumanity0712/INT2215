#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
int main () {
	int i = 0;
	while (i<100) {
 		for (int i = 0; i < 30; i++) cout << endl;      // xóa màn hình
		cout << i++;							      // vẽ hình kế tiếp
 		this_thread::sleep_for(chrono::milliseconds(500));    // đợi
	}
}

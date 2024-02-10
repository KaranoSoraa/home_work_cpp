#include <iostream>
#include <thread>
#include <random>

using namespace std;

auto gener() {
	int mat[2][2];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			mat[i][j] = rand() % 10;
		}
	}
	return mat;
}

int main() {
	srand(time(0));
	int res1[2][2];
	int res2[2][2];

	thread t1([&res1]() { for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			res1[i][j] = mat[i][j];
		}
	}
		});
	/*thread t2(gener, ref(res2));*/
	
}
//#include <iostream>
//
//int main()
//{
//    double games, win, cur_rate;  int count = 0, rate;
//    std::cin >> games >> win;
//
//
//    rate = (int)(win / games * 100);
//    while (true) {
//        games++; win++;
//        count++;
//        if (games == win || (games >= 100 && win == games -1)) {
//            std::cout << -1;
//            exit(EXIT_FAILURE);
//        }
//        else if (rate != (int)(win / games * 100))
//            break;
//    }
//    std::cout << count;
//}

#include <iostream>
#define MAX 1000000000
int main() {
	long long x, y; int z;
	std::cin >> x >> y;
	z = 100 * y / x;
	int mid, per, right = MAX, left = 0;
	if (z >= 99) { std::cout << -1; return 0; }
	int count = -1;
	while (left <= right) {
		mid = (right + left) / 2;
		per = 100 * (y + mid) / (x + mid);
		if (per > z)
			right = mid - 1;
		else {
			left = mid + 1;
			count = mid + 1;
		}
	}
	std::cout << count;

	
}
#include<bits/stdc++.h>
using namespace std;

class ParkingSystem {
	int big, medium, small;
public:
	ParkingSystem(int big, int medium, int small) {
		this->big = big;
		this->medium = medium;
		this->small = small;
	}

	bool addCar(int carType) {
		if (carType == 1) {
			if (!big) return false;
			big--;
		}
		else if (carType == 2) {
			if (!medium) return false;
			medium--;
		}
		else {
			if (!small) return false;
			small--;
		}
		return true;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	return 0;
}
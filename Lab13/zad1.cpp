#include <iostream>
#include <vector>

using namespace std;

struct Wektor {
	private:
		float x;
		float y;
	
	public: 
		Wektor(float x_, float y_) {
			x = x_;
			y = y_;
		}

		void toString() {
			cout << "(" << x << ", " << y << ")" << endl;
		};
		
		float getX() {
			return x;
		};
		
		float getY() {
			return y;
		};
};

class Lamana {
	private:
		vector<Wektor> wektors;
		
	public: 
		void addLast(Wektor wektor) {
			wektors.push_back(wektor);
		}
		
		int unsigned getSize() {
			return wektors.size();
		};
		
		bool compare(Wektor a, Wektor b) {
			return a.getX() == b.getX() and a.getY() == b.getY();
		};
		
		bool isClosed() {
			return compare(wektors[0], wektors[getSize() - 1]);
		};
		
		void removeWektor(Wektor wektor) {
			for (int unsigned i = 0; i < wektors.size(); i++) {
				
				if (compare(wektors[i], wektor)) {
					wektors.erase(wektors.begin()+ i, wektors.begin() + i +1);
				}
			}
		};
		
		//void rotate(int angle);
		
		void toString() {
			for (int unsigned i = 0; i < wektors.size(); i++) {
				wektors[i].toString();
			}
		};
};



int main() {
	
	cout << boolalpha;
	
	Lamana a;
	Wektor wektor1{1,2};
	Wektor wektor2{3,4};
	Wektor wektor4{3,4};
	Wektor wektor3{1,2};

	
	a.addLast(wektor1);
	a.addLast(wektor2);
	a.addLast(wektor3);
	a.addLast(wektor4);
	
	a.removeWektor(wektor2);
	
	cout << "Is Closed : " << a.isClosed() << endl;

	a.toString();
	
	return 0;
}

#include <iostream>

using namespace std;

class Data {
	private:
		int day, month, year;
	public:
		
		Data(int day_, int month_, int year_) {
			day = day_;
			month = month_;
			year = year_;
		}
		
		int getDay() {
			return day;
		};
		
		int getMonth() {
			return month; 
		};
		
		int getYear() {
			return year;
		};
		
		void setDay(int day_) {
			day = day_;
		};
		
		void setMonth(int month_) {
			month = month_;
		};
		
		void setYear(int year_) {
			year = year_;
		};
	
};

int main() {
	
	Data data{1,2,3};
	
	return 0;
}

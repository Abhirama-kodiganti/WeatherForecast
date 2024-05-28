#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

int main() {
	
	int res_num = 1;

	while(res_num){
		cout << "\n\t************************************************" << endl;
		cout << "\t\t\tWeather forecast" << endl;
		cout << "\t************************************************\n" << endl;
		cout << "\tEnter the city: ";
		string city;
		string res;
		getline(cin, city);
		api_request(city);
		cout << endl;
		cout << "\tDo you want to try again for another city (y/n): ";
		getline(cin, res);

		if (res == "y") {
			res_num = 1;
		}
		else {
			res_num = 0;
		}
		
	}
	
	return 0;
}
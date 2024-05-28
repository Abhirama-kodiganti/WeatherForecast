#include <iostream>
#include <string>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include "weather.h"

using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;

void api_request(string city) {

	string query_code = "n";

	http_client client(U("https://api.openweathermap.org/data/2.5"));
	uri_builder builder(U("/weather"));
	builder.append_query(U("q"), utility::conversions::to_string_t(city));
	builder.append_query(U("appid"), U("8566f9b41aa3e280d6ffd8d82d0bb1b3"));
	http_request request(methods::GET);
	request.set_request_uri(builder.to_string());

	client.request(request).then([](http_response response) {
		return response.extract_json();
		}
	).then([](web::json::value body) {

			cout << "\tTemperature --> " << body[U("main")][U("temp")].as_double() << " K" << endl;
			cout << "\tHumidity --> " << body[U("main")][U("humidity")].as_double() << " %" << endl;
			cout << "\tWeather --> " << utility::conversions::to_utf8string(body[U("weather")][0][U("main")].as_string()) << "(" << utility::conversions::to_utf8string(body[U("weather")][0][U("description")].as_string()) << ")" << endl;

		}
		).wait();

		cout << endl;
		cout << "\tDo you want more information (y,n): ";
		getline(cin, query_code);

		if (query_code == "y") {
			client.request(request).then([](http_response response) {
				return response.extract_json();
				}
			).then([](web::json::value body) {
					
					cout << "\n\tPressure --> " << body[U("main")][U("pressure")].as_double() << " hPa" << endl;
					cout << "\tWind --> " << "Blowing at " << body[U("wind")][U("speed")].as_double() << " mph " << "at " << body[U("wind")][U("deg")].as_double() << " deg" << endl;
					cout << "\tMax Temperature --> " << body[U("main")][U("temp_max")].as_double() << " K" << endl;
					cout << "\tMin Temperature --> " << body[U("main")][U("temp_min")].as_double() << " K" << endl;

				}
				).wait();
		}

}
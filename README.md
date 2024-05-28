## C++ Weather Application ##

This is a console weather application written in c++. It fetches weather information from the OpenWeatherApi using the REST Api Architecture 


### Requirements ###
* vcpkg
* C++ compiler

### Required modules ###
* cpprestsdk


### How to Run ###
    git clone https://github.com/AMS003010/weatherIO.git
    vcpkg install cpprestsdk
    g++ -std=c++11 -o weather_app main.cpp weather.cpp -lcpprest
    ./weather_app

### User Customization ###
See Weather.h<br/>
see Weather.cpp

### Example use ###
See main.cpp

// derek_LED.cpp
#include "derek_LED.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

#define LED_PATH "/sys/class/leds/beaglebone:green:usr"

derek_LED::derek_LED(int number) {
    this->number = number;
    path = string(LED_PATH) + to_string(number) + "/";
}

void derek_LED::turnOn() {
    ofstream fs(path + "brightness");
    fs << "1";
    fs.close();
}

void derek_LED::turnOff() {
    ofstream fs(path + "brightness");
    fs << "0";
    fs.close();
}

void derek_LED::blink(int num) {
    for (int i = 0; i < num; i++) {
        turnOn();
        sleep(1);
        turnOff();
        sleep(1);
    }
}

derek_LED::~derek_LED() {}

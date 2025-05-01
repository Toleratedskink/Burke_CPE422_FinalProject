#include <string>
using std::string;

class derek_LED {
  private:
    int number;
    string path;
  public:
    derek_LED(int number);
    void turnOn();
    void turnOff();
    void displayState();
    void blink(int num);
    ~derek_LED();
};

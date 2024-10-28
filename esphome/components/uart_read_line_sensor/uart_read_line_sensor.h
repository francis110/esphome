#include "esphome.h"

class UartReadLineSensor : public Component, public uart::UARTDevice, public Sensor {
 public:
  UartReadLineSensor(UARTComponent *parent) : uart::UARTDevice(parent) {}

  void setup() override {
    // This will be called by App.setup()
  }

  void loop() override {
    // This will be called by App.loop()
    while (available()) {
      char c = read();
      if (c == '\n') {
        publish_state(line_.c_str());
        line_ = "";
      } else {
        line_ += c;
      }
    }
  }

 protected:
  std::string line_;
};

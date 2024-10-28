#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automaton.h"
#include "esphome/components/uart/uart.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace uart_read_line_sensor {

class UartReadLineSensor : public Component, public uart::UARTDevice {
 public:
  void setup() override {
    // Initialize any required resources or settings here
  }

  void loop() override {
    // Read data from UART and process it here
    // For example, read a line and publish it to the text sensor
    if (this->available()) {
      String line = this->read_line();
      if (!line.isEmpty()) {
        this->publish_line(line);
      }
    }
  }

  void publish_line(const String &line) {
    // Publish the line to the text sensor
    this->text_sensor_->publish_state(line);
  }

  void set_text_sensor(text_sensor::TextSensor *text_sensor) {
    this->text_sensor_ = text_sensor;
  }

 protected:
  text_sensor::TextSensor *text_sensor_;
};

}  // namespace uart_read_line_sensor
}  // namespace esphome

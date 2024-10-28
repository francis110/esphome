#include "uart_text_sensor.h"

UartTextSensor::UartTextSensor(uint8_t rx_pin, uint8_t tx_pin, uint32_t baud_rate) {
  _uart = new HardwareSerial(1);  // Replace 1 with the appropriate serial port number
  _uart->begin(baud_rate, SERIAL_8N1, rx_pin, tx_pin);
}

UartTextSensor::~UartTextSensor() {
  delete _uart;
}

void UartTextSensor::setup() {
  // Initialize serial communication
  _uart->begin(baud_rate, SERIAL_8N1);
}

void UartTextSensor::loop() {
  if (_uart->available()) {
    _received_data += (char)_uart->read();
    if (_received_data.endsWith("\n")) {
      // Process received data (e.g., convert to float)
      float value =

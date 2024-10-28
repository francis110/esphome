#ifndef UART_TEXT_SENSOR_H
#define UART_TEXT_SENSOR_H

#include <string>
#include <functional>

class UartTextSensor {
public:
  UartTextSensor(uint8_t rx_pin, uint8_t tx_pin, uint32_t baud_rate);
  ~UartTextSensor();

  void setup();
  void loop();

  // Function to be called when data is received from serial
  void on_data_received(const std::string& data, std::function<void(float)> callback);

private:
  HardwareSerial* _uart;
  std::string _received_data;
  std::function<void(float)> _data_callback;
};

#endif // UART_TEXT_SENSOR_H

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, text_sensor
import esphome.const as const

# Declare the namespace for the component
uart_read_line_sensor_ns = cg.esphome_ns.namespace('uart_read_line_sensor')
UartReadLineSensor = uart_read_line_sensor_ns.class_(
    'UartReadLineSensor', cg.Component, uart.UARTDevice, text_sensor.TextSensor
)

# Configuration schema for the component
CONFIG_SCHEMA = uart.UART_DEVICE_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(UartReadLineSensor),
}).extend(text_sensor.TEXT_SENSOR_SCHEMA.schema)

# Function to generate code from the configuration
def to_code(config):
    # Declare the sensor as a variable
    var = cg.new_Pvariable(config[const.CONF_ID])
    
    # Register component and sensor within ESPHome
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)
    yield text_sensor.register_text_sensor(var, config)

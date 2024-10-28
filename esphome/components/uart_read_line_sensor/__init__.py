import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor, uart
import esphome.const as const

# Namespace declaration
uart_read_line_sensor_ns = cg.esphome_ns.namespace('uart_read_line_sensor')
UartReadLineSensor = uart_read_line_sensor_ns.class_('UartReadLineSensor', cg.Component, uart.UARTDevice, text_sensor.TextSensor)

# Register the component under text_sensor domain
CONFIG_SCHEMA = uart.UART_DEVICE_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(UartReadLineSensor),
}).extend(text_sensor.TEXT_SENSOR_SCHEMA.schema)

# Register the component
def to_code(config):
    var = cg.new_Pvariable(config[const.CONF_ID])
    yield cg.register_component(var, config)
    yield uart.register_uart_device(var, config)
    yield text_sensor.register_text_sensor(var, config)

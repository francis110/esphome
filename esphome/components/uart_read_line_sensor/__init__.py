# __init__.py for uart_read_line_sensor component

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor, uart
import esphome.const as const

DEPENDENCIES = ['uart']
uart_read_line_sensor_ns = cg.esphome_ns.namespace('uart_read_line_sensor')

CONFIG_SCHEMA = uart.UART_DEVICE_SCHEMA.extend({})

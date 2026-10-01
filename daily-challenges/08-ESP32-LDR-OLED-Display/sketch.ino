from machine import Pin, ADC
from machine import I2C
import ssd1306
from time import sleep

i2c = I2C(scl=Pin(22), sda=Pin(21))

oled_width = 128
oled_height = 64
ldr = ADC(Pin(34))
ldr.atten(ADC.ATTN_11DB)

oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

led = Pin(2, Pin.OUT)

oled.fill(0)  # limpa o Display
oled.text('Display', 0, 0)  # escreve texto X, Y
oled.text('OLED', 0, 20)
oled.text('Micro Python', 0, 35)
oled.text('Esp 32', 0, 50)
oled.show()  # Exibe as informações
sleep(3)

while True:
    val_ldr = ldr.read()
    oled.fill(0) 
    oled.text("Teste Display", 9, 0)
    oled.text("Sensor LDR: ", 17, 20)
    oled.text("" + str(val_ldr), 41, 30)
    oled.show()
    
    if val_ldr < 500:
        led.on()
    else:
        led.off()
    
    sleep(1)

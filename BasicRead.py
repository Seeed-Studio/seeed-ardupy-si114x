from arduino import grove_si114x
import time

SI1145 = grove_si114x()

while True:
    print('Visible %03d UV %.2f IR %03d' % (SI1145.Visible , SI1145.UV/100 , SI1145.IR),end=" ")
    print('\r', end='')
    time.sleep(0.5)

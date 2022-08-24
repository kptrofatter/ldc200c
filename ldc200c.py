#==============================================================================#
# Neurophos Inc.                                                               #
# K.P.Trofatter                                                                #
# August 2022                                                                  #
#==============================================================================#
# ldc200c.py - Thorlabs LDC200C series laser diode controller python interface
import serial

#==============================================================================#
# functions                                                                    #
#==============================================================================#
def open(port):
	"""Open a serial connection to the arduino controlling LDC200C series.
	
	intput:
	port -- string of device file (Linux) or COM resource (Windows)
	"""
	# defaults ok: baudrate 9600, 8-bit, no parity bit, 1 stop bit
	ser = serial.Serial(resource, timeout=1.0)
	return ser

def laser_switch_off(ser):
	"""Turn laser off.
	DANGER: device cannot be queried to verify laser state."
	
	input:
	ser -- serial object
	"""
	ser.write(b"0")
	print(ser.read())

def laser_switch_on(ser):
	"""Turn laser on.
	DANGER: device cannot be queried to verify laser state."
	
	input:
	ser -- serial object
	"""
	ser.write(b"1")
	print(ser.read())

#==============================================================================#
#                                                                              #
#                                                                              #
#                                                                              #
#==============================================================================#


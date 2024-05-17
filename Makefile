all: build ci

build: ./led_blink.ino
	arduino-cli compile --output-dir=build
ci: 
	wokwi-cli --timeout 10000 --scenario blink.test.yaml 

all: build ci

build: ./led_blink/*
	arduino-cli compile led_blink --output-dir=build
ci: ./led_blink/*
	wokwi-cli --timeout 10000 --scenario blink.test.yaml 

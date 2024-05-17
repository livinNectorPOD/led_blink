# LED BLINK 

A sample project to blink and LED using STM32-Nucleo C031C6.

This project uses three different programming APIs to control different pheripherals.
1. "Bare Metal" Code for GPIO.
2. STM32HAL for delay using system clock.
3. Arudino Core powered by STM32duino for Serial Communication.

## Instructions

1. Install [`arduino-cli`](https://arduino.github.io/arduino-cli/0.35/installation/).
2. Install [wokwi-cli](https://github.com/wokwi/wokwi-cli) for testing.
3. Install `make` utitlity for running commands from `Makefile`

**Note:** `setup.sh` has the installation script for both `arduino-cli` and `wokwi-cli`

## Building

Building is done by `arduino-cli` the board profiles are specified in the `sketch.yaml` file.

```bash
arduino-cli compile --output-dir=build
```

## Testing with Wokwi CI

The `blink.test.yaml` file defines a scenario for [wokwi-cli](https://github.com/wokwi/wokwi-cli).

```bash
wokwi-cli --timeout 10000 --scenario blink.test.yaml 
```
**Note:** For this command to work you have to generate a Wokwi CI token from https://wokwi.com/dashboard/ci. 

Refer this for generating and using a Wokwi CI token https://docs.wokwi.com/wokwi-ci/getting-started#cli-usage

The CI Token can be set as an environment variable in `.env` file. Change `.env.example` file to `.env` and use the command `source .env && make` to build and test the program.


## Simulation with Wokwi for VSCode

To setup wokwi simulation for VSCode:
1. Install the official Wokwi VSCode extension.
2. Generate a Licsence: https://docs.wokwi.com/vscode/getting-started#installation.
3. Start simulation using VSCode Command Pallete
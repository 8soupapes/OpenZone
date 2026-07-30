# Architecture OpenZone

OpenZone est un contrôleur de zonage pour PAC gainable.

## Hardware

ESP32
│
├── I2C
│   ├── PCF8574 OUT 1
│   ├── PCF8574 OUT 2
│   ├── PCF8574 IN 1
│   └── PCF8574 IN 2
│
├── Ethernet
├── RS485
├── OneWire
└── RF433

## Software

Core
│
├── Outputs
├── Inputs
├── Registers
├── Temperature
├── Zones
├── HVAC
├── Network
├── Diagnostics
└── WebServer
# Architecture OpenZone

OpenZone est un contrôleur de zonage pour PAC gainable.

#OpenZone

Application
│
├── HVAC
│   ├── ZoneManager
│   ├── Zone
│   ├── Register
│   └── Scheduler
│
├── Hardware
│   ├── Inputs
│   └── Outputs
│
├── Drivers
│   ├── I2C
│   ├── PCF8574
│   ├── OneWire
│   ├── Ethernet
│   └── RS485
│
└── Core
    ├── Logger
    ├── Version
    ├── Config
    └── Board
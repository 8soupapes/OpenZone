# Changelog

## v0.1.0

### Infrastructure
- Création de l'architecture OpenZone
- Logger
- Version
- Board
- Config
- PinMap

### Drivers
- Driver I2C
- Scan automatique du bus I2C
- Driver PCF8574

### Hardware
- Gestion des 16 sorties
- Gestion des 16 entrées
- Détection des fronts montants et descendants
- Lecture globale des entrées (state())

### Validation matérielle
- Validation sur carte KC868-A16 V1.6.3
- Détection des PCF8574 :
  - 0x21
  - 0x22
  - 0x24
  - 0x25
- Validation des 16 sorties MOSFET
- Validation des 16 entrées optocouplées

### Divers
- Structure du projet documentée
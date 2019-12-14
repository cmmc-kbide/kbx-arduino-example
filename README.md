# KBX_UI Library

## Pinout
Peripheral Devices | KidBright32 & KBX-UI Extension

#### TFT Display 2.4 Inches. LCD
| Desc.  | Port | Remark |
|-------|:---:|----------|
| ILI9341 DC   | GPIO18 | - |
| ILI9341 CS   | GPIO19 | - |
| ILI9341 MOSI | GPIO21 | shared with I2C0_SDA |
| ILI9341 SCLK | GPIO22 | shared with I2C0_SCL |

#### Touchscreen Panel
| Desc.  | Port | Remark |
|-------|:---:|----------|
| XPT2046 CS   | GPIO27 | OUT2 |
| XPT2046 MOSI | GPIO21 | shared with I2C0_SDA |
| XPT2046 MISO | GPIO32 | IN1 |
| XPT2046 SCLK | GPIO22 | shared with I2C0_SCL |

#### SD-CARD
| Desc.  | Port | Remark |
|-------|:---:|----------|
| TFCARD CS   | GPIO23 | - |
| TFCARD MOSI | GPIO21 | shared with I2C0_SDA |
| TFCARD MISO | GPIO32 | IN1 |
| TFCARD SCLK | GPIO22 | shared with I2C0_SCL |

#### KeyPADs
| Desc.  | Port | Remark |
|-------|:---:|----------|
| BUTTON A | GPIO33 | IN2 |
| BUTTON B | GPIO34 | IN3 |
| BUTTON C | GPIO35 | IN4 |

#### Speaker
| Desc.  | Port | Remark |
|-------|:---:|----------|
| SPEAKER | GPIO26 | - |

### KBX-IO Extension
| Desc.  | Port | Remark |
|-------|:---:|----------|
| GROVE SDA | GPIO4 | - |
| GROVE SCL | GPIO5 | - |

### KidBright32 GPIO
#### ADDR[0x70] HT16K33 : RAM Mapping 16*8 LED Controller Driver with keyscan
| Desc.  | Port | Remark |
|-------|:---:|----------|
| I2C0_SCL | GPIO22 | - |
| I2C0_SDA | GPIO21 | - |

#### ADDR[0x6F] MPC7940N : Battery-Backed I2C™ Real-Time Clock/Calendar with SRAM
| Desc.  | Port | Remark |
|-------|:---:|----------|
| I2C1_SCL | GPIO5 | - |
| I2C1_SDA | GPIO4 | - |

#### ADDR[0x4D] LM73 : 14 Bit Digital Temperature Sensor Default 11 Bit 
| Desc.  | Port | Remark |
|-------|:---:|----------|
| I2C1_SCL | GPIO5 | - |
| I2C1_SDA | GPIO4 | - |

#### LED Status Active LOW
| Desc.  | Port | Remark |
|-------|:---:|----------|
| LED_BT   | GPIO17 | - |
| LED_WIFI | GPIO2 | - |
| LED_NTP  | GPIO15 | - |
| LED_IOT  | GPIO12 | - |

#### Switch Input
| Desc.  | Port | Remark |
|-------|:---:|----------|
| SW1_PIN | GPIO16 | Internal Pullup |
| SW2_PIN | GPIO14 | Internal Pullup |

#### BUZZER
| Desc.  | Port | Remark |
|-------|:---:|----------|
| PWM_PIN | GPIO13 | Buzzer |

#### Light Sensor LDR
| Desc.  | Port | Remark |
|-------|:---:|----------|
|LDR_PIN | GPIO36 | Light Sensor |

#### USB Type A ON/OFF Active HIGH
| Desc.  | Port | Remark |
|-------|:---:|----------|
| USBA_SW | GPIO25 | - |

Not Connect GPIO39

#define MCP2515_RXF0SIDH   0x00
#define MCP2515_RXF0SIDL   0x01
#define MCP2515_RXF0EID8   0x02
#define MCP2515_RXF0EID0   0x03
#define MCP2515_RXF1SIDH   0x04
#define MCP2515_RXF1SIDL   0x05
#define MCP2515_RXF1EID8   0x06
#define MCP2515_RXF1EID0   0x07
#define MCP2515_RXF2SIDH   0x08
#define MCP2515_RXF2SIDL   0x09
#define MCP2515_RXF2EID8   0x0A
#define MCP2515_RXF2EID0   0x0B
#define MCP2515_CANSTAT    0x0E
#define MCP2515_CANCTRL    0x0F
#define MCP2515_RXF3SIDH   0x10
#define MCP2515_RXF3SIDL   0x11
#define MCP2515_RXF3EID8   0x12
#define MCP2515_RXF3EID0   0x13
#define MCP2515_RXF4SIDH   0x14
#define MCP2515_RXF4SIDL   0x15
#define MCP2515_RXF4EID8   0x16
#define MCP2515_RXF4EID0   0x17
#define MCP2515_RXF5SIDH   0x18
#define MCP2515_RXF5SIDL   0x19
#define MCP2515_RXF5EID8   0x1A
#define MCP2515_RXF5EID0   0x1B
#define MCP2515_TEC        0x1C
#define MCP2515_REC        0x1D
#define MCP2515_RXM0SIDH   0x20
#define MCP2515_RXM0SIDL   0x21
#define MCP2515_RXM0EID8   0x22
#define MCP2515_RXM0EID0   0x23
#define MCP2515_RXM1SIDH   0x24
#define MCP2515_RXM1SIDL   0x25
#define MCP2515_RXM1EID8   0x26
#define MCP2515_RXM1EID0   0x27
#define MCP2515_CNF3       0x28
#define MCP2515_CNF2       0x29
#define MCP2515_CNF1       0x2A
#define MCP2515_CANINTE    0x2B
#define MCP2515_CANINTF    0x2C
#define MCP2515_EFLG       0x2D
#define MCP2515_TXB1CTRL   0x40
#define MCP2515_TXB2CTRL   0x50
#define MCP2515_RXB0CTRL   0x60
#define MCP2515_RXB0SIDH   0x61
#define MCP2515_RXB1CTRL   0x70
#define MCP2515_RXB1SIDH   0x71

#define MCP2515_TX_INT     0x1C
#define MCP2515_TX01_INT   0x0C
#define MCP2515_RX_INT     0x03
#define MCP2515_NO_INT     0x00

#define MCP2515_TX01_MASK  0x14
#define MCP2515_TX_MASK    0x54

#define MCP2515_WRITE      0x02
#define MCP2515_READ       0x03

#define MCP2515_BITMOD     0x05

#define MCP2515_LOAD_TX0   0x40
#define MCP2515_LOAD_TX1   0x42
#define MCP2515_LOAD_TX2   0x44

#define MCP2515_RTS_TX0    0x81
#define MCP2515_RTS_TX1    0x82
#define MCP2515_RTS_TX2    0x84
#define MCP2515_RTS_ALL    0x87

#define MCP2515_READ_RX0   0x90
#define MCP2515_READ_RX1   0x94

#define MCP2515_READ_STATUS 0xA0
#define MCP2515_RX_STATUS   0xB0
#define MCP2515_RESET       0xC0

#define MODE_NORMAL     0x00
#define MODE_SLEEP      0x20
#define MODE_LOOPBACK   0x40
#define MODE_LISTENONLY 0x60
#define MODE_CONFIG     0x80
#define MODE_POWERUP    0xE0
#define MODE_MASK       0xE0
#define ABORT_TX        0x10
#define MODE_ONESHOT    0x08
#define CLKOUT_ENABLE   0x04
#define CLKOUT_DISABLE  0x00
#define CLKOUT_PS1      0x00
#define CLKOUT_PS2      0x01
#define CLKOUT_PS4      0x02
#define CLKOUT_PS8      0x03

#define SJW1            0x00
#define SJW2            0x40
#define SJW3            0x80
#define SJW4            0xC0

#define BTLMODE         0x80
#define SAMPLE_1X       0x00
#define SAMPLE_3X       0x40

#define SOF_ENABLE      0x80
#define SOF_DISABLE     0x00
#define WAKFIL_ENABLE   0x40
#define WAKFIL_DISABLE  0x00

#define MCP2515_RX0IF      0x01
#define MCP2515_RX1IF      0x02
#define MCP2515_TX0IF      0x04
#define MCP2515_TX1IF      0x08
#define MCP2515_TX2IF      0x10
#define MCP2515_ERRIF      0x20
#define MCP2515_WAKIF      0x40
#define MCP2515_MERRF      0x80

/* Registres permettant de contrôler le module d'envoi « TX0 » */
#define MCP2515_TXB0CTRL   0x30
#define MCP2515_TXB0SIDH   0x31
#define MCP2515_TXB0SIDL   0x32
#define MCP2515_TXB0EID8   0x33
#define MCP2515_TXB0EID0   0x34
#define MCP2515_TXB0DLC    0x35
#define MCP2515_TXB0D0     0x36
#define MCP2515_TXB0D1     0x37
#define MCP2515_TXB0D2     0x38
#define MCP2515_TXB0D3     0x39
#define MCP2515_TXB0D4     0x3A
#define MCP2515_TXB0D5     0x3B
#define MCP2515_TXB0D6     0x3C
#define MCP2515_TXB0D7     0x3D
#define MCP2515_TXB0CANSTAT   0x3E
#define MCP2515_TXB0CANCTRL   0x3F

/* Registres permettant de contrôler le module de réception « RX0 » */
#define MCP2515_RXB0CTRL   0x60
#define MCP2515_RXB0SIDH   0x61
#define MCP2515_RXB0SIDL   0x62
#define MCP2515_RXB0EID8   0x63
#define MCP2515_RXB0EID0   0x64
#define MCP2515_RXB0DLC    0x65 // IMPORTANT LONGUEUR du nombre d'octet
#define MCP2515_RXB0D0     0x66
#define MCP2515_RXB0D1     0x67
#define MCP2515_RXB0D2     0x68
#define MCP2515_RXB0D3     0x69
#define MCP2515_RXB0D4     0x6A
#define MCP2515_RXB0D5     0x6B
#define MCP2515_RXB0D6     0x6C
#define MCP2515_RXB0D7     0x6D
#define MCP2515_RXB0CANSTAT   0x6E
#define MCP2515_RXB0CANCTRL   0x6F
#define MCP2515_BFPCTRL       0x0C
#define MCP2515_TXRTSCTRL     0x0D

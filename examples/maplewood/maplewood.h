#include <ModbusRtu.h>
#include <modbus_container.h>
#include "ttn.h"
#include "wattnode_settings.h"

typedef enum STATES
{
  STATE_CFG = 0,
  STATE_INIT,
  STATE_POLL,
  STATE_IDLE,

} STATES;

uint8_t PACKET_BUFF_SIZE = 5; //Number of samples to collect before sending over LoRa.
uint16_t SAMPLE_PERIOD = 1000; //Time in millis seconds between samples from WattNode [1:255]

// Wattnode Devices
WATTNODE_DEV device1(1,200,200,200,2,0,0,0);
WATTNODE_DEV device2(2,100,100,100,2,0,0,0);

WATTNODE_DEV devices[] = {device1,device2};
uint8_t num_devs = 2;



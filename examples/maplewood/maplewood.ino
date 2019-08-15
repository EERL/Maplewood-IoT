
#include "maplewood.h"

ModbusSerial<decltype(Serial1)> mySerial(&Serial1);
Modbus host(0, A4); 
Wattnode_Queue Queue(2);

// variables for app
STATES curr_state;
uint8_t curr_dev;
uint16_t au16data[16];
modbus_t telegram;

#define kPowerOn        A3

static inline void powerOn(void)
{
        pinMode(kPowerOn, OUTPUT);
        digitalWrite(kPowerOn, HIGH);
}

void setup(){
  powerOn();
  host.begin(&mySerial, 19200 ); // baud-rate at 19200
  
  host.setTimeOut( 1000 ); // if there is no answer in 1000 ms, roll over
  host.setTxEnableDelay(100);
  curr_state = STATE_CFG;
  for (int i = 0; i < num_devs; i++)
    Queue.enqueue(devices[i]);
  
}

void loop(){
  switch(curr_state) {
    case STATE_CFG:
      WATTNODE_DEV dev = Queue.cycle();
      uint16_t writeData[] = {dev.CT_A, dev.CT_B, dev.CT_C};
      telegram.u8id = dev.id; // device address
      telegram.u8fct = MB_FC_WRITE_MULTIPLE_REGISTERS; // function code (this one is registers read)
      telegram.u16RegAdd = 1603; // start address in device
      telegram.u16CoilsNo = 3; // number of elements (coils or registers) to read
      telegram.au16reg = ; // pointer to a memory array in the Arduino
      if (curr_dev < num_devs){
        curr_dev ++
      }
      else {
        curr_state = STATE_
      }
      break;

    case STATE_INIT:
      break;

    case STATE_POLL:
      break;

    case STATE_IDLE:
      break;

    default:
      Serial.println("Undefined State");
  }
}
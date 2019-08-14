#include <Arduino_LoRaWAN_ttn.h>
// #include <hal/hal.h>
#include <lmic.h>
#include <SPI.h>

class cMyLoRaWAN : public Arduino_LoRaWAN_ttn {
public:
  cMyLoRaWAN() {};

protected:
  // you'll need to provide implementations for each of the following.
  virtual bool GetOtaaProvisioningInfo(Arduino_LoRaWAN::OtaaProvisioningInfo* otaa_info) override;
  // virtual void NetSaveFCntUp(uint32_t uFCntUp) override;
  // virtual void NetSaveFCntDown(uint32_t uFCntDown) override;
  virtual void NetSaveSessionInfo(const SessionInfo &Info, const uint8_t *pExtraInfo, size_t nExtraInfo) override;
};

// This should also be in little endian format.
static const u1_t PROGMEM APPEUI[8]=
 { 0x11, 0x15, 0x01, 0xD0, 0x7E, 0xD5, 0xB3, 0x70 };// Sends to 99999999
// void os_getArtEui (u1_t* buf) { memcpy_P(buf, APPEUI, 8);}

// This should also be in little endian format.
static const u1_t PROGMEM DEVEUI[8]=
{ 0x43, 0xE0, 0xBF, 0xE5, 0x02, 0x54, 0x54, 0x01 };//Send to 99999999
// void os_getDevEui (u1_t* buf) { memcpy_P(buf, DEVEUI, 8);}
  
// This key should be in big endian format
static const u1_t PROGMEM APPKEY[16] = 
{ 0x7E, 0x07, 0x88, 0xAE, 0x2E, 0x2E, 0xED, 0xAA, 0x11, 0xAB, 0x6F, 0x61, 0x16, 0x2D, 0x51, 0x98 };//Send to 99999999
// void os_getDevKey (u1_t* buf) {  memcpy_P(buf, APPKEY, 16);}


const cMyLoRaWAN::lmic_pinmap myPinMap = {
     .nss = 8,
     .rxtx = cMyLoRaWAN::lmic_pinmap::LMIC_UNUSED_PIN,
     .rst = 4,
     .dio = { 3, 6, cMyLoRaWAN::lmic_pinmap::LMIC_UNUSED_PIN },
     .rxtx_rx_active = 0,
     .rssi_cal = 0,
     .spi_freq = 8000000,
};
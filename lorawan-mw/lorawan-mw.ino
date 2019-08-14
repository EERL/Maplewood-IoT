#include "lorawan-mw.h"

bool cMyLoRaWAN::GetOtaaProvisioningInfo(Arduino_LoRaWAN::OtaaProvisioningInfo *otaa_info){
  Serial.println("GetOtaaProvisioningInfo");
  if (APPEUI != NULL ) memcpy_P(otaa_info->AppEUI, APPEUI, 8);
  if (DEVEUI != NULL ) memcpy_P(otaa_info->DevEUI, DEVEUI, 8);
  if (APPKEY != NULL ) memcpy_P(otaa_info->AppKey, APPKEY, 16);
  return (APPEUI != NULL && DEVEUI != NULL && APPKEY != NULL);
}
void cMyLoRaWAN::NetSaveSessionInfo(const SessionInfo &Info, const uint8_t *pExtraInfo,
    size_t nExtraInfo
    ) {
    Serial.println(Info.V2.NetID);
    // save Info somewhere.
}

// set up the data structures.
cMyLoRaWAN myLoRaWAN {};
ARDUINO_LORAWAN_EVENT_FN *pEvent;
int *context;

uint8_t buff[] = {1,2,3,4};

void setup() {
  myLoRaWAN.begin();
  myLoRaWAN.SetLinkCheckMode(true);
  if (!myLoRaWAN.RegisterListener(pEvent,context)) {
    Serial.println("Register Listener Failed");
    return;
  }
}

void loop() {
  myLoRaWAN.SendBuffer(buff,4);
  myLoRaWAN.loop();
  // Serial.println(myLoRaWAN.GetEventName(pEvent));
}

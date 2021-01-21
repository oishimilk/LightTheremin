#include <Wire.h>
#include "pitch_bend.hpp"


void PitchBend::setup(void)
{
  Wire.begin();
  byte rc = MyKX126.init();

  if (rc != 0) {
    Serial.println("KX126 initialization failed");
  }
}

void PitchBend::loop(void)
{
  byte rc = MyKX126.get_val(acc);
}

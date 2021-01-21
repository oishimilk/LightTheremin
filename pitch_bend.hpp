#ifndef _pitch_bend.hpp_
#define _pitch_bend.hpp_

#include <Arduino.h>
#include "KX126.hpp"

class PitchBend {
  public:
    void setup(void);
    void loop(void);
    float acc[3];

  private:
    KX126 MyKX126 = KX126(KX126_DEVICE_ADDRESS_1F);
};

#endif

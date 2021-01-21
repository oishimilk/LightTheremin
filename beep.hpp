#ifndef __beep_hpp__
#define __beep_hpp__

#include <Audio.h>

class Beep {
  public:
    void setup(void);
    void beep(short);
    void panic(void);
    short determine_freq(uint8_t, bool sharp = false);

  private:
    AudioClass *theAudio;
};

#endif

#ifndef _camera_hpp_
#define _camera_hpp_

#include <Camera.h>
#include <SDHCI.h>

class Camera {
  public:
    void setup(void);
    static float color[3];

  private:
    SDClass theSD;
    int take_picture_count = 0;
    void printError(enum CamErr);
    static void CamCB(CamImage);
    void loop(void);
};

#endif

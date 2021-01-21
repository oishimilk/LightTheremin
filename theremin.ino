#include "camera.hpp"
#include "pitch_bend.hpp"
#include "beep.hpp"

#define BAUD_RATE 115200

// static な彼
float Camera::color[3];

// グローバル変数
// 接頭辞 glb_
Camera glb_camera;
PitchBend glb_pitch_bend;
Beep glb_beep;


void setup() {
  // put your setup code here, to run once:
  // Serial Setup
  Serial.begin(BAUD_RATE);
  while (!Serial); // wait until serial is ready
  Serial.println("Reached serial setup.");

  // Camera Setup
  glb_camera = Camera::Camera();
  glb_camera.setup();
  Serial.println("Reached camera setup.");

  // Pitch Bend Setup
  glb_pitch_bend = PitchBend::PitchBend();
  glb_pitch_bend.setup();
  Serial.println("Reached pitch bend setup.");

  // Beep beep I'm a sheep
  glb_beep = Beep::Beep();
  glb_beep.setup();
  Serial.println("Reached beep setup.");

  Serial.println("Light Theremin is ready. Press SPACE to start.");
}


void loop() {
  // put your main code here, to run repeatedly:
  static bool enable = false; // whether beep or not
  bool force_activation = false; // forced beep
  static uint8_t ttl = 0; // time to live - be quiet if ttl > 0
  static bool sharp = false;

  // configuration with keyboard input
  if (Serial.available()) {
    char key;
    int ret = Serial.readBytes(&key, 1);
    if (ret < 0) return;

    switch (key) {
      case ' ':
        force_activation = !enable;
        enable = !enable;
        break;
      case 's':
        Serial.println("=== Current Status ===");
        Serial.print("Average R: "); Serial.print(glb_camera.color[0]);
        Serial.print(", Average G: "); Serial.print(glb_camera.color[1]);
        Serial.print(", Average B: "); Serial.print(glb_camera.color[2]);
        Serial.println("");
        Serial.print("Accel X: "); Serial.print(glb_pitch_bend.acc[0]);
        Serial.print(", Accel Y: "); Serial.print(glb_pitch_bend.acc[1]);
        Serial.print(", Accel Z: "); Serial.print(glb_pitch_bend.acc[2]);
        Serial.println("");
        Serial.print("Enable: "); Serial.println(enable);
        Serial.print("TTL: "); Serial.println(ttl);
        Serial.print("Sharp: "); Serial.println(sharp);
        break;
      case 'v':
        sharp = !sharp;
        force_activation = true;
        break;
      case 'p':
        ttl = 2;
        break;
      default:
        break;
    }
  }

  // beep or be quiet with TTL
  if (ttl == 1) {
    enable = true;
    force_activation = true;
    ttl--;
  } else if (ttl > 0) {
    enable = false;
    ttl--;
  }

  // Get accel data
  glb_pitch_bend.loop();

  // Let's beep
  static uint8_t scale = 0;
  uint8_t new_scale = (uint8_t)(glb_camera.color[1] / 2);
  static float bend = 1;
  float new_bend = glb_pitch_bend.acc[0] + 1;
  short freq = 440;

  if (enable) {
    // beep
    if ((scale != new_scale) || (bend != new_bend) || force_activation) {
      force_activation = false;
      scale = new_scale;
      bend = new_bend;
      freq = glb_beep.determine_freq(scale, sharp);
      glb_beep.beep(freq * new_bend);
    }
  } else {
    // be quiet
    glb_beep.panic();
  }
}

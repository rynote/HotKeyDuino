#include <IRremote.h>


int receiver = 11; // Signal Pin of IR receiver to Arduino Digital Pin 11


/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);     // create instance of 'irrecv'
decode_results results;      // create instance of 'decode_results'

/*-----( Function )-----*/
void translateIR() // takes action based on IR code received
// describing Remote IR codes 
{
  switch(results.value)
  {
//  case 0xFFA25D: Serial.println("POWER"); break;
//  case 0xFFE21D: Serial.println("FUNC/STOP"); break;
  case 0xFF629D: VolumeUp();  break;// Serial.println("VOL+");
//  case 0xFF22DD: Serial.println("FAST BACK");    break;
//  case 0xFF02FD: Serial.println("PAUSE");    break;
//  case 0xFFC23D: Serial.println("FAST FORWARD");   break;
  case 0xFFE01F: IRDown(); break;//Serial.println("DOWN");    break;
  case 0xFFA857: VolumeDown();    break;// Serial.println("VOL-");
  case 0xFF906F: IRUp(); break;//Serial.println("UP");    break;
//  case 0xFF9867: Serial.println("EQ");    break;
//  case 0xFFB04F: Serial.println("ST/REPT");    break;
//  case 0xFF6897: Serial.println("0");    break;
  case 0xFF30CF: Action01();    break;
  case 0xFF18E7: Action02();    break;
  case 0xFF7A85: Action03();    break;
  case 0xFF10EF: Action04();    break;
  case 0xFF38C7: Action05();    break;
  case 0xFF5AA5: Action06();    break;
  case 0xFF42BD: Action07();    break;
  case 0xFF4AB5: Action08();    break;
  case 0xFF52AD: Action09();    break;
//  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    break;

  }// End Case

  delay(150); // Do not get immediate repeat


} //END translateIR

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

#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_UP 0x52 // Keyboard Up Arrow



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

  irrecv.enableIRIn(); // Start the receiver

  delay(200);
}

void loop() 
{
  if (irrecv.decode(&results)) { // have we received an IR signal?
    translateIR(); 
    irrecv.resume(); // receive the next value
  }


  state = digitalRead(PIN_BUTTON_01);
  if (state != 1) {
    Action01();
  } 
  
  state = digitalRead(PIN_BUTTON_02);
  if (state != 1) {
    Action02();
  } 


  state = digitalRead(PIN_BUTTON_03);
  if (state != 1) {
    Action03();
  }

  
  state = digitalRead(PIN_BUTTON_04);
  if (state != 1) {
    Action04();
  } 
}

void Action01()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x1e;    // 1
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void Action02()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x1f;    // 2
    Serial.write(buf, 8);  // Ssend keypress
    releaseKey();
}

void Action03(){
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x20;    // 3
    Serial.write(buf, 8);  // Send keypress
    releaseKey();
}

void Action04()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x21;    // 4
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void Action05()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x22;    // 5
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void Action06()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x23;    // 6
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void Action07()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x24;    // 7
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void Action08()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x25;    // 8
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void Action09()
{
    buf[0] = KEY_LEFT_CTRL_SHIFT_ALT;   // ctrl + shift + alt/option
    buf[2] = 0x26;    // 9
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void VolumeUp()
{
    buf[2] = 128;    // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void VolumeDown()
{
    buf[2] = 129;    // Volume down key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void IRUp()
{
    buf[2] = KEY_UP;    // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void IRDown()
{
    buf[2] = KEY_DOWN;    // Volume down key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key  
  delay(250);
}

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int fingerprintID = 0;
#include <Keyboard.h>
void setup(){
  //Fingerprint sensor module setup
  Serial.begin(9600);
  // set the data rate for the sensor serial port
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } 
  else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Keyboard.begin();
 
}

void loop(){
  fingerprintID = getFingerprintIDez();
  delay(50);
  if(fingerprintID == 1 ){
    Keyboard.print(' ');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.print("go 2 hell");
    Keyboard.releaseAll();
    delay(300);            
  }  
  else if(fingerprintID == 2){
    Keyboard.print(' ');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.print("1399");
    Keyboard.releaseAll();
    delay(300);            
  }
   else if(fingerprintID == 3){
    Keyboard.print(' ');
    Keyboard.releaseAll();
    delay(200);
    Keyboard.print("jose1234");
    Keyboard.releaseAll();
    delay(300);            
  }
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);
  return finger.fingerID;
}

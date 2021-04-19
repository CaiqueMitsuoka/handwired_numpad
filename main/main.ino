#include <Key.h>
#include <Keypad.h>
#include <Keyboard.h>

const byte rows = 6; //four rows
const byte cols = 4; //three columns
// char keys[rows][cols] = {
//   {'q', 'w', 'e', 'r'},
//   {'a', 's', 'd', 'f'},
//   {'7', '8', '9',  0 },
//   {'4', '5', '6', '+'},
//   {'1', '2', '3', 'E'},
//   {'0',  0 , ',',  0 }
// };

char keys[cols][rows] = {
  {'r' , 'f' ,  0  , '+' , 'E' ,  0 },
  {'e' , 'd' , '9' , '6' , '3' , ','},
  {'w' , 's' , '8' , '5' , '2' ,  0 },
  {'q' , 'a' , '7' , '4' , '1' , '0'},

};
byte rowPins[rows] = {PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_C6, PIN_C7}; //connect to the row pinouts of the keypad
byte colPins[cols] = {PIN_D5, PIN_D4, PIN_D6, PIN_D7}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), colPins, rowPins, cols, rows );

void setup() {
 Serial.begin(9600);
 Serial.println("Setup!");
}
void loop() {
  char key = keypad.getKey();
  Serial.println("Pressed");

  if (key != NO_KEY){
    Keyboard.println("Key pressed: " + String(key));
  }
}

#include <Key.h>
#include <Keypad.h>
#include <Keyboard.h>

const byte rows = 4; //four rows
const byte cols = 6; //three columns

char keys[rows][cols] = {
  {-1, 1 , 2 , 3 , 4 , 5 },
  {6 , 7 , 8 , 9 , 10, 11},
  {12, 13, 14, 15, 16, 17},
  {18, 19, 20, 21, 22, 23},
};


unsigned int keys_send_code[rows][cols] = {
  { KEY_MEDIA_VOLUME_INC , KEYPAD_MINUS   ,  0       , KEYPAD_PLUS , KEYPAD_ENTER ,  0            },
  { KEY_MEDIA_VOLUME_DEC , KEYPAD_ASTERIX , KEYPAD_9 , KEYPAD_6    , KEYPAD_3     , KEYPAD_PERIOD },
  { KEY_MEDIA_MUTE       , KEYPAD_SLASH   , KEYPAD_8 , KEYPAD_5    , KEYPAD_2     ,  0            },
  { KEY_MEDIA_PLAY_PAUSE , KEY_ESC        , KEYPAD_7 , KEYPAD_4    , KEYPAD_1     , KEYPAD_0      },
};


byte rowPins[rows] = {PIN_D5, PIN_D4, PIN_D6, PIN_D7};
byte colPins[cols] = {PIN_D0, PIN_D1, PIN_D2, PIN_D3, PIN_C6, PIN_C7};


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

void setup() {
 Serial.begin(9600);
 Serial.println("Setup!");
}

void loop() {
  int key = keypad.waitForKey();
  Serial.println("Pressed");

  if (key != NO_KEY) {
    key_action(key);


  }
}


void key_action(int key) {
  int col = 0;
  int row = 0;

  if(key != -1) {
    col = key % 6;
    row = key / 6;
  }

  Serial.println("key " + String(key));
  Serial.println("col " + String(col));
  Serial.println("row /" + String(row));
  // Keyboard.print(String(key));
  Keyboard.press(keys_send_code[row][col]);
  Keyboard.release(keys_send_code[row][col]);
}

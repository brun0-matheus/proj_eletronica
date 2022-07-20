const byte LED_PINS[4] = {15, 2, 5, 22};
const byte BUTTON_PINS[4] = {32, 33, 25, 26};

#define BTN_PRESSED LOW
#define LED_BLINK_TIME 500
#define DELAY_SEQUENCE 100
#define DELAY_ERROR 1000
#define DELAY_AFTER_USER_TURN 500

bool user_turn = false;
byte sequence[128];
byte size_sequence = 0, cur_user_pos = 0;

void set_all_leds_to(byte value) {
  for(int i = 0; i < 4; i++) digitalWrite(LED_PINS[i], value);
}

void setup() {
  for(byte i = 0; i < 4; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
  }

  set_all_leds_to(LOW);
  randomSeed(analogRead(0));

  delay(500);
  // Serial.begin(9600);
  // Serial.write("COMECOU\n");
}

byte get_pressed_btn() {
  for(byte i = 0; i < 4; i++) {
    if(digitalRead(BUTTON_PINS[i]) == BTN_PRESSED) 
      return i;
  }

  return 255;
}

void blink_led(byte index) {
  digitalWrite(LED_PINS[index], HIGH);
  delay(LED_BLINK_TIME);
  digitalWrite(LED_PINS[index], LOW);
}

void handle_user_action(byte pressed_btn) {
  if(sequence[cur_user_pos] == pressed_btn) {
    cur_user_pos++;
    blink_led(pressed_btn);

    if(cur_user_pos == size_sequence) {
      cur_user_pos = 0;
      user_turn = false;

      delay(DELAY_AFTER_USER_TURN);
    }
  } else {
    cur_user_pos = size_sequence = 0;

    set_all_leds_to(HIGH);
    delay(DELAY_ERROR);
    set_all_leds_to(LOW);

    user_turn = false;
    delay(DELAY_AFTER_USER_TURN);
  }
}

void loop() {
  if(user_turn) {
    byte pressed_btn = get_pressed_btn();
    if(pressed_btn != 255) {
      handle_user_action(pressed_btn);
    }
  } else {
    byte v = random(4);
    sequence[size_sequence++] = v;

    for(int i = 0; i < size_sequence; i++) {
      blink_led(sequence[i]);
      delay(DELAY_SEQUENCE);
    }

    user_turn = true;
  }

  delay(10); // this speeds up the simulation
}

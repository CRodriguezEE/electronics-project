// ECE 3155 — Full H-Bridge Square-Wave Switching Test
// Arduino Uno + IR2110 gate-driver validation
// Approx. 16.97 kHz full-cycle switching, 12 V DC bus
// Leg A: HIN_A = D5, LIN_A = D6
// Leg B: HIN_B = D9, LIN_B = D10
// SD pins tied to GND on both IR2110s
//
// Purpose:
// - Verify complementary H-bridge switching
// - Validate IR2110 input signal routing
// - Add software dead time between switching states
// - Support oscilloscope switching-frequency validation
//
// Note:
// Prototype switching-validation firmware (not finalized SPWM control).

#define HIN_A 5
#define LIN_A 6
#define HIN_B 9
#define LIN_B 10

volatile bool state = false;

void allOff() {
  PORTD &= ~((1 << PD5) | (1 << PD6));
  PORTB &= ~((1 << PB1) | (1 << PB2));
}

void bootstrapCharge() {
  digitalWrite(LIN_A, HIGH);
  digitalWrite(LIN_B, HIGH);
  delay(50);
  digitalWrite(LIN_A, LOW);
  digitalWrite(LIN_B, LOW);
  delay(5);
}

ISR(TIMER1_COMPA_vect) {
  PORTD &= ~((1 << PD5) | (1 << PD6));
  PORTB &= ~((1 << PB1) | (1 << PB2));

  __builtin_avr_delay_cycles(5);  // ~312.5 ns dead time

  if (!state) {
    PORTD |= (1 << PD5);   // HIN_A HIGH (pin 5)
    PORTB |= (1 << PB2);   // LIN_B HIGH (pin 10)
  } else {
    PORTD |= (1 << PD6);   // LIN_A HIGH (pin 6)
    PORTB |= (1 << PB1);   // HIN_B HIGH (pin 9)
  }

  state = !state;
}

void setupTimer1_17kHz() {
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  // OCR1A = 16,000,000 / 17000 / 2 - 1 = 470
  OCR1A = 470;
  TCCR1B |= (1 << WGM12);  // CTC mode
  TCCR1B |= (1 << CS10);   // No prescaler
  TIMSK1 |= (1 << OCIE1A);
  sei();
}

void setup() {
  pinMode(HIN_A, OUTPUT);
  pinMode(LIN_A, OUTPUT);
  pinMode(HIN_B, OUTPUT);
  pinMode(LIN_B, OUTPUT);

  allOff();
  delay(100);

  bootstrapCharge();
  delay(10);

  setupTimer1_17kHz();
}

void loop() {
  // All switching handled in ISR
}

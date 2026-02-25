const uint8_t PinSignalDrain = 0; // INPUT-Drain pump signal on pin 1.
const uint8_t PinValve = 1; // OUTPUT-Water inlet valve on pin 1.
bool CycleEnCour = 0; // Variable to know if a cycle has started.
bool EnRemplissage = 0; // Variable to know if the dishwasher is filling with water.
bool SignalDrain = 1; // Variable for the drain pump signal.
unsigned long currentMillis; // Used to know the milliseconds since the program started.
unsigned long CycleLavageMillis; // Used to time the wash cycle.
unsigned long Saut1erCycleDrainMillis; // Used to skip the first draining and save some water.
unsigned long RemplissageMillis; // Used to time the water filling.
unsigned long DelaisRemplissageMillis; // Used for the water filling delay.
const uint32_t CycleLavage = 9000000; // Used to time the wash cycle.
const uint32_t Saut1erCycleDrain = 240000; // Used to skip the first draining and save some water.
const uint16_t Remplissage = 12000; // Used to time the water filling.
const uint16_t DelaisRemplissage = 20000; // Used for the water filling delay.

void setup() {
  pinMode (PinSignalDrain, INPUT_PULLUP);
  pinMode (PinValve, OUTPUT);
}

void loop() {
  // Digital input reading.
  SignalDrain = digitalRead(PinSignalDrain);

  // Used to know the milliseconds since the program started.
  currentMillis = millis(); 

  if (SignalDrain == 0 && CycleEnCour == 0) {
    CycleEnCour = 1;
    CycleLavageMillis = millis();
    Saut1erCycleDrainMillis = millis();
  }

  // Main timing logic.
  if (CycleEnCour == 1) {
    if ((currentMillis - Saut1erCycleDrainMillis) >= Saut1erCycleDrain) {
      if (SignalDrain == 1) {
        DelaisRemplissageMillis = millis();
      }
      else if (SignalDrain == 0) {
        if ((currentMillis - DelaisRemplissageMillis) >= DelaisRemplissage) {
          EnRemplissage = 1;
        }
      }

      if (EnRemplissage == 0) {
        RemplissageMillis = millis();
      }
      else if (EnRemplissage == 1) {
        if ((currentMillis - RemplissageMillis) <= Remplissage) {
          digitalWrite (PinValve, 1);
        }
        else {
          digitalWrite (PinValve, 0);
          EnRemplissage = 0;
          Saut1erCycleDrainMillis = millis();
        }
      }
    }
  }

  if ((currentMillis - CycleLavageMillis) >= CycleLavage) {
    CycleEnCour = 0;
    EnRemplissage = 0;
  }
}
// TECHNICIAN IN SYSTEMS DEVELOPMENT - SENAC NH
// Base program for WORK 2
// PROF.: Glauber Kiss de Souza
// DISC.: Analysis of Oriented Techniques

// Variables
const int somaPin = 13;
int carryBit = 0;
int nib1[4] = {0, 0, 0, 0};
int nib2[4] = {0, 0, 0, 0};
int res[4] = {0, 0, 0, 0};

void setup() {
  // Pin configuration for input and output
  for (int i = 0; i <= 7; i++) {
    pinMode(i, INPUT);
  }
  for (int i = 8; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(somaPin, INPUT);
}

// Function responsible for bitwise addition
int somaBit(int b1, int b2, int carry) {
  return (b1 ^ b2) ^ carry;
}

// Function responsible for the carry bit addition
int somaCarryBit(int b1, int b2, int carry) {
  return (b1 && b2) || (b1 && carry) || (b2 && carry);
}

void loop() {
  // Read the state of the sum pin
  int soma = digitalRead(somaPin);
  
  // Read the bits from the input nibbles
  for (int i = 0; i < 4; i++) {
    nib1[i] = digitalRead(i);
    nib2[i] = digitalRead(i + 4);
  }

  if (soma == HIGH) {
    // Perform bitwise addition with carry
    carryBit = 0;
    for (int i = 0; i < 4; i++) {
      res[i] = somaBit(nib1[i], nib2[i], carryBit);
      carryBit = somaCarryBit(nib1[i], nib2[i], carryBit);
    }
  }

  // Write the results to the output pins
  for (int i = 0; i < 4; i++) {
    digitalWrite(8 + i, res[i]);
  }
  digitalWrite(12, carryBit);
}
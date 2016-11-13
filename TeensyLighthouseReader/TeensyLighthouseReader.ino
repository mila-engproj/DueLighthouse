// Control and status register addr
int* control;

// Reload value register addr
int* load;

// Current value register addr
int* current;

// Calibration value register addr
int* calib;


void setup() {
  // put your setup code here, to run once:


  // Set up serial
  Serial.begin(9600);

  // Set up SysTick addresses
  control = (int*) 0xE000E010;
  load =  (int*) 0xE000E014;
  current = (int*) 0xE000E018;
  calib = (int*) 0xE000E01C;
}

void loop() {
  // put your main code here, to run repeatedly:


  // Check SysTick control values:
  Serial.print("Control (bin): ");
  Serial.print(*control, BIN);
  Serial.println("");


  // Check SysTick load value:
  Serial.print("Reload (dec): ");
  Serial.print(*load);
  Serial.println("");

  // Don't print too fast
  delay(1000);
}

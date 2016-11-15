class SysTick {
  private:
  // Control and status register addr
  int* CONTROL;

  // Reload value register addr
  int* LOAD;

  // Current value register addr
  int* VAL;

  // Calibration value register addr
  int* CALIB;

  public:
  SysTick() {
    CONTROL = (int*) 0xE000E010;
    LOAD =  (int*) 0xE000E014;
    VAL = (int*) 0xE000E018;
    CALIB = (int*) 0xE000E01C;
  }

  int getControl() {
    return *CONTROL;
  }

  int getLoad() {
    return *LOAD;
  }

  int getVal() {
    return *VAL;
  }

  int getCalib() {
    return *CALIB;
  }
};

SysTick* sysTick = new SysTick();

void setup() {
  // put your setup code here, to run once:


  // Set up serial
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  // Check SysTick control values:
  Serial.print("Control (bin): ");
  Serial.println(sysTick->getControl(), BIN);

  // Check SysTick load value:
  Serial.print("Reload (dec): ");
  Serial.println(sysTick->getLoad());

    // Check SysTick current value:
  Serial.print("Current (dec): ");
  Serial.println(sysTick->getVal());

  // Check SysTick calib value:
  Serial.print("Calib (bin): ");
  Serial.println(sysTick->getCalib(), BIN);

  // Check SysTick calib value:
  Serial.print("Calib (dec): ");
  Serial.println(sysTick->getCalib());

  // Don't print too fast
  delay(5000);
}

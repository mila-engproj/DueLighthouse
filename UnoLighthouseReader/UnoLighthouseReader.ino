#define DISPLAY_ANGLES

#define RINGBUFF_LEN 0x100

#define RINGBUFF_MODULO_MASK (RINGBUFF_LEN -1)

#define TICKS_PER_US 84

#define RISING_EDGE  0x00000000
#define FALLING_EDGE 0x80000000

#define MILLIS_MULTIPLIER 1
#define MAX_COUNTER (MILLIS_MULTIPLIER * 8400000)

#define MAX_RECEIVERS 7

/**
 * Classes and Structs
 */

class RingBuff {
  public:

  // Last place read from
  short readerPos;

  // Next placet to write to
  short writerPos;

  /*  
   *  If readerPos == writerPos, RingBuff is full
   */

  volatile unsigned int buff[RINGBUFF_LEN];

  RingBuff() {
    readerPos = 0;
    writerPos = 1;
  }
};

struct OotcPulseInfo {
  int startTime;
  bool data;
  bool rotor;
  bool skip;

  OotcPulseInfo() {
    startTime = 0;
    data = false;
    rotor = false;
    skip = false;
  }
};

class IrReceiver {
  public:

    bool isAsserted;
    int lastRiseTime;

    float X,Y;

    IrReceiver() {
      X = 0;
      Y = 0;
      isAsserted = false;
      lastRiseTime = 0;
    }
};


/**
 * Global Variables
 */

/* Start time of the Lighthouse flash */
int OotcPulseStartTime;

static RingBuff ringBuff;

OotcPulseInfo ootcInfo;

IrReceiver gReceiver[MAX_RECEIVERS];

long int down = 0, up = 0;

// Runs once, at the beginning
void setup() {
  // Output
  pinMode(13, OUTPUT);

  // Inputs
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  // Initialize serial
  Serial.begin(115200);

  // Attach interupts
  attachInterrupt(digitalPinToInterrupt(8), rising0, FALLING);
  attachInterrupt(digitalPinToInterrupt(9), falling0, RISING);

  Serial.print("Done initialization.\n\r");
}

void loop() {
  // put your main code here, to run repeatedly:

}

/**
 * Interrupt routines
 */

void rising0() {
  Serial.print("In rising0\n");
}

void falling0() {
  Serial.print("In falling0");
}


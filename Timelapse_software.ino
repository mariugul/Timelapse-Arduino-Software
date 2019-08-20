#include <Wire.h>
#include <Adafruit_GFX.h>                     // Library for OLED
#include <Adafruit_SSD1306.h>                 // Library for OLED

#define OLED_RESET 4                          // 
Adafruit_SSD1306 display(OLED_RESET);         //

#if (SSD1306_LCDHEIGHT != 64)
// #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

const unsigned char logo [] PROGMEM = {       // GFF graphic

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x01, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x03, 0xe0, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x7f, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc3, 0xff, 0xff, 0xe1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x8f, 0xff, 0xfc, 0x18, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x3f, 0xff, 0xf0, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x7f, 0xff, 0xe0, 0x86, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xff, 0xff, 0xc7, 0xfe, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xff, 0xff, 0xcf, 0xfc, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0xff, 0xff, 0x8f, 0xfc, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0xcf, 0xff, 0xff, 0x8f, 0xf8, 0xf9, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x9f, 0xff, 0xff, 0x9f, 0xf8, 0xfc, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x9f, 0xff, 0xff, 0x9f, 0xf8, 0xfe, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff, 0x9f, 0xf8, 0xfe, 0x60, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x02, 0x7f, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x06, 0x7f, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x04, 0xff, 0xff, 0xff, 0x1f, 0xf8, 0xff, 0x98, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0c, 0xf8, 0x00, 0x10, 0x00, 0x80, 0x0f, 0x98, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0d, 0xe0, 0x00, 0x10, 0x00, 0x80, 0x0f, 0xc8, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x19, 0xc7, 0xe3, 0xff, 0x9f, 0xf8, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1b, 0x8f, 0xf9, 0xff, 0x9f, 0xf8, 0xff, 0xec, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1b, 0x1f, 0xfc, 0xff, 0x9f, 0xf8, 0xff, 0xec, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x13, 0x1f, 0xfc, 0xff, 0x9f, 0xf8, 0xff, 0xe4, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x13, 0x3f, 0xfc, 0x7f, 0x9f, 0xf8, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x33, 0x3f, 0xfe, 0x7f, 0x9f, 0xf8, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x33, 0x3f, 0xfe, 0x7f, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x37, 0x3f, 0xfc, 0x7f, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x37, 0x1f, 0xfc, 0x7f, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x37, 0x1f, 0xfc, 0xff, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x37, 0x8f, 0xf8, 0xff, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x37, 0xc7, 0xf1, 0xff, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x33, 0xe0, 0x03, 0xff, 0x9f, 0xf8, 0xff, 0xf6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x33, 0xf8, 0x0f, 0xff, 0x9f, 0xf8, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x33, 0xf8, 0x7f, 0xff, 0x9f, 0xf8, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x13, 0xe3, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0xe4, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1b, 0xcf, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0xe4, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x19, 0x8f, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0xec, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x19, 0x8f, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0xcc, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0d, 0xc7, 0xff, 0xff, 0x9f, 0xf8, 0xff, 0xc8, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x0c, 0xe0, 0x07, 0xff, 0x9f, 0xf8, 0xff, 0x98, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x04, 0xf0, 0x00, 0xff, 0xff, 0xff, 0xff, 0x98, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x06, 0x1f, 0xfc, 0x3f, 0xff, 0xff, 0xff, 0x30, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x02, 0x3f, 0xff, 0x1f, 0xff, 0xff, 0xfe, 0x60, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x9f, 0xff, 0xff, 0xfe, 0x60, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0x9f, 0xff, 0xff, 0xfc, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0xff, 0x9f, 0xff, 0xff, 0xf9, 0x80, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x67, 0xff, 0x1f, 0xff, 0xff, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0xfe, 0x3f, 0xff, 0xff, 0xe6, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0xfc, 0x3f, 0xff, 0xff, 0xce, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0f, 0xff, 0xff, 0xf8, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc3, 0xff, 0xff, 0xe1, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x07, 0xf0, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xc0, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

// \     I N P U T / O U T P U T                                               |
//  \__________________________________________________________________________|
int           pushButtonE = 0;              // Set enter-button.
int           pushButtonB = A0;              // Set back-button.
int           pushButtonU = A1;              // Set up-button.
int           pushButtonD = A2;              // Set back-button.
int           batteryLevel = A3;             // Analog battery voltage level.
int           LEDtrigger = 12;               // Camera trigger indication.
int           LEDmotor = 13;                 // Motor runing indication.
int           LEDlowBattery = 11;            // Low battery indication.
int           stepMotor = 3;                 // Step motor.
int           dirMotor = 2;                  // Direction motor (H=L and L=R).
int           camFocus = 7;                  // Enables camera focus.
int           camTrigger = 8;                // Triggers the camera.
int           enableStepper = 1;             // Enables the driver output (A=L)


// \     V A R I A B E L S                                                     |
//  \__________________________________________________________________________|
int           buttonPushCounter = 0;         // Sum of enter and back pushes.
int           stateU = 0;                    // Saves pushbutton state.
int           stateD;                        // Saves pushbutton state.
int           stateB;                        // Saves pushbutton state.
int           stateE = HIGH;                 // Saves pushbutton state.
int           nPictures = 150;               // The number of photos.
int           nPassings = 1;                 // The number of passings.
int           intervalTime = 1;              // Delay between each exposure.
int           exposureTime = 1;              // The exposure time per photo.
int           dirRightLeft;                  // Direction movement (right = 1).
float         distTrack = 100;               // The total distance of movement.
float         speedMotor;                    // Motor speed (0.01 - 1).
bool          var = true;                    // Used when initializing.
bool          timelapse;                     // Is the mode chosen timelapse?.

// \     S E T U P                                                             |
//  \__________________________________________________________________________|
void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize, I2C addr 0x3C.
  pinMode(pushButtonU, INPUT_PULLUP);        // Input, internal pullup resistor.
  pinMode(pushButtonD, INPUT_PULLUP);        // Input, internal pullup resistor.
  pinMode(pushButtonE, INPUT_PULLUP);        // Input, internal pullup resistor.
  pinMode(pushButtonB, INPUT_PULLUP);        // Input, internal pullup resistor.
  pinMode(dirMotor, OUTPUT);                 // Output.
  pinMode(stepMotor, OUTPUT);                // Output.
  pinMode(enableStepper, OUTPUT);            // Output.
  pinMode(camFocus, OUTPUT);                 // Output.
  pinMode(camTrigger, OUTPUT);               // Output.
  pinMode(LEDtrigger, OUTPUT);               // Output.
  pinMode(LEDmotor, OUTPUT);                 // Output.
  pinMode(LEDlowBattery, OUTPUT);            // Output.

  // \     S T A R T U P   A N D   W E L C O M E   S C R E E N                   |
  //  \__________________________________________________________________________|
  digitalWrite(enableStepper, HIGH);         // Disables driver output. 
  display.clearDisplay();                    // Clear display.
  display.drawBitmap(0, 0, logo, 128, 64, WHITE); // Draw bitmap logo "GFF".
  display.display();                         // Update display.
  delay(1000);                               // Delay to view bitmap logo.

  display.clearDisplay();                    // Clear logo from display.
  sendText("Timelapse/video", 16, 1, 1, WHITE, BLACK);  // Welcome screen.
  sendText("slide controller", 16, 16, 1, WHITE, BLACK);// -------"--------
  sendText("Ole og Marius", 20, 48, 1, WHITE, BLACK);   // -------"--------
  delay(1000);
  // analogReference(EXTERNAL);                 // ??????????????????????????????????????????????????????????
}


// \     L O O P                                                               |
//  \__________________________________________________________________________|
void loop() {

  // \     T I M E L A P S E   O R   V I D E O   O P E R A T I O N               |
  //  \__________________________________________________________________________|
  while (buttonPushCounter == 0) {

    if (var == true) {                                 // Initializing once.
      display.clearDisplay();                          // Clear display.
      displayBattery();                                // Display the battery.
      stateU = LOW;                                    // sel tlapse from start.
      nPictures = 20;                                  // Initialization value.
      intervalTime = 1;                                // Initialization value.
      exposureTime = 1;                                // Initialization value.
      distTrack = 40;                                  // Initialization value.
      nPassings = 1;                                   // Initialization value.
      var = false;                                     // Initialization once.
      digitalWrite(enableStepper, HIGH);               // Stepper sleep active. 
    }

    if (stateU == LOW) {                               // TIMELAPSE selected.
      sendText("Timelapse", 38, 20, 1, BLACK, WHITE);  // Selected - Black text.
      sendText("Video", 50, 40, 1, WHITE, BLACK);      //            White text.
      timelapse = true;
    }
    else if (stateD == LOW) {                          // VIDEO selected.
      sendText("Timelapse", 38, 20, 1, WHITE, BLACK);  //            White text.
      sendText("Video", 50, 40, 1, BLACK, WHITE);      // Selected - Black text.w
      timelapse = false;
    }

    stateU = digitalRead(pushButtonU);                 // Read up-button.
    stateD = digitalRead(pushButtonD);                 // Read down-button.
    buttonCounter();                                   // Counts prev/next push.
    if (buttonPushCounter != 0) {
      var = true;                                      // For initialization.
      digitalWrite(enableStepper, LOW);                // Enables stepper output.
    }
  }

  // \     T I M E L A P S E   M O D E                                            |
  //  \___________________________________________________________________________|
  if (timelapse == true) {                             // If timelapse-mode.
    displayHeader("Timelapse Mode");
    displayMenu("nPictures:", "Interval:", "Exposure:", "Distance:");
    while (buttonPushCounter != 0) {                   // While for tlapse-menu.

      while (buttonPushCounter == 1) {                 // Set n of pictures.
        nPictures = getValue(nPictures, 90, 25, 1 , " ");
      }

      while (buttonPushCounter == 2) {                 // Set interval seconds.
        intervalTime = getValue(intervalTime, 90, 35, 2, "s");
      }

      while (buttonPushCounter == 3) {                 // Set exposure seconds.
        exposureTime = getValue(exposureTime, 90, 45, 3, "s");
      }

      while (buttonPushCounter == 4) {                 // Set distance in cm.
        distTrack = getValue(distTrack, 90, 55, 4, "cm");
      }


      while (buttonPushCounter == 5) {                 // Get start direction.
        displayHeader("Timelapse Mode");
        getStartDir();
        if (buttonPushCounter == 4) {                  // If return, display
          buttonPushCounter = 1;                       //   prev menu window.
          displayHeader("Timelapse Mode");
          displayMenu("nPictures:", "Interval:", "Exposure:", "Distance:");
        }
      }

      // S T A R T
      var = true;
      while (buttonPushCounter == 6) {                 // Waits for user to
        if (var == true) {                             //  START timelapse.
          displayHeader("Timelapse Mode");
          sendText("START", 35, 25, 2, BLACK, WHITE);
          var = false;
        }
        buttonCounter();
      }

      // T I M E L A P S E    S E K V E N S
      var = true;
      while (buttonPushCounter == 7) {
        countdown();                                   // Counts down 3, 2, 1..

        speedMotor = 0.04260;
        float distPicture = (distTrack / (nPictures - 1)); // Dist per photo.
        float timeMovement = distPicture * (0,056(1/speedMotor)+0,000075);                       // time per movement.
        int timeRemaining;                             // For time calculation.

        displayHeader("Timelapse Mode");               // Initializes display.
        displayMenu("Remaining", "Photos:", "Distance:", "Time:");
        sendText("cm", 100, 45, 1, WHITE, BLACK);
        sendText("s", 100, 55, 1, WHITE, BLACK);
        display.setTextSize(1);
        display.setTextColor(BLACK, WHITE);

        while (nPictures > 0) {
          timeRemaining = ((nPictures * exposureTime) + (nPictures - 1) * (intervalTime + timeMovement + 1)); // Calc time remaining.
          int distR = distTrack;                       // Convert to int.
          display.setCursor(70, 35);                   // Cursor for pictures.
          if (nPictures < 100) {                       // In case two digit.
            display.print(" ");
            if (nPictures < 10) display.print(" ");    // In case one digit.
          }
          display.print(nPictures);                    // Displays number.

          display.setCursor(70, 45);                   // Cursor for distance.
          if (distR < 100) {                   // In case two digit.
            display.print(" ");
            if (distR < 10) display.print(" ");// In case one digit.
          }
          display.print(distR);                        // Displays number.

          display.setCursor(65, 55);                   // Cursor for time.
          if (timeRemaining < 1000) {                  // In case three digit.
            display.print(" ");
            if (timeRemaining < 100) {                 // In case two digit
              display.print(" ");
              if (timeRemaining < 10) display.print(" ");// In case one digit.
            }
          }
          display.print(timeRemaining);                // Displays number.
          display.display();                           // Sends to the display.

          digitalWrite(camFocus, HIGH);                // Cam focus/wake camera.
          delay(900);                                  // Focus/wake-up-time.
          digitalWrite(camTrigger, HIGH);              // Triggers the shutter.
          digitalWrite(LEDtrigger, HIGH);              // LED on, trigger.
          delay(exposureTime * 1000);                  // Delays exposure time.
          digitalWrite(camTrigger, LOW);               // Disables the trigger
          digitalWrite(LEDtrigger, LOW);               // LED off, trigger.
          delay(100);
          digitalWrite(camFocus, LOW);                 // Disables the focus

          if(nPictures > 1) {
            rotateDist(distPicture, dirRightLeft, speedMotor); // Runs motor.
            distTrack -= distPicture;                // - distance traveled.
            delay(intervalTime*1000);                         // Delays further.
          }
          displayBattery();
          nPictures--;                                 // -1 photo.
        }
//        if (nPictures == 1) {                          // If timelapse is done.
//          digitalWrite(camFocus, HIGH);                // Cam focus/wake camera.
//          delay(900);                                  // Focus/wake-up-time.
//          digitalWrite(camTrigger, HIGH);              // Triggers the shutter.
//          digitalWrite(LEDtrigger, HIGH);              // LED on, trigger.
//          delay(100);
//          digitalWrite(camTrigger, LOW);               // Disables the trigger
//          delay(exposureTime * 1000);                  // Delays exposure time.
//          digitalWrite(LEDtrigger, LOW);               // LED off, trigger.
//          delay(100);
//          digitalWrite(camFocus, LOW);                 // Disables the focus
//          delay(500); 
//          nPictures--;
//        }
        if (nPictures == 0) {
          buttonPushCounter = 0;                       // Goes back to menu 0.
          display.clearDisplay();
          sendText("Timelapse done!", 5, 5, 1, WHITE, BLACK);
          stateE = HIGH;
          while (stateE == HIGH) {                     // Waits for b-push.
            stateE = digitalRead(pushButtonE);
            delay(50);
          }
          delay(500);
        }
      }
    }
  }                                                 // END timelapsemode-while()


  // \     V I D E O   M O D E                                                   |
  //  \__________________________________________________________________________|
  else {                                               // Video-mode was chosen
    displayHeader("Video Mode");
    displayMenu("Distance:", "Speed:", "Passings:", "Time passing:");

    while (buttonPushCounter != 0) {
      int timePerPassing = 0;
      int speedOption = 0;
      while (buttonPushCounter == 1) {                 // Get trackdist
        distTrack = getValue(distTrack, 90, 25, 1, "cm");
      }

      stateU = LOW;
      while (buttonPushCounter == 2) {                 // Get speedoption.

        if (stateU == LOW) {                           // Set upper speed limit.
          if (speedOption < 6) sendNumber(++speedOption, 90, 35, 1, BLACK, WHITE);
        }
        else if (stateD == LOW) {                      // Set lower speed limit.
          if (speedOption > 1) sendNumber(--speedOption, 90, 35, 1, BLACK, WHITE);
        }
        switch (speedOption) {                         // Sets motor speed and
          case 1:                                      //   calculates time
            speedMotor = 0.05;                         //   elapsed with option.
            timePerPassing = distTrack * (0,056(1/speedMotor)+0,000075);
            break;
          case 2:
            speedMotor = 0.08;
            timePerPassing = distTrack * (0,056(1/speedMotor)+0,000075);
            break;
          case 3:
            speedMotor = 0.11;
            timePerPassing = distTrack * (0,056(1/speedMotor)+0,000075);
            break;
          case 4:
            speedMotor = 0.14;
            timePerPassing = distTrack * (0,056(1/speedMotor)+0,000075);
            break;
          case 5:
            speedMotor = 0.17;
            timePerPassing = distTrack * (0,056(1/speedMotor)+0,000075);
            break;
          case 6:
            speedMotor = 0.19;
            timePerPassing = distTrack * (0,056(1/speedMotor)+0,000075);
            break;
        }
        
        display.setCursor(90, 55);                     // Cursor, time passing.
        display.setTextColor(WHITE, BLACK);
        display.print("    ");                         // "Ereases" prev number.
        display.setCursor(90, 55);                     // Position again.
        display.print(timePerPassing);                 // Displays number.
        display.setCursor(110, 55);                    // Sets cursor for unit.
        display.print("s");                            // Displays unit.
        display.display();                             // Sends all to display.

        stateU = digitalRead(pushButtonU);             // Read up-button.
        stateD = digitalRead(pushButtonD);             // Read down-button.
        buttonCounter();                               // Read return/enter.
        if (buttonPushCounter != 2) {                  // Before going to next,
          sendNumber(timePerPassing, 90, 55, 1, WHITE, BLACK); //   prints with
          sendNumber(speedOption, 90, 35, 1, WHITE, BLACK); //      white text.
        }
      }

      while (buttonPushCounter == 3) {                 // Get n of passings.
        nPassings = getValue(nPassings, 90, 45, 3, " ");
        delay(100);                                    // Ease of sel low nr.
      }

      while (buttonPushCounter == 4) {                 // Get start direction.
        displayHeader("Video Mode");
        getStartDir();
        if (buttonPushCounter == 3) {                  // Going to prev menu.
          buttonPushCounter = 1;
          displayHeader("Video Mode");
          displayMenu("Distance:", "Speed:", "Passings:", "Time passing:");
        }
      }
      var = true;

      while (buttonPushCounter == 5) {                 // Waits for user to
        if (var == true) {                             //  START video mode.
          displayHeader("Video Mode");
          sendText("START", 35, 25, 2, BLACK, WHITE);
          var = false;
          delay(200);
        }
        buttonCounter();
        delay(100);
      }

      while (buttonPushCounter == 6) {
        countdown();                                   // Counts down 3, 2, 1.
        displayHeader("Video Mode");
        displayMenu("Remaining", "Loops:", "  ", "  ");
        sendText("stk", 100, 35, 1, WHITE, BLACK);     // Display units.
        display.setTextSize(1);
        display.setTextColor(BLACK, WHITE);

        while(nPassings > 0) {
          display.setCursor(70, 35);                   // Cursor pictures.
          if (nPassings < 100) {                       // In case two digit.
            display.print(" ");
            if (nPassings < 10) display.print(" ");    // In case one digit.
          }
          display.print(nPassings);                    // Prints number.
          display.display();                           // Sends all to display.
          
          float distRemaining = distTrack;
          while(distRemaining > 0) {
            // R U N   M O T O R   C O N T I N I O U S L Y   F O R   G I V E N   D I S T
            rotateDist(0.2, dirRightLeft, speedMotor);
            distRemaining -= 0.2;
          }

          if (dirRightLeft == 0) dirRightLeft = 1;
          else dirRightLeft = 0;
          nPassings--;

          
        }
        if (nPassings < 1) {                           // If video done.
          buttonPushCounter = 0;                       // Goes back to menu 0.
          display.clearDisplay();
          sendText("Video done!", 5, 5, 1, WHITE, BLACK);
          stateE = digitalRead(pushButtonE);
          var = true;
          while (stateE == HIGH) {                     // Waits for b-push.
            stateE = digitalRead(pushButtonE);
            delay(10);
          }
          delay(1000);
        }
      }
    }
  }
}                                                      // Void loop() end.


// \     F U N C T I O N S                                                     |
//  \__________________________________________________________________________|

//   S E N D   T E X T      - Used to send text to display
void sendText(String text, int x, int y, int Size, int color, int backColor) {
  display.setTextSize(Size);                           // Text size (integer).
  display.setTextColor(color, backColor);              // Text/background color.
  display.setCursor(x, y);                             // Places cursor on disp.
  display.println(text);                               // Sends text to displ.
  display.display();                                   // Updates the display.
}

//   S E N D   N U M B E R  - Send up to 3digit integer numbers to the display.
void sendNumber(int nr, int x, int y, int Size, int color, int backColor) {
  display.setTextSize(Size);                           // Text size.
  display.setTextColor(color, backColor);              // Text/background color.
  display.setCursor(x, y);                             // Places cursor on disp.
  if (nr < 100) {                                      // In case two digit.
    display.print(" ");                                // Blank fill space.
    if (nr < 10) display.print(" ");                   // In case one diigt.
  }
  display.println(nr);                                 // Sends number to disp.
  display.display();                                   // Updates the display.
}

//   D I S P L A Y   H E A D E R  - Used to clear display and print the header.
void displayHeader(String str) {
  display.clearDisplay();                              // Clear display
  sendText(str, 1, 1, 1, WHITE, BLACK);                // Display header text.
  display.drawFastHLine(1, 8, str.length() * 6, WHITE);// Line under header.
  displayBattery();                                    // Battery level.
}

//   D I S P L A Y   M E N U    - Display a menu list, up to 4 arguments.
void displayMenu(String str1, String str2, String str3, String str4) {
  sendText(str1, 1, 25, 1, WHITE, BLACK);
  sendText(str2, 1, 35, 1, WHITE, BLACK);
  sendText(str3, 1, 45, 1, WHITE, BLACK);
  sendText(str4, 1, 55, 1, WHITE, BLACK);
  display.display();
}

//   B U T T O N   C O U N T E R    - Reads Enter/Back button, updates
void buttonCounter() {            //  buttonPushCounter for menu navigation.
  stateE = digitalRead(pushButtonE);
  stateB = digitalRead(pushButtonB);
  if (stateE == LOW) {                                 // If enter was pushed
    if (buttonPushCounter < 999) {                     // Limit counter to 999
      buttonPushCounter++;                             // Increment counter if less than 999
    }
  }
  else if (stateB == LOW) {                            // If back was pushed
    if (buttonPushCounter > 0) {                       // Limit counter to positive numbers
      buttonPushCounter--;                             // Decrement counter if bigger than zero
    }
  }
  delay(200);                                          // Debouncing.
}

//   M E A S U R E   A N D   D I S P L A Y   B A T T E R Y   L E V E L
void displayBattery() {
  float level = analogRead(batteryLevel);
  
  if (level > 1020) {
    drawBatteryIcon(115, 2, 11, 2);
    digitalWrite(LEDlowBattery, LOW);                  // OFF, low battery LED.
  }
  else if (level > 1010) {
    drawBatteryIcon(118, 2, 8, 2);                     // __ %
    digitalWrite(LEDlowBattery, LOW);                  // OFF, low battery LED.
  }
  else if (level > 995) {
    drawBatteryIcon(120, 2, 6, 2);                     // __ %
    digitalWrite(LEDlowBattery, LOW);                  // OFF, low battery LED.
  }
  else if (level > 985) {
    drawBatteryIcon(123, 2, 3, 2);                     // __ %
    digitalWrite(LEDlowBattery, HIGH);                 // ON, low battery LED.
  }
  else if (level < 975) {
    drawBatteryIcon(0, 0, 0, 0);                       // 0 %
    digitalWrite(LEDlowBattery, HIGH);                 // ON, low battery LED.
  }

}
//
//////   D R A W  T H E   B A T T E R Y   I C O N
void drawBatteryIcon(int x, int y, int w, int h) {
  display.drawRect(111, 2, 1, 2, WHITE);               // Draw battery square.
  display.drawRect(112, 0, 16, 6, WHITE);              // Draw battery rectangle.
  display.fillRect(113, 1, 14, 4, BLACK);              // Draw blank battery.
  display.fillRect(x, y, w, h, WHITE);                 // Display battery %.
}

// G E T   A   S T A R T   D I R E C T I O N
void getStartDir() {
  int timelapseOrVideo = 5;
  if (timelapse == false) timelapseOrVideo = 4;
  sendText("Start direction", 20, 25, 1, WHITE, BLACK);
  sendText("Forward", 40, 40, 1, BLACK, WHITE);
  sendText("Backward", 36, 55, 1, WHITE, BLACK);
  dirRightLeft = 1;
  while (buttonPushCounter == timelapseOrVideo) {
    if (stateU == LOW) {
      sendText("Forward", 40, 40, 1, BLACK, WHITE);    // Forward selected.
      sendText("Backward", 36, 55, 1, WHITE, BLACK);   // Backward unselected.
      dirRightLeft = 1;                                // Start dir is Forward.
    }
    else if (stateD == LOW) {
      sendText("Forward", 40, 40, 1, WHITE, BLACK);           // Forward unselected.
      sendText("Backward", 36, 55, 1, BLACK, WHITE);           // Backward selected.
      dirRightLeft = 0;                                // Start dir is Backward.
    }
    stateU = digitalRead(pushButtonU);
    stateD = digitalRead(pushButtonD);
    buttonCounter();
  }
}

  //G E T   A   N U M B E R   V A L U E
int getValue(int startValue, int x, int y, int menuItem, String unit ) { // Gets value of numbers selected by push-buttons
  int temp = startValue;                                                          // Temp verdi for den aktuelle verdeien
  if(var == true){                                                                // If true...
    sendNumber(temp, x, y, 1, BLACK, WHITE);                               // Prints startvalue
    sendText(unit, x+20, y, 1, WHITE, BLACK);                                     // Prints value unit
    var = false;                                                                  // Set var false to not refresh every loop round
  }

  stateU = digitalRead(pushButtonU);                                              // Reads up-button
  stateD = digitalRead(pushButtonD);                                              // Reads down-button
  buttonCounter();                                                                // Counts enter and return buttons

  if(stateU == LOW) {
    if(temp < 999)  sendNumber(++temp, x, y, 1, BLACK, WHITE);             // Limits value, adds one and prints to screen
  }
  else if(stateD == LOW) {
    if(temp > 1)    sendNumber(--temp, x, y, 1, BLACK, WHITE);             // Limits value, subtracts one and prints to screen
  }
  if(buttonPushCounter != menuItem) {
    sendNumber(temp, x, y, 1, WHITE, BLACK);                               // Prints white number if moving on
    var = true;
  }
  return temp;
}

//   R O T A T E   M O T O R   F O R   G I V E N   D I S T A N C E
void rotateDist(float dist, int dir, float rotSpeed) {
  digitalWrite(dirMotor, dir);                         // Set direction.
  int steps = abs((dist) * (1600 / 4));                // Calculates nr steps.
  float stepDelay = (1 / rotSpeed) * 70;               // Calc ms between steps.

  digitalWrite(LEDmotor, HIGH);                        // LED on, when motor on.
  for (int i = 0; i < steps; i++) {                    // loops for n steps.
    digitalWrite(stepMotor, HIGH);                     // Sets step pin high.
    delayMicroseconds(stepDelay);                      // Delay, speed controll.
    digitalWrite(stepMotor, LOW);                      // Sets step pin low.
    delayMicroseconds(stepDelay);                      // Dealy, speed controll.
  };
  digitalWrite(LEDmotor, LOW);                         // LED off, motor off.
}

// C O U N T D O W N    - Countdown before sequence start.
void countdown() {
  delay(300);
  display.clearDisplay();
  sendText("Begins in...", 5, 20, 1, WHITE, BLACK);   // Begins in...
  sendText("3", 95, 15, 2, BLACK, WHITE);              // 3..
  delay(1000);
  sendText("2", 95, 15, 2, BLACK, WHITE);              // 2..
  delay(1000);
  sendText("1", 95, 15, 2, BLACK, WHITE);              // 1..
  delay(1000);
}


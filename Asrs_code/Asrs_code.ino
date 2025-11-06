//Automatic Storage and retrieval System Code. 

#include <Keypad.h> #include <Servo.h>

// Define the pins for the servo motor and keypad #define SERVO_PIN 9
#define ROWS 4
#define COLS 4


// Define the keypad keys and their corresponding labels char keys[ROWS][COLS] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

// Define row and column pins for servo 
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {8, 7, 6, 10};


// Create instances of the Servo and Keypad libraries Servo servo;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


// Define the positions for each tray
int trayPositions[4] = {0, 45, 90, 135}; // Adjust these angles as needed


void setup() {
// Attach the servo to the servo pin servo.attach(SERVO_PIN);

// Initialize the serial communication
 

Serial.begin(9600);
}


void loop() {
// Check if a key is pressed on the keypad char key = keypad.getKey();

if (key != NO_KEY) {
// Move the corresponding tray based on the key pressed switch (key) {
case 'A': moveTray(0); break;
case 'B': moveTray(1); break;
case 'C': moveTray(2); break;
case 'D': moveTray(3); break;
}
}
}


void moveTray(int trayIndex) {
// Map the tray index to the corresponding position int trayPosition = trayPositions[trayIndex];

// Move the servo to the specified position servo.write(trayPosition);
 

// Print the tray movement to the serial monitor Serial.print("Moving tray "); Serial.print((char)('A' + trayIndex)); Serial.print(" to position "); Serial.println(trayPosition);

// Add a delay if necessary to allow the servo to reach the desired position delay(1000);
}
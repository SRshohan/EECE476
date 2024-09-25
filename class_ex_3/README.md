## Output

// Declare variables and initialize them
bool state = LOW;         // Variable to store the state of the switch
bool push = false;        // Variable to track if the push button is pressed
bool onOff = false;       // Variable to track the LED state (on/off)
bool toggle = false;      // Initialize toggle to false
const int switchPin = 2;  // Pin connected to the switch
const int ledPin = 13;    // Pin connected to the LED

void setup() {
    pinMode(switchPin, INPUT);     // Set the switchPin as input
    pinMode(ledPin, OUTPUT);       // Set the ledPin as output
    digitalWrite(ledPin, LOW);     // Initialize the LED as off
}

void loop() {
    state = digitalRead(switchPin); // Read the switch state
    if (state == HIGH) {            // If switch is in short circuit (pressed)
        if (push == true) {         // If push button is pressed
            onOff = !onOff;         // Toggle the LED state
            if (onOff) {
                digitalWrite(ledPin, HIGH); // Turn the LED on
            } else {
                digitalWrite(ledPin, LOW);  // Turn the LED off
            }
        }
        push = false;               // Reset the push state after toggling
    } else {                        // If switch is in open circuit (not pressed)
        toggle = true;              // Set toggle to true when circuit is open
    }

    delay(100);                     // Delay for 100ms to prevent bouncing
}

// --- manager.ino ---
// This file can be used to manage pover
// delivered to motherboard and operate
// hardware clock.

int attemp = 0;
int bps = 9600;

class Monitoring {
    public:
        bool isActive() {
            return bool digitalRead(boardStatusIndicator) == HIGH;
        }
}

class ManagerBoard {
    void readConfig() {};
    void startSetup() {
        Serial.begin(bps);
        Serial1.begin(bps);
        Serial2.begin(bps);
    };
}

class Power {
    void sigterm() {
        digitalWrite(signalizator, HIGH);
        delay(2500);
        digitalWrite(signalizator, LOW);
    }
}

void setup() {
    ManagerBoard::startSetup();
}

void loop() {
    if(Monitoring::isActive() == (exceptedBoardStatus == HIGH)) {}
}
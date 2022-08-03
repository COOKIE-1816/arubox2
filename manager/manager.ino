// --- manager.ino ---
// This file can be used to manage pover
// delivered to motherboard and operate
// hardware clock.

int attemp = 0;

class Monitoring {
    public:
        bool isActive() {
            return bool digitalRead(boardStatusIndicator) == HIGH;
        }
}

class ManagerBoard {
    void readConfig() {};
    void startSetup() {};
}

void setup() {
    ManagerBoard::startSetup();
}

void loop() {
    if(Monitoring::isActive() == (exceptedBoardStatus == HIGH)) {}
}
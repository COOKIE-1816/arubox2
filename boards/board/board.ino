#include <iostream>
#include <cstring>

#define max 8

using namespace std;

string strings[max];

int len(string str) {
    int length = 0;

    for(int i = 0; str[i] != "\0"; i++) {
        length++;
    }

    return length;
}

void split(string str, char separator) {
    int current = 0, i = 0;
    int start = 0, end = 0;

    while(i <= len(str)) {
        if(str[i] == separator || i == len(str)) {
            end = i;

            string subst = "";
            subst.append(str, start, end - start);
            strings[current] = subst;

            current += 1;
            start = end + 1;
        }

        i++;
    }
}

class BIF {
    public:
        char file = "file";
        char entry_name = "OS on firmware device";
        size entry_idn_ = 0;
        int memory = 4;
        bool quiet = false;
        bool display = true;
};

void load_BIF(BIF_contents) {
    BIF bif_;

    split(string raw, char "\n");
    bif = strings;

    return 0;
};

void setup() {}
void loop() {}
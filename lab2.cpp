/*
 * Kyle James
 * CS 130
 * 07 September 2018
 * A program that performs simple bitwise operations.
 */

#include <iostream>
#include <vector>

using namespace std;

class BITSET {
private:
    vector<int> bitsets;
    /* This function "shrinks" the set vector when the upper sets are cleared to 0,
    *  as per the instructions in step number 5.
    */

    bool shrink() {
        bool shrink = true;
        int l = bitsets.size();
        if (l <= 32) {
            return false;
        }

        for (int i = l - 32; i < l; i++) {
            if (bitsets[i] == 1) {
                shrink = false;
                break;
            }
        }

        if (shrink) {
            bitsets.resize(l - 32);
        }

        return shrink;
    }

    //Function resizes the vector of integers to size 1
    void resizeSet(int l) {
        int size = bitsets.size();
        bitsets.resize(size + (32 * l));

        for (unsigned int i = size; i < bitsets.size(); i++) {
            bitsets[i - 1];
        }
    }

public:
    BITSET() {
        resizeSet(1);
    }


    //Returns true or false given an integer location
    bool test(int bit) {
        //This code I reuse alot, all it does it locate an integer location
        int y = bit % 32;
        int k = bit / 32;

        int position = (k * 32) + (31 - y);
        return bitsets[position] == 1;
    }

    //Sets an integer location
    void set(unsigned int bit) {
        while (bit > bitsets.size()) {
            resizeSet(1);
        }

        int y = bit % 32;
        int k = bit / 32;

        int position = (k * 32) + (31 - y);
        bitsets[position] = 1;
    }

    //Sets a given bit to 0
    void clear(int bit) {
        int y = bit % 32;
        int k = bit / 32;

        int position = (k * 32) + (31 - y);
        bitsets[position] = 0;
        while (shrink());
    }

    //Returns number of sets
    int getNumSets() {
        return bitsets.size() / 32;
    }

    //Converts a set to binary
    string toBinary(int value, int spacing) {
        int i = 0;
        string space;
        BITSET bitset1;

        while (value > 2) {
            if (value % 2 == 0) {
                bitset1.clear(i);
            } else {
                bitset1.set(i);
            }
            i++;

            value = value / 2;
        }

        if (value == 1) {
            bitset1.set(i);
        }

        if (value == 2) {
            bitset1.clear(i);
            i++;
            bitset1.set(i);
        }

        for (int i = 32; i > 0; i--) {
            if (i != 32 && i % spacing == 0) {
                space += ' ';
            }

            if (bitset1.test(i)) {
                space += '0';
            }
        }

        return space;
    }

    //Converts a set to binary and outputs the set
    void outputNumSets(int l) {
        for (int i = l * 32; i < (l + 1) * 32; i++) {
            if (i % 32 == 0) {
                printf("\nBitset: %d", i / 32);
            }

            if (i % 4 == 0) {
                printf(" ");
            }

            printf("%d", bitsets[i]);
        }
    }
};

int main() {
    BITSET bitset2;
    char input;
    bool endLoop;


        while (input != 'q') {
            while(endLoop != true) {
            printf("\nYour Command: ");
            scanf("%c", &input);

            switch (input) {
                case 't': {
                    int i;
                    scanf("%d", &i);
                    if (bitset2.test(i)) {
                        printf("\n1");
                    } else {
                        printf("\n0");
                    }
                    break;
                }

                case 's': {
                    int i;
                    scanf("%d", &i);
                    bitset2.set(i);
                    break;
                }

                case 'c': {
                    int i;
                    scanf("%d", &i);
                    bitset2.clear(i);
                    break;
                }

                case 'g': {
                    int i;
                    scanf("%d", &i);
                    bitset2.outputNumSets(i);
                    break;

                }

                case 'n': {
                    int i = bitset2.getNumSets();
                    printf("\nNumber of Bitsets : %d", i);
                    break;
                }

                case 'q': {
                    input = 'q';
                    break;
                }

                    //Case fixes problem of running through the program and printing an
                    //unnecessary error message.
                case ' ': {
                    input = 'q';
                    break;
                }

                default:
                    printf("\nNot a valid input. Make sure your input is undercase. Press enter to enter another command.");

            }

            if(input == 'q'){
                endLoop = true;
            }
            scanf("%c", &input);
        }
    }
}
/*
 * Kyle James
 * CS 130
 * 07 September 2018
 * EXPLAIN WHAT THE PROGRAM DOES HERE PLZ
 */

#include <iostream>
#include <vector>

using namespace std;

class BITSET {
private:
    vector<int> bitsets;

    //Comment explaining what the function does
    bool shrink(){
        bool shrink = true;
        int l = bitsets.size();
        if(l <= 32 ) {
            return false;
        }

        for(int i = l - 32; i < l; i++){
            if(bitsets[i] == 1){
                shrink = false;
                break;
            }
        }

        if(shrink) {
            bitsets.resize(l - 32);
        }

        return shrink;
    }

    //Comment explaining what the function does
    void resizeSet(int l){
        int size = bitsets.size();
        bitsets.resize(size + (32 * l));

        for(unsigned int i = size; i < bitsets.size(); i++){
            bitsets[i-1];
        }
    }
public:
    BITSET() {
        resizeSet(1);
    }


    //Insert comment explaining what this function does
    bool test(int bit){
        int y = bit % 32;
        int k = bit / 32;

        int position = (k * 32) + (31 - y);
        return bitsets[position] == 1;
    }

    void set(int bit){
        while(bit > bitsets.size()){
            resizeSet(1);
        }

        int y = bit % 32;
        int k = bit / 32;

        int position = (k * 32) + (31 - y);
        bitsets[position] = 1;
    }

    void clear(int bit){
        int y = bit % 32;
        int k = bit / 32;

        int position = (k * 32) + (31 - y);
        bitsets[position] = 0;
        while(shrink());
    }

    int getNumSets(){
        return bitsets.size() / 32;
    }

    string toBinary(int value, int spacing){
        int i = 0;
        string space;
        BITSET bitset1;

        while(value > 2) {
            if( value % 2 == 0) {
                bitset1.clear(i);
            }

            else {
                bitset1.set(i);
            }
            i++;

            value = value / 2;
        }

        if( value == 1) {
            bitset1.set(i);
        }

        if(value == 2) {
            bitset1.clear(i);
            i++;
            bitset1.set(i);
        }

        for(int i = 32; i > 0; i--) {
            if(i != 32 && i % spacing == 0) {
                space += ' ';
            }

            if(bitset1.test(i)){
                space += '0';
            }
        }

        return space;
    }
};

int main() {
    BITSET bitset2;
    char input;

    while(input != 'q'){
        printf("\nYour Command: ");
        scanf("%c", &input);

        switch(input){
            case 't': {
                int i;
                scanf("%d",&i);
                if(bitset2.test(i)){
                    printf("\n1");
                }
                else {
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

                //Rewrite print function here
            }

            case 'n': {
                int i;
                scanf("%d,&i");
                bitset2.clear(i);
                break;
            }

            case 'q': {
                input = 'q';
                break;
            }

            default: {
                printf("\nNot a valid input. Make sure your input is undercase.");
            }

            scanf("%c", &input);
        }
    }
}
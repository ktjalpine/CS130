#include<iostream>
#include<vector>

using namespace std;

class BITSET {
private:
    vector<int> bits;

    void increaseSet(int n) {
        int s = bits.size();
        bits.resize(s + (32 * n));
        for (unsigned int i = s; i < bits.size(); i++) {
            bits[i - 1] = 0;
        }
    }

    bool shrink() {
        int n = bits.size();
        if (n <= 32) {
            return false;
        }
        bool shr = true;
        for (int i = n - 32; i < n; i++) {
            if (bits[i] == 1) {
                shr = false;
                break;
            }
        }
        if (shr) {
            bits.resize(n - 32);
        }
        return shr;
    }

public:
    BITSET() {
        increaseSet(1);
    }

    bool Test(int bit) {
        if (bit < 0 && bit >= bits.size()) {
            return false;
        }
        int n = bit / 32;
        int p = bit % 32;
        int pos = (n * 32) + (31 - p);
        return bits[pos] == 1;
    }

    void Set(int bit) {
        while (bit > bits.size()) {
            increaseSet(1);
        }
        int n = bit / 32;
        int p = bit % 32;
        int pos = (n * 32) + (31 - p);
        bits[pos] = 1;
    }

    void Clear(int bit) {
        if (bit < 0 && bit >= bits.size()) {
            return;
        }
        int n = bit / 32;
        int p = bit % 32;
        int pos = (n * 32) + (31 - p);
        bits[pos] = 0;
        while (shrink());
    }

    int GetNumSets() {
        return bits.size() / 32;
    }

    void inc() {
        increaseSet(1);
    }

    void print(int n) {
        if (n < 0 || n > GetNumSets()) {
            return;
        }
        for (int i = n * 32; i < (n + 1) * 32; i++) {
            if (i % 32 == 0) {
                printf("\nSET %d: ", i / 32);
            }
            if (i % 4 == 0) {
                printf(" ");
            }
            printf("%d", bits[i]);
        }
    }

};

string ToBinary(int val, int space) {
    BITSET b;
    int i = 0;
    while (val > 2) {
        if (val % 2 == 0) {
            b.Clear(i);
        } else {
            b.Set(i);
        }
        i++;
        val = val / 2;
    }

    if (val == 1) {
        b.Set(i);
    }

    if (val == 2) {
        b.Clear(i);
        i++;
        b.Set(i);
    }
    string s = "";
    for (int i = 32; i > 0; i--) {
        if (i != 32 && i % space == 0) {
            s += ' ';
        }
        if (b.Test(i)) {
            s += '1';
        } else {
            s += '0';
        }
    }
    cout << s;
    return s;
}

int main() {
    BITSET b;
    char command = ' ';
    while (command != 'q') {
        printf("\nCMD >> ");
        scanf("%c", &command);
        switch (command) {
            case 't': {
                int n;
                scanf("%d", &n);
                if (b.Test(n)) {
                    printf("\n1");
                } else {
                    printf("\n0");
                }
                break;
            }
            case 's': {
                int n;
                scanf("%d", &n);
                b.Set(n);
                break;
            }
            case 'g': {
                int n;
                scanf("%d", &n);
                //please specify it clearly i didn't get
                b.print(n);
                break;
            }
            case 'n': {
                int n = b.GetNumSets();
                printf("\nNumber Of Set : %d", n);
                break;
            }
            case 'q': {
                command = 'q';
                break;
            }
            case 'c': {
                int n;
                scanf("%d", &n);
                b.Clear(n);
                break;
            }
            default:
                printf("\nINVALID COMMAND !!! ");
        }
        scanf("%*c", &command);
    }
}
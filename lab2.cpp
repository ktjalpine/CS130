#include <iostream>
#include <vector>

using namespace std;


class bitset {
private:
    vector<int> bitsets;
public:

    resize(){
        for(int i = 1; i < 10; i++){
            bitsets.push_back(i);
        }
    }
};

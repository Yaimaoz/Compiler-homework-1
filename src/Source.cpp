#include <iostream>
#include "Gate.h"
#include "Network.h"
using namespace std;

int main( int argc, char*argv[] ){

    
    Network network;
    network.parser();
    network.topologySort();
    network.test();
    return 0;
}

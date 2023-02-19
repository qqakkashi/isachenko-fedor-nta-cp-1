//
//  main.cpp
//  isachenko-fedor-nta-cp-1
//
//  Created by qqakkashi on 19.02.2023.
//

#include <iostream>
#include "miller-rabin-test.cpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    int prime_test = miller(5);
    std::cout << prime_test;
    return 0;
}

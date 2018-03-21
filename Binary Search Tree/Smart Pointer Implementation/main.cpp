//
//  main.cpp
//  BSTsmart
//
//  Created by samuel on 3/5/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include "BSTtree.h"
#include <iostream>
using namespace std;

int main(){
    BSTtree A;
    A.InsertNR(10);
    A.InsertNR(20);
    A.InsertNR(5);
    A.InsertNR(30);
    
    A.InorderPrint();
    
    return 0;
    
    
    
}


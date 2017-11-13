//
//  arbiter.h
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef arbiter_h
#define arbiter_h

#include "systemc.h"

SC_MODULE(arbiter){
    sc_in<bool> clk;
    sc_out<int> a_out;
    int counter;
    void arbiter_p();
    
    SC_CTOR(arbiter){
        counter = 0;
        SC_METHOD(arbiter_p);
        dont_initialize();
        sensitive<<clk.pos();
    }
    
    
};


#endif /* arbiter_h */

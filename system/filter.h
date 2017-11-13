//
//  filter.hpp
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef filter_h
#define filter_h

#include "systemc.h"

SC_MODULE(filter){
    sc_in<char> f_in;
    sc_out<char> f_out;
    
    void filter_p();
    
    SC_CTOR(filter){
        SC_METHOD(filter_p);
        sensitive<<f_in;
    }
    
    
    
    
};

#endif /* filter_h */

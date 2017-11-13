//
//  change_case.h
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef change_case_h
#define change_case_h

#include "systemc.h"

SC_MODULE(change_case){
    sc_in<char> c_in;
    sc_out<char> c_out;
    
    void change_case_p();
    
    SC_CTOR(change_case){
        SC_METHOD(change_case_p);
        sensitive<<c_in;
    }
    
};



#endif /* change_case_h */

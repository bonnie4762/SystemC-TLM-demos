//
//  ram.h
//  lab2_ram
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef ram_h
#define ram_h

#include "systemc.h"

class ram: public sc_module{
public:
    
    sc_in<bool> clk;
    sc_inout<sc_uint<8>> data;
    sc_in<sc_uint<32>> addr;
    sc_in<bool> ce;
    sc_in<bool> we;
    
    
    
    SC_HAS_PROCESS(ram);
    
    ram(sc_module_name name, int s) : sc_module(name), size(s){
        memory = new sc_uint<8>[size];
        SC_THREAD(init);
    
        SC_METHOD(ram_p);
        dont_initialize();
        sensitive<<clk.pos();
        
    }
    
    void init();
    void ram_p();
    
    
private:
    int size;
    sc_uint<8> *memory;
    
    
    
};


#endif /* ram_h */

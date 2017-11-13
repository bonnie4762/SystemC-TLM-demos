//
//  uart.h
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef uart_h
#define uart_h

#include "systemc.h"


SC_MODULE(uart){
    sc_in<char> u_in;
    sc_out<char> u_out;
    
    
    
    SC_CTOR(uart){
        
    }
    
    
    
};


#endif /* uart_h */

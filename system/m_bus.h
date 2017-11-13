//
//  m_bus.h
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#ifndef m_bus_h
#define m_bus_h

#include "systemc.h"

SC_MODULE(m_bus){
    sc_in<char> c_m_in;
    sc_in<char> f_m_in;
    sc_in<int> a_m_in;
    sc_out<char> m_out;
    
    void m_bus_p();
    
    SC_CTOR(m_bus){
        SC_METHOD(m_bus_p);
        sensitive<<c_m_in<<f_m_in<<a_m_in;
    }
    
    
};


#endif /* m_bus_h */

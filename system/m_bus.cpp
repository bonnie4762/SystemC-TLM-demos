//
//  m_bus.cpp
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "m_bus.h"

void m_bus::m_bus_p(){
    
    if(a_m_in==0)
        m_out = c_m_in;
    else if (a_m_in==1)
        m_out = f_m_in;
    
}

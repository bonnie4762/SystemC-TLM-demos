//
//  arbiter.cpp
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "arbiter.h"

void arbiter::arbiter_p(){
    counter ++;
    if(counter==100){
        counter = 0;
        a_out = !a_out;
    }
    
}



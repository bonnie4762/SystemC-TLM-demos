//
//  filter.cpp
//  task4_3
//
//  Created by bonnie on 03/10/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include "filter.h"

void filter::filter_p(){
    f_out = f_in;
    const char *characters = "systemc";
    while(*characters){
        if((*characters++)==f_in){
            f_out = '#';
            break;
        }
    }
}

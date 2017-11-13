//
//  channel.cpp
//  scLab
//
//  Created by bonnie on 26/09/2017.
//  Copyright © 2017 bonnie. All rights reserved.
//

#include"channel.h"


void channel::write(char c)
{
    while(n>=100){
        wait(1, SC_NS);
    }
    if (n<100){
        n++;
        data[w++] = c;
        if(w==100){
            w = 0;
        }
    }
}

char channel::read()
{
    while(n==0){
        wait(1, SC_NS);
    }
    char c;
    if(n>0){
        n--;
        c=data[r++];
        if(r==100){
            r=0;
        }
    }
   
    return c;
}

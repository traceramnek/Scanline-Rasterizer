//
//  Equation.h
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/17/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#ifndef Equation_h
#define Equation_h

#include <stdio.h>
#include <iostream>
#include "Equation.h"
#include "Vertex.h"


class Equation{
public:
    // variables used in the implicit function
    float x0,y0,x1,y1;
    float ACoef, BCoef, CCoef;
    //constructors
    Equation();
    Equation(Vertex frst, Vertex scnd);
    float solveXImp(int impY); // solves for x frmo implicit equation

    
};

#endif /* Equation_h */

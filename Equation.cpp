//
//  Equation.cpp
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/9/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Equation.h"

using namespace std;

Equation::Equation(){
    // set each coordinate to it's corresponding value
    this->x0 = 1;
    this->x1 = 1;
    this->y0 = 2;
    this->y1 = 2;
    
    this->ACoef = y0-y1;// finds A coef
    this->BCoef = x1-x0;// finds B coef
    this->CCoef = (x0*y1) - (x1*y0);// find C coef
}

Equation::Equation(Vertex frst, Vertex scnd){
    // set each coordinate to it's corresponding value
    this->x0 = frst.getXPos();
    this->x1 = scnd.getXPos();
    this->y0 = frst.getYPos();
    this->y1 = scnd.getYPos();
    
    //set A B and C Coefs
    this->ACoef = y0-y1;// finds A coef
    this->BCoef = x1-x0;// finds B coef
    this->CCoef = (x0*y1) - (x1*y0);// find C coef
}

float Equation::solveXImp(int impY){
    //x intersection
    int xImp = 0;
    
    //Solve for X with given coefficients
    xImp = -1 * ((BCoef*impY) + CCoef);
    xImp /= ACoef;
    
    return xImp;
}















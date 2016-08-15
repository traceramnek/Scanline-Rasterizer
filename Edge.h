//
//  Edge.h
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/17/16.
//  Copyright © 2016 Kwan Holloway. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

#include <stdio.h>
#include <iostream>
#include "Vertex.h"
#include "Equation.h"


class Edge{
public:
    
    Vertex startPoint, endPoint; // start and endpints for the edge
    Equation eqtn; // Equation of the edge
    //constructors
    Edge();
    Edge(Vertex srt, Vertex end);
    
    void printEdge(); // prints edge
    
};

#endif /* Edge_h */

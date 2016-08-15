//
//  main.cpp
//  ScanlineRaster
//
//  Created by Kwan Holloway on 4/9/16.
//  Copyright (c) 2016 Kwan Holloway. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include "vertex.h"
#include "edge.h"
#include "equation.h"
#include "scanlinerasterizer.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    ScanlineRasterizer r(atoi(argv[1]), atoi(argv[2]));
    r.rasterize(argv[3]);
    r.print();

    return 0;
    
}
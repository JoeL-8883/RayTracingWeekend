//
//  color.h
//  
//
//  Created by Joe Lee on 24/12/2022.
//  3.3 Color Utility Functions

#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"

#include <iostream>

void write_color(std::ostream &out, color pixel_color) {
    out << static_cast<int>(255.999 * -pixel_color.x()*1.5) << ' '
        << static_cast<int>(255.999 * -pixel_color.y()*1.5) << ' '
        << static_cast<int>(255.999 * -pixel_color.z()*1.5) << '\n';
}

#endif /* color_h */

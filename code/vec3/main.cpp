//
//  main.cpp
//  RayTracingWeekend
//
//  Created by Joe Lee on 24/12/2022.
//

#include "color.h"

#include <iostream>

int main() {

    // Image - increased dimensions for clarity and to show how the process indicator works
    const int image_width = 720;
    const int image_height = 720;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    
    // Iterate each pixel
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            
            // std::flush - immediately output in each loop instead of outputting simultaneously
            std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            color pixel_color(double(i)/(image_width-1), double(j)/image_height-1, 0.25);
            write_color(std::cout, pixel_color);
        }
    }
    
    std::cerr << "\nDone.\n";
}

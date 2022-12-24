//
//  main.cpp
//  RayTracingWeekend
//
//  Created by Joe Lee on 24/12/2022.
//

#include <iostream>

int main() {

    // Image

    const int image_width = 256;
    const int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    
    // Iterate each pixel
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            
            // Change slightly colour in each loop
            auto r = double(i) / (image_width-1);
            auto g = (double(j) / (image_height-1))/2;
            auto b = 0.5;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}

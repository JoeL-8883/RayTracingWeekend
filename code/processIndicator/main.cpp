//
//  main.cpp
//  RayTracingWeekend
//
//  Created by Joe Lee on 24/12/2022.
//

#include <iostream>

// More graphical text based progress bar
void process(int scanLines, int renderedLines) {
    int percentage = renderedLines/scanLines;
    int position = percentage*50;
    int remaining = 50-position;
    printf("\r%3d%% [%.*s%*s]",
           percentage,
           position,
           "||||||||||||||||||||||||||||||||||||||||||||||||||",
           remaining,
           "");
    
    fflush(stdout);
}
 
int main() {

    // Image - increased dimensions for clarity and to show how the process indicator works
    const int image_width = 720;
    const int image_height = 720;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    
    // Iterate each pixel
    for (int j = image_height-1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            
            // Process indicator
            // std::flush - immediately output in each loop instead of outputting simultaneously
            //std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
            process(j, image_width);
            
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
    
    std::cerr << "\nDone.\n";
}

#include "ray.h"
#include <iostream>

int main() {
    // Test code to print out the equation of the ray
    vec3 direction(1,2,3);
    vec3 origin(0,0,0);

    ray test_ray(origin, direction);
    std::cout << test_ray << std::endl;
}
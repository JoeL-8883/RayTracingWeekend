#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {}
        // Instantiate a ray
        // A point in a ray is given by
        // P = Origin + constant*direction
        ray(const point3& origin, const vec3& direction) {
            orig = origin;
            dir = direction;
        }

        // Return the point at the given constant t
        point3 at(double t) const {
            return orig + t*dir;
        }

        point3 origin() const { return orig; }
        vec3 direction() const { return dir; }
    public:
        point3 orig;
        vec3 dir;
    
};

#endif
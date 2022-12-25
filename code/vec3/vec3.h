//
//  vec3.h
//
//
//  Created by Joe Lee on 24/12/2022.
//  3.1 Variables and Methods
//  3.2 Vector utility functions

#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
public:
	vec3() {}

    // Instantiate vec3
	vec3(float e0, float e1, float e2) {
        e[0]=e0;
        e[1]=e1;
        e[2]=e2;
    }
	
    // Return components
	inline float x() const {return e[0];}
	inline float y() const {return e[1];}
	inline float z() const {return e[2];}
	inline float r() const {return e[0];}
	inline float g() const {return e[1];}
	inline float b() const {return e[2];}

    // Return vector
	inline const vec3& operator+() const {return *this;}

    // Return negation of vector
	inline vec3 operator-() const {return vec3(-e[0],-e[1],-e[2]);}

    // Return the ith component
	inline float operator[](int i) const {return e[i];}
	inline float& operator[](int i) {return e[i];}
	
	inline vec3& operator+=(const vec3 &v2); // add two vectors
	inline vec3& operator-=(const vec3 &v2); // subtract two vectors
	inline vec3& operator*=(const vec3 &v2); // multiply two vectors
	inline vec3& operator/=(const vec3 &v2); // divide two vectors
	inline vec3& operator*=(const float t);  // scale a vector
	inline vec3& operator/=(const float t); // divide by some constant
	
	inline float length() const {return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);} // Euclidean distance of a vector
	inline float length_squared() const {return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];}
	inline void make_unit_vector(); // normalise the vector
	
	float e[3];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

// Print the vector
inline std::istream& operator>>(std::istream &is, vec3 &t) {
 is >> t.e[0] >> t.e[1] >> t.e[2];
 return is;
}

// Set the values of a vector
inline std::ostream& operator<<(std::ostream &os, vec3 &t) {
 os << t.e[0] << " " << t.e[1] << " " << t.e[2];
 return os;
}

inline void vec3::make_unit_vector() {
 float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
 e[0] *= k; e[1] *= k; e[2] *= k;
}

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
 return vec3(v1.e[0]+v2.e[0],v1.e[1]+v2.e[1],v1.e[2]+v2.e[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) {
 return vec3(v1.e[0]-v2.e[0],v1.e[1]-v2.e[1],v1.e[2]-v2.e[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
 return vec3(v1.e[0]*v2.e[0],v1.e[1]*v2.e[1],v1.e[2]*v2.e[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2) {
 return vec3(v1.e[0]/v2.e[0],v1.e[1]/v2.e[1],v1.e[2]/v2.e[2]);
}

inline vec3 operator*(float t, const vec3 &v) {
 return vec3(t*v.e[0],t*v.e[1],t*v.e[2]);
}

inline vec3 operator/(float t, const vec3 &v) {
 return vec3(t/v.e[0],t/v.e[1],t/v.e[2]);
}

inline vec3 operator/(const vec3 &v, float t) {
 return vec3(v.e[0]/t,v.e[1]/t,v.e[2]/t);
}

// Dot produdt
inline float dot(const vec3 &v1, const vec3 &v2) {
	return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}

// Cross product
inline vec3 cross(const vec3 &v1, const vec3 &v2) {
	return vec3(v1.e[1]*v2.e[2] - v1.e[2]*v2[1], 
	-(v1.e[0]*v2.e[2] - v1.e[2]*v2[0]), 
	v1.e[0]*v2.e[1] - v1.e[1]*v2[0]);
}

inline vec3& vec3::operator+=(const vec3 &v) {
 e[0] += v.e[0];
 e[1] += v.e[1];
 e[2] += v.e[2];
 return *this;
}

inline vec3& vec3::operator-=(const vec3 &v) {
 e[0] -= v.e[0];
 e[1] -= v.e[1];
 e[2] -= v.e[2];
 return *this;
}

inline vec3& vec3::operator*=(const vec3 &v) {
 e[0] *= v.e[0];
 e[1] *= v.e[1];
 e[2] *= v.e[2];
 return *this;
}

inline vec3& vec3::operator/=(const vec3 &v) {
 e[0] /= v.e[0];
 e[1] /= v.e[1];
 e[2] /= v.e[2];
 return *this;
}

inline vec3& vec3::operator*=(const float t) {
 e[0] *= t;
 e[1] *= t;
 e[2] *= t;
 return *this;
}

inline vec3& vec3::operator/=(const float t) {
 float k = 1.0/t;
 e[0] /= k;
 e[1] /= k;
 e[2] /= k;
 return *this;
}

inline vec3 unit_vector(vec3 v) {
 return v / v.length();
}

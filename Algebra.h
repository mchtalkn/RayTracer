//
// Created by Selin Yıldırım on 13.11.2021.
//

#ifndef GIT_ALGEBRA_H
#define GIT_ALGEBRA_H
#include <iostream>
#include "parser.h"
#include "ppm.h"
using namespace parser;
Vec3f operator +(Vec3f lhs, Vec3f& rhs);
Vec3f operator -(Vec3f lhs, Vec3f& rhs);
Vec3f operator *(Vec3f lhs, float rhs);
Vec3f operator *(float lhs, Vec3f& rhs);
float dotProduct(Vec3f& lhs, Vec3f& rhs);
Vec3f crossProduct(Vec3f& lhs, Vec3f& rhs);
Vec3f hadamardProduct(Vec3f& lhs, Vec3f& rhs);
float determinant(Vec3f& v1, Vec3f& v2, Vec3f& v3);
Vec3f normalize(Vec3f& v);


#endif //GIT_ALGEBRA_H

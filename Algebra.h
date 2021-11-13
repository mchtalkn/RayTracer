//
// Created by Selin Yıldırım on 13.11.2021.
//
#include <iostream>
#include "parser.h"
#include "ppm.h"
using namespace parser;
#ifndef GIT_ALGEBRA_H
#define GIT_ALGEBRA_H

Vec3f operator +(Vec3f lhs, Vec3f rhs);
Vec3f operator -(Vec3f lhs, Vec3f rhs);

float dotProduct(Vec3f , Vec3f);
float crossProduct(Vec3f , Vec3f);



#endif //GIT_ALGEBRA_H

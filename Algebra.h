//
// Created by Selin Yıldırım on 13.11.2021.
//
#pragma once

#include <iostream>
#include "parser.h"
#include "ppm.h"
#include <cmath> // for sqrt in Algebra.cpp


#ifndef GIT_ALGEBRA_H
#define GIT_ALGEBRA_H

#define LOG_ERR(message) cout << endl << message << endl;


using namespace parser;

Vec3f operator +(Vec3f lhs, const Vec3f& rhs);
Vec3f operator -(Vec3f lhs, const Vec3f& rhs);
Vec3f operator *(Vec3f lhs, float rhs);
Vec3f operator /(Vec3f lhs, float rhs);
Vec3f operator *(float lhs, const Vec3f& rhs);
float calculateDistance(const Vec3f& source, const Vec3f& destination);
float dotProduct(const Vec3f& lhs, const Vec3f& rhs);
Vec3f crossProduct(const Vec3f& lhs, const Vec3f& rhs);
Vec3f hadamardProduct(const Vec3f& lhs, const Vec3f& rhs);
float determinant(const Vec3f& v1, const Vec3f& v2, const Vec3f& v3);
Vec3f& normalize(Vec3f& v);


#endif //GIT_ALGEBRA_H

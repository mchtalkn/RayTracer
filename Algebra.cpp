//
// Created by Selin Yıldırım on 13.11.2021.
//
#include "Algebra.h"

Vec3f operator+(Vec3f lhs, Vec3f& rhs)
{
	// TODO: insert return statement here
	Vec3f r;
	r.x = lhs.x + rhs.x;
	r.y = lhs.y + rhs.y;
	r.z = lhs.z + rhs.z;
	return r;
}

Vec3f operator-(Vec3f lhs, Vec3f& rhs)
{
	return Vec3f();
}

Vec3f operator*(Vec3f lhs, float rhs)
{
	return Vec3f();
}

Vec3f operator*(float lhs, Vec3f& rhs)
{
	return Vec3f();
}

float dotProduct(Vec3f& lhs, Vec3f& rhs)
{
	return 0.0f;
}

Vec3f crossProduct(Vec3f& lhs, Vec3f& rhs)
{
	return Vec3f();
}

Vec3f hadamardProduct(Vec3f& lhs, Vec3f& rhs)
{
	return Vec3f();
}

float determinant(Vec3f v1, Vec3f v2, Vec3f v3)
{
	return 0.0f;
}

Vec3f& normalize(Vec3f& v)
{
	// TODO: insert return statement here
}


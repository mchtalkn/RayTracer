//
// Created by Selin Yıldırım on 13.11.2021.
//
#include "Algebra.h"

Vec3f operator+(Vec3f lhs, Vec3f rhs)
{
	// TODO: insert return statement here
	Vec3f r;
	r.x = lhs.x + rhs.x;
	r.y = lhs.y + rhs.y;
	r.z = lhs.z + rhs.z;
	return r;
}

Vec3f operator-(Vec3f lhs, Vec3f rhs)
{
	return Vec3f();
}

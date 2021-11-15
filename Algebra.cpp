//
// Created by Selin Yıldırım on 13.11.2021.
//
#include "Algebra.h"

using namespace std;
#define LOG_ERR(message) cout << endl << message << endl;

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
    Vec3f r;
    r.x = lhs.x - rhs.x;
    r.y = lhs.y - rhs.y;
    r.z = lhs.z - rhs.z;
    return r;
}

Vec3f operator*(Vec3f lhs, float rhs)
{
    Vec3f r;
    r.x = lhs.x * rhs;
    r.y = lhs.y * rhs;
    r.z = lhs.z * rhs;
    return r;
}

Vec3f operator*(float lhs, Vec3f& rhs)
{
    Vec3f r;
    r.x = lhs * rhs.x;
    r.y = lhs * rhs.y;
    r.z = lhs * rhs.z;
    return r;
}

float dotProduct(Vec3f& lhs, Vec3f& rhs)
{
    float r = lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z ;
	return r;
}

Vec3f crossProduct(Vec3f& lhs, Vec3f& rhs)
{
    Vec3f r;
    r.x= lhs.y*rhs.z - lhs.z*rhs.y ;
    r.y= lhs.z*rhs.x - lhs.x*rhs.z ;
    r.z= lhs.x*rhs.y - lhs.y*rhs.x ;
    return r;
}

Vec3f hadamardProduct(Vec3f& lhs, Vec3f& rhs)
{
    Vec3f r;
    r.x= lhs.x*rhs.x ;
    r.y= lhs.y*rhs.y ;
    r.z= lhs.z*rhs.z ;
    return r;
}

float determinant(Vec3f& v1, Vec3f& v2, Vec3f& v3)
{
    float r = v1.x*v2.y*v3.z  -  v1.x*v2.z*v3.y  -  v1.y*v2.x*v3.z  +  v1.y*v2.z*v3.x  +  v1.z*v2.x*v3.y  -  v1.z*v2.y*v3.z ;
    return r;
}

Vec3f normalize(Vec3f& v)
{
    float norm = sqrt (v.x*v.x + v.y*v.y + v.z*v.z) ;
    if(!norm){
        LOG_ERR("Norm is zero while normalizing. Quitting here.")
        return v;
    }
    v.x= v.x/norm ;
    v.y= v.y/norm ;
    v.z= v.z/norm ;
    return v;
}


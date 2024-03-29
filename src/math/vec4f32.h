#pragma once

#ifdef __ARM_NEON
#include "sse2neon.h"
#else
#include <emmintrin.h>
#include <smmintrin.h>
#endif

class Vec4i32;
struct Vec4f32 {
    Vec4f32();
    Vec4f32(float val);
    Vec4f32(float a, float b, float c, float d);
    Vec4f32(__m128 a);
    
    Vec4i32 to_int_nearest() const;
    Vec4i32 to_int_round_down() const;

    Vec4f32 normalized() const;
    Vec4f32 min(float val) const;
    Vec4f32 max(float val) const;
    Vec4f32 clamp(float min, float max) const;
    Vec4f32 modf1() const;

    float x() const;
	float y() const;
	float z() const;
	float w() const;
    
    float dot(const Vec4f32& rhs) const;

    float operator[](int index) const;

    Vec4f32 operator+(const Vec4f32& rhs) const;
    Vec4f32 operator*(const Vec4f32& rhs) const;
    Vec4f32 operator/(const Vec4f32& rhs) const;
private:
    union { 
        __m128 _mf;
        float _xyzw[4];
    };
};

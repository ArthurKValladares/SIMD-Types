#pragma once

#ifdef __ARM_NEON
#include "sse2neon.h"
#else
#include <emmintrin.h>
#include <smmintrin.h>
#endif

struct Vec4f32;
struct Vec4i32 {
    Vec4i32();
    Vec4i32(int a, int b, int c, int d);
    Vec4i32(int a);
    Vec4i32(__m128i a);
    
    Vec4f32 to_float() const;
    
    int x() const;
	int y() const;
	int z() const;
	int w() const;

    bool any_gte(int val) const;
    
    int operator[](int index) const;

    Vec4i32 operator*(const int& rhs) const;

    Vec4i32 operator+(const Vec4i32& rhs) const;
    Vec4i32 operator-(const Vec4i32& rhs) const;
    Vec4i32 operator*(const Vec4i32& rhs) const;
    
    void operator+=(const Vec4i32& rhs);
    void operator-=(const Vec4i32& rhs);
    void operator*=(const Vec4i32& rhs);
    
    Vec4i32 operator&(const Vec4i32& rhs) const;
    Vec4i32 operator|(const Vec4i32& rhs) const;
    Vec4i32 operator^(const Vec4i32& rhs) const;
    Vec4i32 operator!() const;
    
    Vec4i32 operator==(const Vec4i32& rhs) const;
    Vec4i32 operator>(const Vec4i32& rhs) const;
    Vec4i32 operator<(const Vec4i32& rhs) const;
    Vec4i32 operator>=(const Vec4i32& rhs) const;
    Vec4i32 operator<=(const Vec4i32& rhs) const;
private:
    union {
        __m128i _mi;
        int _xyzw[4];
    };
};

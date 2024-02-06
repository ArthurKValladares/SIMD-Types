#include "vec4i32.h"
#include "vec4f32.h"

#include <utility>

Vec4i32::Vec4i32() {}

Vec4i32::Vec4i32(int a, int b, int c, int d) {
    _mi = _mm_set_epi32(d, c, b, a);
}

Vec4i32::Vec4i32(int a) {
    _mi = _mm_set1_epi32(a);
}

Vec4i32::Vec4i32(__m128i a) {
    _mi = std::move(a);
}

Vec4f32 Vec4i32::to_float() const {
    return Vec4f32(_mm_cvtepi32_ps(_mi));
}

int Vec4i32::x() const {
    return _xyzw[0];
}
int Vec4i32::y() const {
    return _xyzw[1];
}
int Vec4i32::z() const {
    return _xyzw[2];
}
int Vec4i32::w() const {
    return _xyzw[3];
}

bool Vec4i32::any_gte(int val) const {
    return this->x() >= val ||
           this->y() >= val ||
           this->z() >= val ||
           this->w() >= val;
}

int Vec4i32::operator[](int index) const {
    return _xyzw[index];
}

Vec4i32 Vec4i32::operator*(const int& rhs) const {
    return *this * Vec4i32(rhs);
}

Vec4i32 Vec4i32::operator+(const Vec4i32&rhs) const {
    return Vec4i32(_mm_add_epi32(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator-(const Vec4i32&rhs) const {
    return Vec4i32(_mm_sub_epi32(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator*(const Vec4i32& rhs) const {
    return Vec4i32(_mm_mullo_epi32(_mi, rhs._mi));
}

void Vec4i32::operator+=(const Vec4i32&rhs) {
    _mi = (*this + rhs)._mi;
}
void Vec4i32::operator-=(const Vec4i32&rhs) {
    _mi = (*this - rhs)._mi;
}
void Vec4i32::operator*=(const Vec4i32& rhs) {
    _mi = (*this * rhs)._mi;
}

Vec4i32 Vec4i32::operator&(const Vec4i32& rhs) const {
return Vec4i32(_mm_and_si128(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator|(const Vec4i32& rhs) const {
    return Vec4i32(_mm_or_si128(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator^(const Vec4i32& rhs) const {
    return Vec4i32(_mm_xor_si128(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator!() const {
    return *this ^ Vec4i32(0xffff);
}

Vec4i32 Vec4i32::operator==(const Vec4i32& rhs) const {
    return Vec4i32(_mm_cmpeq_epi32(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator>(const Vec4i32& rhs) const {
    return Vec4i32(_mm_cmpgt_epi32(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator<(const Vec4i32& rhs) const {
    return Vec4i32(_mm_cmplt_epi32(_mi, rhs._mi));
}
Vec4i32 Vec4i32::operator>=(const Vec4i32& rhs) const {
    return !(*this < rhs);
}
Vec4i32 Vec4i32::operator<=(const Vec4i32& rhs) const {
    return !(*this > rhs);
}

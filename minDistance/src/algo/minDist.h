#ifndef MINDIST_H
#define MINDIST_H
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "src/objects/Point2D.h"
#include <cmath>
#include <vector>
#define NUMBER 10000
using namespace std;

struct pt {
    int x, y, id;
    inline bool cmp_x (const pt & a, const pt & b);
    inline bool cmp_y (const pt & a, const pt & b);
};


inline bool cmp_x (const pt & a, const pt & b);

inline bool cmp_y (const pt & a, const pt & b);
inline void updAns (const pt & a, const pt & b);
void rec (int l, int r);

std::vector<Point2D> mainf (std::vector<Point2D> set);

#endif // MINDIST_H

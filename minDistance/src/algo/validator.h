#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <stdlib.h>
#include <time.h>
#include "src/objects/Point2D.h"
#include "src/algo/minDist.h"
#include <vector>
#include <set>

#define TEST_SIZE 10000

class Validator
{
public:

    static int test_size;
    std::vector<Point2D> ans;
    std::vector<Point2D> points;
    void generate();
    void min_dist();
    void test();
    Validator();

};
#endif

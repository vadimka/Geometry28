#include "validator.h"

int Validator::test_size = TEST_SIZE;
int Validator::srand_nmbr = SRAND_NMBR;

Validator::Validator()
{
}


void Validator::generate()
{
    //srand ( time(NULL) );
    srand ( srand_nmbr );
    int a, b;
    std::set <Point2D> point_set;
    for(int i = 0; i < this->test_size; i++)
    {
        //*for Win
        a = (rand() - 16000) * (rand() - 16000);
        b = (rand() - 16000) * (rand() - 16000);

    //    a = (rand() - RAND_MAX / 2) % 100000000;
      //  b = (rand() - RAND_MAX / 2) % 100000000;

        point_set.insert(Point2D (a, b));
      //  printf("%d %d\n", a, b);
    }
    std::set<Point2D>::iterator it;
    for(it = point_set.begin(); it != point_set.end(); ++it)
    {
        points.push_back(*it);
    }

}

void Validator::min_dist()
{
     this->ans = mainf(this->points);
}

void Validator::test()
{
    std::cout << "O(n^2) ";
    bust(this->points);

}

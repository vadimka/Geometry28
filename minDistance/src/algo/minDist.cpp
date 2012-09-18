#include <src/algo/minDist.h>
using namespace std;


static pt A[NUMBER];
static pt B[NUMBER];

inline bool cmp_x (const pt & a, const pt & b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

inline bool cmp_y (const pt & a, const pt & b) {
    return a.y < b.y;
}

static double minDist;
static int ansA[NUMBER], ansB[NUMBER];
static int nmbr = 0;

inline void updAns (const pt & a, const pt & b) {

    double dist = sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + .0);

    if ( dist == minDist ) {
        nmbr++;
        ansA[nmbr] = a.id;
        ansB[nmbr] = b.id;
    }
    if (dist < minDist) {
        minDist = dist;
        nmbr = 0;
        ansA[nmbr] = a.id;
        ansB[nmbr] = b.id;
    }
}

void rec (int l, int r) {
    if (r - l <= 3) {
        for (int i=l; i<=r; ++i)
            for (int j=i+1; j<=r; ++j)
                updAns (A[i], A[j]);
        sort (A+l, A+r+1, &cmp_y);
        return;
    }

    int m = (l + r) >> 1;
    int midx = A[m].x;
    rec (l, m),  rec (m+1, r);
    static pt t[NUMBER];
    merge (A+l, A+m+1, A+m+1, A+r+1, t, &cmp_y);
    copy (t, t+r-l+1, A+l);

    int tsz = 0;
    for (int i=l; i<=r; ++i)
        if (abs (A[i].x - midx) < minDist) {
            for (int j=tsz-1; j>=0 && A[i].y - t[j].y < minDist; --j)
                updAns (A[i], t[j]);
            t[tsz++] = A[i];
        }
}

std::vector<Point2D>  mainf (std::vector<Point2D> set) {

    int N = set.size();

    for (int i=0; i<N; i++) {
        A[i].x = set[i].getX();
        A[i].y = set[i].getY();
        A[i].id = i+1;
    }

    minDist = 9e307;
    sort (A, A+N, &cmp_x);
    rec (0, N-1);
    cout << "minDist: " << minDist << endl;
    std::vector<Point2D> result;

    for (int i=0; i <= nmbr; i++) {
        result.push_back(set[ansA[i] - 1]);
        result.push_back(set[ansB[i] - 1]);
     //   cout << "Точка№" << ansA[i] << " Точка№" << ansB[i] << endl;
    }

    return result;

}

void bust (std::vector<Point2D> set) {

    int N = set.size();

    minDist = 9e307;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
         updAns (A[i], A[j]);
        }
    }

    cout << "minDist = " << minDist << endl;

}

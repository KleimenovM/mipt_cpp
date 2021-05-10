#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::pow;

const unsigned int MAX_POINTS = 100;

struct Route {
    char source[20];
    char destination[20];
    double length;
    unsigned int n_points;
    double x_points[MAX_POINTS];
    double y_points[MAX_POINTS];
    bool is_correct_geometry;
};

void check_geometry(Route* r){
    long double dist, surf_len = 0;
    for (int i = 0; i < r->n_points - 1; i++){
        dist = std::sqrt(pow(r->x_points[i] - r->x_points[i+1], 2) + pow(r->y_points[i] - r->y_points[i+1], 2));
        surf_len += dist;
    }

    if (std::fabs(r->length - surf_len) >= pow(10, -6))
        r->is_correct_geometry = false;
    else
        r->is_correct_geometry = true;
}


int main()
{
    Route r;
    cin >> r.source >> r.destination >> r.n_points >> r.length;
    for (int i = 0; i < r.n_points; ++i) {
        cin >> r.x_points[i] >> r.y_points[i];
    }

    check_geometry(&r);
    cout << boolalpha << r.is_correct_geometry << endl;
    return 0;
}


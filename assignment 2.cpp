
#include <iostream>
#include <string>
#include< cstdlib > 
#include <time.h>
#include "cluster.h"

using namespace std;

void Centre(point c[], int n, float& cx, float& cy);
string cfit(point c1[], int nc1, point c2[], int nc2, point p);
void Centre(point c[], int n);

int main() {
    srand(time(NULL));

    float q = 0, q2 = 0;
    point* ca, * cb, m[20];
    int na, nb;

    cout << "Enter the number of points in cluster A: " << endl;
    cin >> na;
    cout << "Enter the number of points in cluster B: " << endl;
    cin >> nb;
    //filling clusters a and b with random numbers 
    ca = new point[na];
    for (int i = 0; i < na; i++) {
        ca[i].set_x(20 * ((float)rand() / RAND_MAX) + 70);

        ca[i].set_y(20 * ((float)rand() / RAND_MAX) + 70);
    }

    cb = new point[nb];
    for (int i = 0; i < nb; i++) {
        cb[i].set_x(20 * ((float)rand() / RAND_MAX) + 20);
        cb[i].set_y(20 * ((float)rand() / RAND_MAX) + 20);
    }
    //Genreating 20 random numbers to use in testing the cluster fit function(cfit)
    for (int i = 0; i < 20; i++)
    {
        m[i].set_x(95 * ((float)rand() / RAND_MAX) + 5);
        m[i].set_y(95 * ((float)rand() / RAND_MAX) + 5);
        cout << i << " " << cfit(ca, na, cb, nb, m[i]) << endl;

    }
    //deleting cluster a and b 
    delete [] ca;
    delete [] cb;

    return 0;
}
//Centre function, returining results as an outpout
void Centre(point c[], int n) {
    float sumx = 0, sumy = 0, cx, cy;
    //looping over each class object getting sum of x and y
    for (int i = 0; i < n; i++)
    {
        sumx = sumx + c[i].get_x();
        sumy = sumy + c[i].get_y();
    }
    cx = sumx / n;
    cy = sumy / n;

    cout << "The centre of the given points is " << "(" << cx << "," << cy << ")" << endl;
    return;
}
//overloaded form of centre function to return centre using pass by refrence 
void Centre(point c[], int n, float& cx, float& cy) {
    float sumx = 0, sumy = 0;
    for (int i = 0; i < n; i++)
    {
        sumx = sumx + c[i].get_x();
        sumy = sumy + c[i].get_y();
    }
    cx = sumx / n;
    cy = sumy / n;

    // cout << "The centre of the given points is " << "(" << cx << "," << cy << ")" << endl;
    return;
}

//cluster fit function
string cfit(point c1[], int nc1, point c2[], int nc2, point p)
{
    float  c1x = 0, c2x = 0, c1y = 0, c2y = 0;
    // using centre function from above to get centre of each cluster 
    Centre(c1, nc1, c1x, c1y);
    Centre(c2, nc2, c2x, c2y);

    //using class function disttop to get distance between point and centre if each cluster
    float dc1 = p.disttop(c1x, c1y);
    float dc2 = p.disttop(c2y, c2y);
    //returning the results as string
    if (dc1 > dc2)
        return "Point  belongs to cluster 2";
    else if (dc1 < dc2)
        return "Point belongs to cluster 1";
    else
        return "Point has equal distances from centre of cluster 1 and cluster 2";
}


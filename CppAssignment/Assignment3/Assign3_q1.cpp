// Quesiton 1 Dodging bullets
#include <iostream>

using namespace std;
int n;
int m;

struct bullet
{
    int posit_x;
    int posit_y;
    short dir_x;
    short dir_y;

    //constructor
    bullet(int px, int py, short dx, short dy) : posit_x(px), posit_y(py), dir_x(dx), dir_y(dy) {}
    bullet();
};

void print_map(int *);

/*
*  set_map
*  To set the unsafety point into 1.
*/
void set_map(bullet const &b, int map[])
{
    for (int i = b.posit_x, j = b.posit_y; i >= 0 && j >= 0 && i < n && j < m; i += b.dir_x, j += b.dir_y)
    {
        map[i * m + j] = 1;
    }
}

/*
* return number of safety point
*/
int get_safty_point(int map[])
{
    int count = 0;
    for (int i = 0; i < n * m; i++)
        if (map[i] == 0)
            count++;
    return count;
}

// For testing use.
void print_map(int map[])
{
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
            cout << map[i * m + j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int k;
    cin >> n >> m >> k;   // input the first three number
    int map[n * m] = {0}; // initalize the map

    bullet b = bullet(0, 0, 0, 0);
    for (int i = 0; i < k; i++)
    {
        cin >> b.posit_x;
        cin >> b.posit_y;
        cin >> b.dir_x;
        cin >> b.dir_y;
        set_map(b, map);
    }
    cout << get_safty_point(map);
}
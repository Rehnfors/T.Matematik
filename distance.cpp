#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x0, y0, x1, y1;
    cout << "Enter the coordinates of the starting point (latitude and longitude): ";
    cin >> x0 >> y0;
    cout << "Enter the coordinates of the ending point (latitude and longitude): ";
    cin >> x1 >> y1;

    double distance = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)) * 111320;
    cout << "The distance between the two points is: " << distance << " meters" << endl;

    int t0_hours, t0_minutes, t0_seconds, t1_hours, t1_minutes, t1_seconds;
    cout << "Enter the time of the starting point (hours minutes seconds): ";
    cin >> t0_hours >> t0_minutes >> t0_seconds;
    cout << "Enter the time of the ending point (hours minutes seconds): ";
    cin >> t1_hours >> t1_minutes >> t1_seconds;

    int time_difference = (t1_hours - t0_hours) * 3600 + (t1_minutes - t0_minutes) * 60 + (t1_seconds - t0_seconds);
    double speed = distance / time_difference * 3.6;
    cout << "The speed between the two points is: " << speed << " km/h" << endl;

    return 0;
}
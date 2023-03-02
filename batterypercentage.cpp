#include <iostream>
using namespace std;

int main() {

  float capacity = 300; // in mAh
  float voltage_full = 3.7; // in V
  float voltage_now = 3.2; // in V
  float energy_full = (capacity * voltage_full) / 1000; // in Wh
  float energy_now = (capacity * voltage_now) / 1000; // in Wh
  float remaining = (energy_now / energy_full) * 100; // as a percentage
  cout << "Remaining battery capacity: " << remaining << "%" << endl;

  return 0;
}
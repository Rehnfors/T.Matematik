#include <iostream>
using namespace std;

int main() {
    int ppg_data[] = {10, 15, 20, 25, 20, 15, 10, 5, 10, 15, 20, 25, 30, 25, 20, 15};
    int num_data_points = sizeof(ppg_data) / sizeof(ppg_data[0]);
    int adc_value = 0;
    int heart_rate_bpm = 0;
    int heart_rate_count = 0;

    // loop through the PPG data
    for (int i = 1; i < num_data_points; i++) {
        // calculate the difference between adjacent data points
        int diff = ppg_data[i] - ppg_data[i-1];
        // if the difference is positive and above a threshold, increment the heart rate count
        if (diff > 0 && diff > 5) {
            heart_rate_count++;
        }
    }

    // Combining the heart_rate_count and num_data_points to represent
    // amount of heartbeats and the amount of elements in the array.
    adc_value = heart_rate_count << 10 | num_data_points;

    //Multiply by 60 to convert from beats per second to beats per minute
    //Dividing it back to the original format
    heart_rate_bpm = adc_value * 60 / 1024;

    // check if the heart rate falls within a reasonable range
    while (heart_rate_bpm > 50 && heart_rate_bpm < 200) 
    {
     // output the heart rate to the console
        cout << "Heart rate: " << heart_rate_bpm << " bpm" << endl;
    }

    return 0;
}
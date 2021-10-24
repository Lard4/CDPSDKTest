#include <thread>
#include <iostream>
#include <GPS.h>
#include <Duck.h>

using namespace std;

int main() {
   Duck* testDuck = new Duck();
   GPS* gps = testDuck->startGPS(5);

   for (int i = 0; i < 5; i++) {
      // take a reading
      GPSReadings readings = gps->getAllReadings();

      // print our the data
      cout << "GPS reading #" << i << endl;
      cout << "\tLatitude: " << readings.latitude << endl;
      cout << "\tLongitude: " << readings.longitude << endl;
      cout << "\tTimestamp: " << readings.hours << ":" << readings.minutes << ":" << readings.seconds << endl;
      cout << "\tEpoch milliseconds: " << readings.timeMillis << endl << endl;

      // sleep for 3 seconds
      this_thread::sleep_for(chrono::seconds(3));
   }

   cout << "done";

   return 0;
}
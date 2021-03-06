// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Vision2              vision        2               
// Motor12              motor         12              
// Motor20              motor         20              
// Drivetrain           drivetrain    4, 11           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

double pi = acos(-1);
int degreeBlock = 600;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  double x, y;
  double z = 0;
  int l, r, distanceMoved;
  while (true) {
    l = LeftDriveSmart.position(deg);
    r = RightDriveSmart.position(deg);
    distanceMoved = -(l + r)/2/degreeBlock;
    x = distanceMoved*sin(z);
    y = distanceMoved*cos(z);
    z = ((l - r) / 2) % 1080/**pi*/ / 540; // remember to multiply by pi later
    Brain.Screen.setCursor(6, 6);
    Brain.Screen.print("%d %d %d\n%f %f %f", l, r, distanceMoved, x, y, z);
  }
}
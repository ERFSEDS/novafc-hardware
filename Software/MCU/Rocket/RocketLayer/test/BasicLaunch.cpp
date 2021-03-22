#include "LayerTester.hpp"

int main() {
  RocketLayerTester tester("resources/TestData.csv");
  if(tester.runSimulation()) {
    return 0;//success
  }
  return 1; //fail
}

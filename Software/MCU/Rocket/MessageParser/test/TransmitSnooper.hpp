#pragma once
#include <string>
#include <cinttypes>
//This is used to snoop and read the transmit callback when i expect a transmission
//This is a simplified thing for testing it wont work if you have multiple threads all logging
class TransmitSnooper {
public:
  TransmitSnooper(bool active, void* handoffContext, void (*transmit_callback)(void*, std::string));
  void snoop(bool snooping);
  static void snoopCallback(void* context, std::string msg);
  void setExpectedResponse(uint8_t * msg, size_t size);
  bool matchedExpected();
private:
  bool snooping;
  bool messageMatch;
  void* context;
  void (*transmit_callback)(void*, std::string);
  void snoop_callback_i(std::string msg);
  uint8_t *expectedMsg;
  size_t expectedSize;
};

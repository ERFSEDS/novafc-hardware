#include "Common.hpp"


float getFloat(uint8_t * floatBytes, int offset) {
  uint32_t bytes = (floatBytes[offset] << 24) +
    (floatBytes[offset+1] << 16) +
    (floatBytes[offset+2] << 8 ) +
    (floatBytes[offset+3]);
  return *(reinterpret_cast<float*>(&bytes));
}
void setFloat(float valueF, uint8_t * ptr, int offset) {
  uint32_t* value = reinterpret_cast<uint32_t*>(&valueF);
  ptr[offset] = (*value & (0xFF << 24)) >> 24;
  ptr[offset+1]=(*value & (0xFF << 16)) >> 16;
  ptr[offset+2]=(*value & (0xFF << 8)) >> 8;
  ptr[offset+3]=*value & (0xFF);
}

#include "custom_stream.h"
#include <Arduino.h>

#define BUFFER_INCREMENTS 128

CustomStream::CustomStream()
{
    this->_len = 0;
    this->_buffer = (char*)malloc(BUFFER_INCREMENTS);
}

size_t CustomStream::write(uint8_t byte) {
  if(this->_len+1 > this->buffer_size) {
    // grow
    auto tmp = (char*)realloc(this->_buffer, this->buffer_size+BUFFER_INCREMENTS);
    if(tmp == NULL) {
      // failed to grow buffer due to memory error
      Serial.println("Failed to grow buffer");
      return 0;
    }
    this->_buffer = tmp;
    this->buffer_size += BUFFER_INCREMENTS;
  }
  this->_buffer[this->_len] = byte;
  this->_len++;
  return 1;
}

void CustomStream::flush() {
  this->_len=0;
  // shrink
  this->_buffer = (char*)realloc(this->_buffer, BUFFER_INCREMENTS);
  this->buffer_size = BUFFER_INCREMENTS;
}

int CustomStream::read() {
  return 0;
}

int CustomStream::peek() {
  return 0;
}

int CustomStream::available() {
  return 1;
}
#ifndef CustomStream_h
#define CustomStream_h
#include <Arduino.h>
#include <Stream.h>

class CustomStream : public Stream
{
private:
   uint16_t _len;
   uint16_t buffer_size;
   // buffer pointer
   char* _buffer;


public:
  // public methods
  CustomStream();
  ~CustomStream() {
    free(this->_buffer);
  }

  operator const uint8_t *() const { return NULL; }
  operator const char *() const { return (const char*)NULL; }

  const uint16_t current_length() const { return _len; }

  bool listen() { return true; }
  void end() {}
  bool isListening() { return true; }
  int peek();

  virtual size_t write(uint8_t byte);
  virtual int read();
  virtual int available();
  virtual void flush();

  const char* get_buffer() const { return _buffer; }

  // get string
  const char* get_string() const { 
    // Null terminate
    _buffer[_len] = '\0';
    return _buffer;
  }

  using Print::write;
};
#endif
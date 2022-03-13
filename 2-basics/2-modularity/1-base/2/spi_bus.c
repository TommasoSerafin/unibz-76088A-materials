#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool is_in_error;
bool is_idle;
void init() {
}
void send(uint8_t *buffer, size_t len) {
  if (len > 0 && is_idle) {
    printf("Sending: ");
    for (size_t i = 0; i < len; ++i) {
      printf("%x ", (unsigned int)buffer[i]);
      // or alternatively
      // printf("%x ", (unsigned int)*(buffer + i));
    }
    printf("\n");
  }
}
void deinit() {
}
void foo() {
}

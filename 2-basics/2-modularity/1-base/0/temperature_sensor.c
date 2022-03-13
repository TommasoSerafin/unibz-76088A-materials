#include <stdbool.h>
#include <stdint.h>

bool is_in_error;
bool is_idle;
void init() {
}
int16_t get_current_temperature() {
  if (is_idle) {
    return 0;
  }
  return INT16_MIN;
}
void deinit() {
}

void foo() {
}

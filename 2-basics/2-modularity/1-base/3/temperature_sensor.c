#include <stdbool.h>
#include <stdint.h>

bool is_in_error;
bool is_idle;
void temperature_sensor_init() {
}
int16_t temperature_sensor_get_current_temperature() {
  if (is_idle) {
    return 0;
  }
  return INT16_MIN;
}
void temperature_sensor_deinit() {
}

void temperature_sensor_foo() {
}

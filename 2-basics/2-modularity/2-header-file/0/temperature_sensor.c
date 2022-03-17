#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int temperature_sensor_error_number = 0;
static bool is_idle = true;
void temperature_sensor_init() {
}
int16_t temperature_sensor_get_current_temperature() {
  if (is_idle) {
    is_idle = false;
    int temperature;
    printf("Please insert the temperature> ");
    scanf("%d", &temperature);
    is_idle = true;
    return temperature;
  }
  return INT16_MIN;
}
void temperature_sensor_deinit() {
}

static void foo() {
}

#include <stdint.h>

#include <stdbool.h>
#include <stdio.h>

bool is_in_error;

void init();
int16_t get_current_temperature();
void send(uint8_t *buffer, size_t len);

int main(int argc, char *argv[]) {
  // How should I invoke the init of temperature_sensor and the init of spi_bus?
  init();
  init();

  while (1) {
    int16_t temperature = get_current_temperature();
    // How to use the is_in_error of temperature_sensor?
    if (is_in_error) {
      printf("Temperature_sensor error\n");
    } else {
      send((uint8_t *)&temperature, sizeof(int16_t));
    }
    // How to use the is_in_error of spi_bus?
    if (is_in_error) {
      printf("SPI bus error\n");
    }
  }
}

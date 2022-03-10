#include <stdint.h>

int main(int argc, char *argv[]) {
  // How should I invoke the init of temperature_sensor and the init of spi_bus?
  init();
  init();

  while (1) {
    int16_t temperature = get_current_temperature();
    send((uint8_t *)&temperature, sizeof(int16_t));
  }
}

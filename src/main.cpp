#include "settings.h"
#include <Led.hpp>
#include <avr/io.h>

led::Led Led(&LED_PORT, LED_PIN);

ISR(TIMER1_COMPA_vect) { Led.toggle(); }

int main() {
  setup_timer1();

  while (1) {
  }
}

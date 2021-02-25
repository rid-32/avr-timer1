#define F_CPU 12000000UL

#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include <avr/interrupt.h>
#include <avr/io.h>

#define LED_PORT PORTA
#define LED_PIN 3

inline void setup_timer1() {
  /* disable global interrupt */
  cli();

  /* set up CTC and clk/256 */
  TCCR1A &= ~(1 << WGM10 | 1 << WGM11);
  TCCR1B |= (1 << CS12 | 1 << WGM12);
  TCCR1B &= ~(1 << CS10 | 1 << CS11 | 1 << WGM13);

  /* compare every 500 millis */
  OCR1A = F_CPU / (256 * 2);

  /* clear counter */
  TCNT1 = 0;

  /* enable interruption by compare */
  TIMSK |= (1 << OCIE1A);

  /* enable global interrupt */
  sei();
}

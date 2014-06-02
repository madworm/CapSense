#include <stdint.h>

// 50Hz AC not good

// sense_a: 15 / PC1
// store_a: 14 / PC0
// sense_b: 19 / PC5 
// store_b: 18 / PC4

const uint8_t moving_average_data_length = 10;

int16_t moving_average_data[moving_average_data_length] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

int16_t moving_average = 0;
uint8_t moving_average_index = 0;

int main(void)
{
	init();			// arduino internals
	discharge_cap_a();
	discharge_cap_b();
	Serial.begin(115200);
	int16_t cycle_counter_a = 0;
	int16_t cycle_counter_b = 0;
	int16_t delta = 0;

	for (;;) {

		// check against (cycle_counter_X == 0) to avoid 50Hz AC problems
		// not an issue if battery powered (e.g. laptop with NO power-supply connected)
		// but if the board is not floating anymore, AC hum causes the high-impedance
		// inputs to trigger prematurely

		cli();
		while (!(PINC & _BV(PC1)) || (cycle_counter_a == 0)) {
			DDRC &= ~(_BV(PC0) | _BV(PC1));	// store_a and sense_a as inputs
			PORTC |= _BV(PC1);	// sense_a pull-up on
			DDRC |= _BV(PC1);	// sense_a as output (high)
			// delayMicroseconds(1);
			DDRC &= ~_BV(PC1);	// sense_a as input (pull-up on)
			PORTC &= _BV(PC1);	// sensa_a pull-up off
			DDRC |= _BV(PC0);	// store_a as output (low)                    
			cycle_counter_a++;
		}
		sei();

		Serial.print("cycle_counter_a: ");
		Serial.print(cycle_counter_a);
		Serial.print(" - ");
		discharge_cap_a();

		cli();
		while (!(PINC & _BV(PC5)) || (cycle_counter_b == 0)) {
			DDRC &= ~(_BV(PC4) | _BV(PC5));	// store_b and sense_b as inputs
			PORTC |= _BV(PC5);	// sense_b pull-up on
			DDRC |= _BV(PC5);	// sense_b as output (high)
			// delayMicroseconds(1);
			DDRC &= ~_BV(PC5);	// sense_b as input (pull-up on)
			PORTC &= _BV(PC5);	// sensa_b pull-up off
			DDRC |= _BV(PC4);	// store_b as output (low)                    
			cycle_counter_b++;
		}
		sei();

		Serial.print("cycle_counter_b: ");
		Serial.print(cycle_counter_b);
		Serial.print(" - ");
		discharge_cap_b();

		delta = cycle_counter_a - cycle_counter_b;
		Serial.print("delta: ");
		Serial.print(delta);

		Serial.print(" index: ");
		Serial.print(moving_average_index);

		moving_average_data[moving_average_index] = delta;
		moving_average_index = (moving_average_index + 1) % moving_average_data_length;

		moving_average = moving_average_calc();
		Serial.print(" - mavg: ");
		Serial.print(moving_average);

		Serial.print(" - delta2: ");
		Serial.println(moving_average - delta);

		cycle_counter_a = 0;
		cycle_counter_b = 0;

		delay(1);
	}
}

void discharge_cap_a(void)
{
	PORTC &= ~(_BV(PC0) | _BV(PC1));	// set LOW
	DDRC |= (_BV(PC0) | _BV(PC1));	// set as output
	delayMicroseconds(50);
	DDRC &= ~(_BV(PC0) | _BV(PC1));	// set as input
}

void discharge_cap_b(void)
{
	PORTC &= ~(_BV(PC4) | _BV(PC5));	// set LOW
	DDRC |= (_BV(PC4) | _BV(PC5));	// set as output
	delayMicroseconds(50);
	DDRC &= ~(_BV(PC4) | _BV(PC5));	// set as input
}

int16_t moving_average_calc(void)
{
	uint8_t ctr;
	int16_t sum = 0;
	for (ctr = 0; ctr < moving_average_data_length; ctr++) {
		sum += moving_average_data[ctr];
	}
	return sum / moving_average_data_length;
}

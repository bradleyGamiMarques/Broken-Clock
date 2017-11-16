// Broken Clock
// Bradley Marques
#include <bitset>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
// Other include files?
using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::set;
void SetClockArray(bitset<8> led_clock_numbers[10]);
void main() {
	ifstream fin("led.in");
	if (fin.is_open()) {
		ofstream fout("led.out");

		// Main part of program goes here.  Use fin and fout for input and output.
		// May also use cout statements for debugging purposes.

		// This is an architectural choice. The input will be integers
		// but since the numbers are so small I believe shorts will be
		// an appropriate data type to use.
		const short TEN = 10;
		short number_to_read = 0;
		bitset<8> broken_leds;
		bitset<10> have_seen;
		bitset<8> led_clock_numbers[TEN];
		bitset<8> temp;
		bitset<8> temp_storage[TEN];
		set<short>::iterator it;
		set<short>storage_set[TEN];


		SetClockArray(led_clock_numbers);
		fin >> number_to_read;
		while (number_to_read > 0) {
			broken_leds.set();
			broken_leds.flip(0);
			bool first_time_in_case = true;
			bool first_time_in_set = true;
			
			while (number_to_read > 0) {
				// What we are reading in from file are the led numbers that are broken
				// We need to keep track of those numbers somehow because they will be
				// used in the output
				broken_leds[number_to_read] = 0;
				fin >> number_to_read;

			}
			cout << "Case <";
			fout << "Case <";
			for (short index = 1; index < 8; index++) {
				// The led is broken
				if (broken_leds[index] == 0) {
					if (first_time_in_case) {
						first_time_in_case = false;
					}
					else {
						cout << ',';
						fout << ',';
					}
					cout << index;
					fout << index;
				}

			}
			cout << ">:";
			fout << ">:";

			for (short index = 0; index < 10; index++) {
				temp = broken_leds & led_clock_numbers[index];
				temp_storage[index] = temp;
				for (short counter = 0; counter < 10; counter++) {
					if (temp_storage[index] == (broken_leds & led_clock_numbers[counter])) {
						storage_set[index].insert(counter);
					}
				}
			}

			have_seen.reset();
			// Process what we got and then go through the while loop again.
			for (short i = 0; i < 10; i++) {
				if (storage_set[i].size() > 1 && have_seen[i] == 0) {
					cout << " {";
					fout << " {";
					for (auto x : storage_set[i]) {
						if (first_time_in_set) {
							first_time_in_set = false;
						}
						else {
							cout << ',';
							fout << ',';
						}
						have_seen.set(x);
						cout << x;
						fout << x;
					}
					cout << "}";
					fout << "}";
				}
				first_time_in_set = true;
			}
			cout << endl;
			fout << endl;
			for (short index = 0; index < 10; index++) {
				storage_set[index].clear();
				temp_storage[index].reset();
			}
			fin >> number_to_read;
		}
		

		fout.close();
		fin.close();
	}
	else {
		cout << "Input file not found." << endl;
	}
}
// The following function takes a sized bitset array as input. The function 
// sets the bits in the bitset at the corresponding array slot to 1's and 0's
// based on the following diagram. The function returns no values.

/*******************************************
*            1                             *
*            _                             *
*          2| |3                           *
*                                          *
*            4                             *
*			 _                             *
*                                          *
*          5|_|6                           *
*            7                             *
*******************************************/
void SetClockArray(bitset<8> led_clock_numbers[10])
{
	// Read all bitsets from right to left. Position 0 is the right most bit.
	// Position 0 will always be zero. It does not correspond to any leds.
	for (short index = 0; index < 10; index++) {
		switch (index) {
		case 0:
			// 11101110
			led_clock_numbers[0].set();
			led_clock_numbers[0].flip(0);
			led_clock_numbers[0].flip(4);
			break;
		case 1:
			// 01001000
			led_clock_numbers[1].set();
			led_clock_numbers[1].flip(0);
			led_clock_numbers[1].flip(1);
			led_clock_numbers[1].flip(2);
			led_clock_numbers[1].flip(4);
			led_clock_numbers[1].flip(5);
			led_clock_numbers[1].flip(7);
			break;
		case 2:
			// 10111010
			led_clock_numbers[2].set();
			led_clock_numbers[2].flip(0);
			led_clock_numbers[2].flip(2);
			led_clock_numbers[2].flip(6);
			break;
		case 3:
			// 11011010
			led_clock_numbers[3].set();
			led_clock_numbers[3].flip(0);
			led_clock_numbers[3].flip(2);
			led_clock_numbers[3].flip(5);
			break;
		case 4:
			// 01011100
			led_clock_numbers[4].set();
			led_clock_numbers[4].flip(0);
			led_clock_numbers[4].flip(1);
			led_clock_numbers[4].flip(5);
			led_clock_numbers[4].flip(7);
			break;
		case 5:
			// 11010110
			led_clock_numbers[5].set();
			led_clock_numbers[5].flip(0);
			led_clock_numbers[5].flip(3);
			led_clock_numbers[5].flip(5);
			break;
		case 6:
			// 11110110
			led_clock_numbers[6].set();
			led_clock_numbers[6].flip(0);
			led_clock_numbers[6].flip(3);
			break;
		case 7:
			// 01001010
			led_clock_numbers[7].set();
			led_clock_numbers[7].flip(0);
			led_clock_numbers[7].flip(2);
			led_clock_numbers[7].flip(4);
			led_clock_numbers[7].flip(5);
			led_clock_numbers[7].flip(7);
			break;
		case 8:
			// 11111110
			led_clock_numbers[8].set();
			led_clock_numbers[8].flip(0);
			break;
		case 9:
			// 01011110
			led_clock_numbers[9].set();
			led_clock_numbers[9].flip(0);
			led_clock_numbers[9].flip(5);
			led_clock_numbers[9].flip(7);
			break;
		}
	}
}

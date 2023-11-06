#include "Header.h"
#include <iostream>

using namespace std;

char set_start_key() {
	char keys_start = ' ';
	cout << "Key to launch auto clicker (type in capitals) : ";
	cin >> keys_start;
	return keys_start;
}
char set_end_key() {
	char keys_end = ' ';
	cout << "Key to stop auto clicker (type in capitals) : ";
	cin >> keys_end;
	return keys_end;
}
int set_click() {
	int click=0;
	cout << "Type '0' to assign autoclick to right click and '1' to assign it to left click : ";
	cin >> click;
	return click;
}
int set_cps() {
	int cps=0;
	cout << "Enter cps value : ";
	cin >> cps;
	return cps;
}
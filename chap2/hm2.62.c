int int_shifts_are_arithmetic(void) {
	int x = -1; // 0b11...1
	int y = x >> 1; // 0b11..1 if arithmetic shift, else 0b01..1
	return x == y ? 1 : 0;
}

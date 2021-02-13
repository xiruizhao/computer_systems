/*
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x) {
    x |= x >> 1; // repeatedly reduce gaps of 0s.
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16; // now 0b0...011...1
    x ^= x >> 1;
    return x;
}

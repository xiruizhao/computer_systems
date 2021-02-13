/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32 */
int odd_ones(unsigned x) {
    // xor reduces pairs of 1s to 0
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 1; // extract least significant bit
    return x;
}

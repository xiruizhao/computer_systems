/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/*
 * Compute (int) f.
 * If conversion causes overflow or f is NaN, return 0x80000000
 */
int float_f2i(float_bits f) {
    unsigned e = (f << 1) >> 24;
    if (e == 0) {
        // denormalized
        return 0;
    } else if (e == 255) {
        // Inf and NaN
        return 0x80000000;
    } else {
        // normalized
        int s = f >> 31; // sign
        int E = e - (1 << 7) + 1; // exponent
        int res; // result
        unsigned il1 = 1 << 23; // implied leading 1
        if (E < 0) {
            return 0;
        } else if (E <= 23) {
            res = ((f << 9 >> 9) | il1) >> (23 - E);
        } else if (E <= 31) {
            res = ((f << 9 >> 9) | il1) << (E - 23);
        } else {
            return 0x80000000;
        }

        if (s == 0) {
            return res;
        } else {
            return ~res + 1;
        }
    }
}

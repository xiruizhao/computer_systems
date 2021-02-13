/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Compute (float) i */
float_bits float_i2f(int i) {
    // always normalzed representation, except 0
    unsigned s_mask, j, k;
    if (i > 0) {
        s_mask = 0;
        k = j = i;
    } else if (i == 0) {
        return 0;
    } else {
        s_mask = 1 << 31;
        k = j = ~i + 1; // -x -> x
    }
    int E = -1;
    while (j != 0) {
        j >>= 1;
        E++;
    }
    int e_mask = (E + (1 << 7) - 1) << 23;
    if (E >= 23) {
        return s_mask | e_mask | (k >> (E - 23) << 9 >> 9);
    } else {
        return s_mask | e_mask | (k << (32 - E) >> 9);
    }
}

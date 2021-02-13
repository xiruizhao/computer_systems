/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Compute 2*f. If f is NaN, then return f. */
float_bits float_twice(float_bits f) {
    unsigned e = (f << 1) >> 24;
    if (e == 0) {
        // denormalized
        unsigned s_e_mask = (f >> 23 << 23);
        if ((f & (1 << 22)) == 0) {
            return s_e_mask | (f << 10 >> 9);
        } else {
            // convert to normalized
            return s_e_mask | (f << 9 >> 8);
        }
    } else if (e == 255) {
        // Inf and NaN
        return f;
    } else {
        // normalized
        e += 1;
        unsigned s_mask = f >> 31 << 31;
        if (e == 255) {
            // overflow to Inf
            return s_mask | (e << 23);
        } else {
            return s_mask | (e << 23) | (f << 9 >> 9);
        }
    }
}

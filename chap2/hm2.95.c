/* Access bit-level representation floating-point number */
typedef unsigned float_bits;

/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
    unsigned e = (f << 1) >> 24;
    if (e == 0) {
        // denormalized
        return (f >> 23 << 23) | (f << 9 >> 10);
    } else if (e == 255) {
        // Inf and NaN
        return f;
    } else {
        // normalized
        e -= 1;
        unsigned s_mask = f >> 31 << 31;
        if (e == 0) {
            // convert to denormalized
            return s_mask | (f << 1 >> 2);
        } else {
            return s_mask | (e << 23) | (f << 9 >> 9);
        }
    }
}

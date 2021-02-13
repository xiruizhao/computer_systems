unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    unsigned mask = (1 << (8*sizeof(int) - k)) - 1;
    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    int mask = (1 << (8*sizeof(int) - k)) - 1;
    if (x >= 0) {
        return xsrl & mask;
    } else {
        return xsrl | ~mask;
    }
}

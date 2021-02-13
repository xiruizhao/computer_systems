int signed_high_prod(int x, int y);

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    int w = 8*sizeof(unsigned);
    return signed_high_prod(x, y) +  (x >> (w - 1))* y + x * (y >> (w - 1));
}

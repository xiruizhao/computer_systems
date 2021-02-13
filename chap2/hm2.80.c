int threefourths(int x) {
    if (x >= 0) {
        // (3/4) rounded toward zero is |_(3/4)x_| when x >= 0.
        // |_ (3/4)x _| = |_x/2_| + |_(x+1)/4_|
        unsigned u = x;
        return (u >> 1) + ((u + 1) >> 2);
    } else {
        // (3/4)x rounded toward zero is symmetrical about origin, i.e., f(-x) = -f(x). 
        unsigned u = ~x + 1; // x -> -x, including INT_MIN
        int f_x = (u >> 1) + ((u + 1) >> 2); // 0 <= f_x <= INT_MAX
        return ~f_x + 1;
    }
}

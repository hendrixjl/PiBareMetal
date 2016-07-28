inline unsigned int make_mask(unsigned start_bit, unsigned bit_count)
{
    unsigned int temp = (1 << bit_count) - 1;
    return (temp << start_bit);
}

inline unsigned int get_bit_pattern(unsigned int data, unsigned start_bit, unsigned bit_count)
{
    unsigned int temp = data & make_mask(start_bit, bit_count);
    return (temp >> start_bit);
}

inline unsigned int set_bit_pattern(unsigned int data, unsigned int pattern, unsigned start_bit, unsigned bit_count)
{
    unsigned temp = data & ~make_mask(start_bit, bit_count);
    return temp | (pattern << start_bit);
}


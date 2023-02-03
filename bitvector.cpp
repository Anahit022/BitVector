#include <iostream>
#include <cmath>

class BitVector
{
public:
	BitVector(int size) :size_bit(size) {
		num_bits = (size_bit + 63) / 64;
		bits = new unsigned int[num_bits];
		for (int i = 0; i < num_bits; ++i) {
			bits[i] = 0;
		}
	}

	~BitVector() {
		delete[] bits;
	}

	void set(int index) {
		if (index < 0 || index >= size_bit) return;
		bits[index / 64] |= 1 << (index % 64);
	}

	void reset(int index) {
		if (index < 0 || index >= size_bit) return;
		bits[index / 64] &= ~(1 << (index % 64));
	}

	bool get(int index) const {
		if (index < 0 || index >= size_bit) return false;
		return bits[index / 64] & (1 << (index % 64));
	}

private:
	int size_bit;
	int num_bits;
	unsigned int* bits;
};
int main()
{
	BitVector b(100);
	b.set(6);
	b.set(14);
	b.reset(6);
	return 0;
}
/* converter.h */
#ifndef CONVERTER_H
#define CONVERTER_H

#include "reference.h"

class Converter : public Reference {
    GDCLASS(Converter, Reference);

protected:
    static void _bind_methods();

public:
	PoolVector<uint8_t> float_array_to_byte_array(const PoolVector<float> &array);

	Converter();
};

#endif
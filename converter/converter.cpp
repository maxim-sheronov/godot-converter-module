/* converter.cpp */

#include "converter.h"

void Converter::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("float_array_to_byte_array", "array"), &Converter::float_array_to_byte_array);
}

PoolVector<uint8_t> Converter::float_array_to_byte_array(const PoolVector<float> &array)
{
	PoolVector<uint8_t> point_img;
	point_img.resize(array.size() * sizeof(float));
	{
		PoolVector<uint8_t>::Write iw = point_img.write();
		zeromem(iw.ptr(), array.size() * sizeof(float));
		PoolVector<float>::Read r = array.read();
		copymem(iw.ptr(), r.ptr(), array.size() * sizeof(float));
	}
	
	return point_img;
}

Converter::Converter()
{
}
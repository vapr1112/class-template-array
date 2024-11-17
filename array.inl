#include "array.h"

template <> class Array<T>::Array (const T* array_p, const int size_p) : Array{ new T * [size_p] }, size{ size_p }
{
	if (array_p)
	{
		for (int i = 0; i < size; i++)
		{
			Array[i] = array_p[i];
		}
	}
}
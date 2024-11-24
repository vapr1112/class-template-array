template <class T> Array<T>:: Array(const T* array_p, const int size_p) : mas{ new T[size_p] }, size{ size_p }
{
	if (array_p)
	{
		for (int i = 0; i < size; i++)
		{
			mas[i] = array_p[i];
		}
	}
}
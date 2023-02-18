#pragma once
#include"Simplex.h"
namespace OptLib
{
	template<class Stream, size_t dim>
	Stream& operator<<(Stream& o, const Point<dim>& p)
	{
		o << p[0];
		for (size_t i = 1; i < p.size(); ++i) {
			o << ", " << p[i];
		}
		return o;
	}
}


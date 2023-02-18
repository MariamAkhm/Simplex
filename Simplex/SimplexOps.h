#pragma once
#include <functional>
namespace OptLib
{
	namespace SimplexOps
	{
		namespace UnaryOps
		{
			template<class Scalar>
			struct plus
			{
				plus(Scalar value) : scalar{ value } {};
				template<class T = void>
				T operator()(const T& lhs)
				{
					return lhs + scalar;
				}
			protected:
				Scalar scalar;
			};
			template<class Scalar>
			struct minus
			{
				minus(Scalar value) : scalar{ value } {};
				template<class T = void>
				T operator()(const T& lhs)
				{
					return lhs - scalar;
				}
			protected:
				Scalar scalar;
			};
		}
		namespace BinaryOps
		{
			template<class T = void>
			using plus = std::plus<T>;
		}
	}
}


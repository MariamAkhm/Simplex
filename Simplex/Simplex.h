#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include<array>
#include"SimplexOps.h"
namespace OptLib
{
	template<size_t dim>
	using Point = std::array<double, dim>;
	template<size_t dim>
	Point<dim> operator+ (const Point<dim>& arr1, const Point<dim> arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(), arr2.begin(), result.begin(), std::plus<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator + (const Point<dim>& arr1, double consta)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(), result.begin(), SimplexOps::UnaryOps::plus<double>{consta });
		return result;
	}

	template<size_t dim>
	Point<dim> operator- (const Point<dim>& arr1, const Point<dim> arr2)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(), arr2.begin(), result.begin(), std::minus<>{});
		return result;
	}

	template<size_t dim>
	Point<dim> operator - (const Point<dim>& arr1, double consta)
	{
		Point<dim> result;
		std::transform(arr1.begin(), arr1.end(), result.begin(), SimplexOps::UnaryOps::minus<double>{consta });
		return result;
	}
	template<size_t dim>
	double operator* (const Point<dim>& arr1, const Point<dim> arr2)
	{
		Point<dim> result;
		double res = 0;
		std::transform(arr1.begin(), arr1.end(), arr2.begin(), std::back_inserter(result), std::multiplies<>{});
		for (auto& el : result)
			res += el;
		return res;
	}
	template<size_t dim>
	double operatorabs(const Point<dim>& arr1)
	{
		Point<dim> result;
		double res = 0;
		std::transform(arr1.begin(), arr1.end(), arr1.begin(), result.begin(), std::multiplies<>{});
		for (auto& el : result)
			res += el;
		return sqrt(res);
	}
	template <size_t dim>
	struct RawPoint {
		RawPoint() = default;
		Point <dim> P;
		RawPoint(const Point <dim>& P) noexcept : P{p} {}
		RawPoint(Point <dim>&& p) : P{ std::move(p) } {}; //move(перемещение) влияет только на стэк, в куче(хип) остается прежним
		// что стоит под мувом, после него нельзя использовать (забирает полностью "ресурс", потом нельзя использовать, его нет)
		double operator [] (size_t i) const { return P[i]; }
		operator Point <dim>() { return P };
	};
	template <size_t dim>
	struct PointVal : public RawPoint <dim>{
		double val;
		PointVal() = default;
		PointVal (Point <dim>&&P, double val):
			RawPoint<dim>{ std::move(p) }, val{ val } {};
		PointVal(const Point <dim>& P, double val) :
			newPoint<dim>{ P }, val{ val } {};
		bool operator < (const Point <dim> rhs) {
			return this->val < rhs.val;
		}
	};
	template <size_t dim>
	PointVal <dim> operator + (const PointVal<dim>& p1, const PointVal<dim>& p2) {
		return PointVal<dim> { p1.P + p2.P, p1.val + p2.val};
	}
}


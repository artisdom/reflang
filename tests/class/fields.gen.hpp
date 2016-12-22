// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! This file is auto-generated by Reflang. !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <string>
#include <type_traits>

#include "lib/reflang.hpp"

namespace reflang
{

template <>
class Class<MyClass> : public IClass
{
public:
	static const constexpr int FieldCount = 14;

	int GetFieldCount() const override
	{
		return FieldCount;
	}

	const std::string& GetName() const override
	{
		static const std::string name = "MyClass";
		return name;
	}

	// Calls T::operator() on each field of 'MyClass'.
	// Works well with C++14 generic lambdas.
	template <typename T>
	static void IterateFields(const MyClass& c, T t)
	{
		t(c.field);
		t(c.const_field);
		t(c.pointer_field);
		t(c.const_pointer_field);
		t(c.const_pointer_const_field);
		t(c.ref_field);
		t(c.const_ref_field);
		t(c.complex);
		t(c.const_complex);
		t(c.pointer_complex);
		t(c.const_pointer_complex);
		t(c.const_pointer_const_complex);
		t(c.ref_complex);
		t(c.const_ref_complex);
	}

	template <typename T>
	static void IterateFields(MyClass& c, T t)
	{
		t(c.field);
		t(c.const_field);
		t(c.pointer_field);
		t(c.const_pointer_field);
		t(c.const_pointer_const_field);
		t(c.ref_field);
		t(c.const_ref_field);
		t(c.complex);
		t(c.const_complex);
		t(c.pointer_complex);
		t(c.const_pointer_complex);
		t(c.const_pointer_const_complex);
		t(c.ref_complex);
		t(c.const_ref_complex);
	}
};

const int Class<MyClass>::FieldCount;


}  // namespace reflang

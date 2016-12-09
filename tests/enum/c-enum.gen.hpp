#include <cassert>
#include <string>

namespace reflang
{

template <typename T> class Enum;

template <>
struct Enum<CEnum>
{
	using EnumType = CEnum;

	struct ConstIterator
	{
		EnumType operator*() { return value_; }

		ConstIterator& operator++()
		{
			switch (value_)
			{
			case EnumType::Value0:
				value_ = EnumType::Value1;
				break;
			case EnumType::Value1:
				last_ = true;
				break;
			}
			return *this;
		}

		ConstIterator operator++(int)
		{
			auto tmp = *this;
			operator++();
			return tmp;
		}

		ConstIterator& operator--()
		{
			if (last_)
			{
				last_ = false;
				value_ = EnumType::Value1;
			}
			else
			{
				switch (value_)
				{
				case EnumType::Value0:
					assert(false);
					break;
				case EnumType::Value1:
					value_ = EnumType::Value0;
					break;
				}
			}
			return *this;
		}

		ConstIterator operator--(int)
		{
			auto tmp = *this;
			operator--();
			return tmp;
		}

		bool operator==(const ConstIterator& o) const
		{
			return ((last_ && o.last_) || (value_ == o.value_));
		}

		bool operator!=(const ConstIterator& o) const
		{
			return !(*this == o);
		}

		EnumType value_;
		bool last_ = true;
	};

	struct IteratorContainer
	{
		ConstIterator begin() const
		{
			ConstIterator it;
			it.last_ = false;
			it.value_ = EnumType::Value0;
			return it;
		}

		ConstIterator end() const
		{
			return ConstIterator();
		}
	};

	static IteratorContainer Iterate()
	{
		return IteratorContainer();
	}

	static bool TryTranslate(const std::string& s, EnumType& value)
	{
		if (s == "Value0")
		{
			value = EnumType::Value0;
			return true;
		}
		else if (s == "Value1")
		{
			value = EnumType::Value1;
			return true;
		}
		else
		{
			return false;
		}
	}

	static std::string Translate(EnumType e)
	{
		switch (e)
		{
			case EnumType::Value0:
				return "Value0";
				break;
			case EnumType::Value1:
				return "Value1";
				break;
		}
	}
};
}  // namespace reflang

#include <iostream>
#include <gtest/gtest.h>
#include <set>
#include <unordered_map>
#include <functional>

namespace CLE
{

class ivar
{

};

template <class T>
class var : public ivar
{
public:
	T value;

	var& operator=(const var& a)
	{
		value = a.value;
		return *this;
	}
	var& operator=(const T& a)
	{
		value = a;
		return *this;
	}
};


template <class T>
class ifunc
{
	std::set<ivar&> inputs;
	std::set<ivar&> outputs;
	std::function callable;
};

template <class T>
var<T> operator+(const var<T>& lhs, const var<T>& rhs)
{
	var<T> res;
	res.value = lhs.value + rhs.value;
	return res;
}



class engine
{
	std::set<CLE::ivar*> vars;
	std::unordered_map<CLE::ivar*, std::set<CLE::ivar*> > parents;
	std::unordered_map<CLE::ivar*, std::set<CLE::ivar*> > children;
};
}

TEST(CLE, test1)
{
	CLE::var<int> a;
	CLE::var<int> b;
	CLE::var<int> c;

	a = 1;
	b = 2;

	c = a + b;
	EXPECT_EQ(c.value, 3);
}

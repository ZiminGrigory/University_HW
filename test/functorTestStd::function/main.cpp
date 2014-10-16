#include <functional>
#include <iostream>
#include <QStringList>

class A
{
public:
	A(){}
	int foo( int x ,  QStringList const &l)
	{
		std::cout << "int test::foo(int,char) " << x << " "<< l.size() << "\n" ; return 9 ;
	}
	void foo1( int x ,  QStringList const &l)
	{
		std::cout << "int test::foo(int,char) " << x+ 10 << " "<< l.size() << "\n" ;
	}
};

template<typename Ret>
class FunctorInterface
{
public:
	virtual void startFunc() = 0;
	virtual Ret const result() = 0;
	virtual bool isReturnSmth(){return true;}
};

template <typename Target, typename Ret, typename... Args>
class NoVoidFunctor: public FunctorInterface<Ret>
{
public:
	NoVoidFunctor(Target* ptr, Ret (Target::*pfn)(Args...), Args&&... data)
		:FunctorInterface<Ret>(), mFunc(std::bind(pfn, ptr, std::forward<Args>(data)...)){}
	NoVoidFunctor(Target& ptr, Ret (Target::*pfn)(Args...), Args&&... data)
		:FunctorInterface<Ret>(), mFunc(std::bind(pfn, ptr, std::forward<Args>(data)...)){}
	void startFunc(){mRes = mFunc();}
	Ret const result(){return mRes;}
private:
	Ret mRes;
	std::function<Ret()> mFunc;
};

template <typename Target, typename Ret, typename... Args>
class VoidFunctor: public FunctorInterface<Ret>
{
public:
	VoidFunctor(Target* ptr, Ret (Target::*pfn)(Args...), Args&&... data)
		:FunctorInterface<Ret>(), mFunc(std::bind(pfn, ptr, std::forward<Args>(data)...)){}
	VoidFunctor(Target& ptr, Ret (Target::*pfn)(Args...), Args&&... data)
		:FunctorInterface<Ret>(), mFunc(std::bind(pfn, ptr, std::forward<Args>(data)...)){}
	void startFunc(){mFunc();}
	bool isReturnSmth(){return false;}
	Ret const result(){return;}
private:
	std::function<void()> mFunc;
};


int main()
{
	A a;
	const QStringList l = QStringList();
	FunctorInterface<int> *b = new NoVoidFunctor<A, int, int, const QStringList&>(&a, &A::foo, 7, l);
	b->startFunc();
	if (b->isReturnSmth()){
		std::cout << b->result() << std::endl;
	}
	FunctorInterface<void> *c = new VoidFunctor<A, void, int, const QStringList&>(&a, &A::foo1, 7, l);
	c->startFunc();
	if (c->isReturnSmth()){
		std::cout << "C->result()" << std::endl;
	}
}





/*
//template <typename Target, typename Ret, typename... Args>
//struct derived_void_functor
//{
//	~derived_void_functor(){}
//	derived_void_functor( Target* ptr, Ret (Target::*pfn)(Args...), Args&&... data)
//		:mFunc(std::bind(pfn, ptr, std::forward<Args>(data)...)){}

//	derived_void_functor( Target& ref, Ret (Target::*pfn)(Args...), Args&&... data)
//		:mFunc(std::bind(pfn, ref, std::forward<Args>(data)...)){}

//	void runOperator(){mFunc();}
//	bool returnSmth(){return false;}
//private:
//	std::function<void()> mFunc;
//};


//template <typename Target, typename Ret, typename... Args>
//struct derived_functor
//{
//	~derived_functor(){}
//	derived_functor( Target* ptr, Ret (Target::*pfn)(Args...), Args&&... data)
//		:mFunc(std::bind(pfn, ptr, std::forward<Args>(data)...)){}

//	derived_functor( Target& ref, Ret (Target::*pfn)(Args...), Args&&... data)
//		:mFunc(std::bind(pfn, ref, std::forward<Args>(data)...)){}

//	void runOperator(){res = mFunc();}
//	bool returnSmth(){return true;}
//	Ret result() const{return res;}

//private:
//	std::function<Ret()> mFunc;
//	Ret res;
//};

//template< typename T, typename R, typename... Args > inline
//derived_functor<T,R,Args...> make_fun(T* p,  R( T::*pmf)(Args...), Args&&... data)
//{
//	return derived_functor<T,R,Args...>(p, pmf, std::forward<Args>(data)...);
//}

//template< typename T, typename R, typename... Args > inline
//derived_functor<T,R,Args...> make_fun(T& r,  R( T::*pmf)(Args...), Args&&... data)
//{
//	return derived_functor<T,R,Args...>(r, pmf, std::forward<Args>(data)...);
//}

//template< typename T, typename R, typename... Args > inline
//derived_void_functor<T,R,Args...> make_void_fun(T* p,  R( T::*pmf)(Args...), Args&&... data)
//{
//	return derived_void_functor<T,R,Args...>(p, pmf, std::forward<Args>(data)...);
//}

//template< typename T, typename R, typename... Args > inline
//derived_void_functor<T,R,Args...> make_void_fun(T& r,  R( T::*pmf)(Args...), Args&&... data)
//{
//	return derived_void_functor<T,R,Args...>(r, pmf, std::forward<Args>(data)...);
//}
*/


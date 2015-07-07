#include <boost/shared_ptr.hpp>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace boost;


struct Foo
{
    Foo(int _x):x(_x){}
    ~Foo(){std::cout<<"Destructing a Foo with x="<<x<<std::endl;}
    int x;
};

typedef shared_ptr<Foo> FooPtr;

struct FooPtrOps
{
    bool operator()(const FooPtr &a,const FooPtr &b)
    {
        return a->x>b->x;
    }
    void operator()(const FooPtr &a)
    {
        std::cout<<a->x<<std::endl;
    }
};
int main()
{
    std::vector<FooPtr>   foo_vector;
    std::set<FooPtr,FooPtrOps>  foo_set;
    
    FooPtr foo_ptr(new Foo(2));
    foo_vector.push_back(foo_ptr);
    foo_set.insert(foo_ptr);
    
    foo_ptr.reset(new Foo(1));
    foo_vector.push_back(foo_ptr);
    foo_set.insert(foo_ptr);
    
     foo_ptr.reset(new Foo(3));
    foo_vector.push_back(foo_ptr);
    foo_set.insert(foo_ptr);
    
     foo_ptr.reset(new Foo(2));
    foo_vector.push_back(foo_ptr);
    foo_set.insert(foo_ptr);
    
    std::cout<<"foo_vector:\n";
    std::for_each(foo_vector.begin(),foo_vector.end(),FooPtrOps());
    
    std::cout<<"\nfoo_set:\n";
    std::for_each(foo_set.begin(),foo_set.end(),FooPtrOps());
    std::cout<<std::endl;
    return 0;
}


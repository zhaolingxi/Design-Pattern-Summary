#include <iostream>
#include <string>
#include <memory>
using namespace std;


class product
{
public:
    product() {};
    int val;
 
    virtual int GetVal() = 0;
    virtual void CoutVal() = 0;
};

class productA :public product
{
public:
    productA(int inum)
    {
        val = inum;
    };
    int GetVal() override
    {
        return val;
    }
    void CoutVal() override
    {
        cout << "productA val:" << GetVal() << endl;
    }
};

class productB :public product
{
public:
    productB(int inum)
    {
        val = inum;
    };
    int GetVal() override
    {
        return val;
    }

    void CoutVal() override
    {
        cout << "productB val:" << GetVal() << endl;
    }
};

class productC :public product
{
public:
    productC(int inum)
    {
        val = inum;
    };
    int GetVal() override
    {
        return val;
    }

    void CoutVal() override
    {
        cout << "productC val:" << GetVal() << endl;
    }
};

template  <class T>
class simple_factory
{
public:
    std::shared_ptr<T> CreatePrd(string istr)
    {
        int param = 0;
        if (istr == "A")
        {
            param = 1;
            return std::make_shared<productA>(productA(param));
        }
        else if (istr == "B")
        {
            param = 2;
            return std::make_shared<productB>(productB(param));
        }
        else if (istr == "C")
        {
            param = 3;
            return std::make_shared<productC>(productC(param));
        }
        else
        {
            return nullptr;
        }
    }

    product* CreatePrd1(string istr)
    {
        if (istr == "A")
        {
            return new productA(1);
        }
        else if (istr == "B")
        {
            return new productB(2);
        }
        else if (istr == "C")
        {
            return new productC(3);
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    simple_factory<product> FAC;
    auto pa=FAC.CreatePrd("A");
    auto pb = FAC.CreatePrd("B");
    auto pc = FAC.CreatePrd("C");

    if (pa && pb && pc)
    {
          pa->CoutVal();
          pb->CoutVal();
          pc->CoutVal();
    }
    getchar();
    
}
#pragma once
#include <cassert>
#include <iostream>

using namespace std;

typedef long long ll;

template <class type>
class Vector
{
    type* arr{ nullptr };
    ll size{ 0 };
    ll capacity{};

public:
    Vector(ll sz);
    ~Vector();
    void expand_capacity();
   
};


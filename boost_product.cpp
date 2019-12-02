#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std;

int128_t boost_product(long long a,long long b)
{
    int128_t ans=(int128_t)a*b;
    return ans;
}

int main()
{
    long long first = 98745636214564698; 
    long long second=7459874565236544789;
    cout<<boost_product(first,second);
    return 0;
}
#include <cstdio>
#include <boost/lexical_cast.hpp>

int main(void)
{
	printf("%d\n", boost::lexical_cast<int>("123"));
}

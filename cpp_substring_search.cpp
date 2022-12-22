#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
class c1
{
  public:
	 int c;
};
class aa
{
   int a;
   c1 *pc;
public:
	   aa(c1 *p)
	{
		pc = p;
		cout<<pc->c<<endl;	
	}
   
};
int main(int argc, char *argv[])
{
	c1 mc;
	mc.c = 34;
	aa ma(&mc);
	return 0;
}
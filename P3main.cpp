using namespace std;
#include <iostream>
#include "zDepthList.cpp"
int main() {
	int l[30];
	for (int i=0;i<30;i++) l[i]=i;
	cout << "Test";
	zDepthList z(l,30);
/*	z.out('f');
	z.move(10,2,'f');
	//z.out();
	z.move(14,3,'r');
	z.out('r');
	//z.movefront(4);
	//z.moveback(13);
	//z.out();
	cout << endl << endl;
	for (int i=0;i<30;i+=2) l[i]=28-i;
	zDepthList x(l,30);
	x.out('f');
	x.move(27,2,'f');
	//x.out();
	x.move(3,8,'r');
	x.out('r');
	//x.movefront(4);
	//x.moveback(13);
	//x.out();
	//x.addfront();
	//x.addback();
	//x.out();
#define bigsize 1000000
	int big[bigsize];
	for (int i=0;i<bigsize;i++) big[i]=i;
	zDepthList y(big,bigsize);
	//for (int i=0;i<bigsize;i+=2) y.moveback(i);
	//for (int i=0;i<bigsize;i+=3) y.movefront(i);
	//for (int i=1;i<bigsize;i+=3) y.move(i,4);
	for (int i=0;i<bigsize;i+=2) y.move(i,2,'r');
	//cout << y.at(6) << " " << y.at(bigsize-2) << endl;
*/
}

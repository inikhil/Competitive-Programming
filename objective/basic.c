#include <stdio.h>
void abc(int d){
    cout<<d<<" ";
}

	void main()
	{
	    int x = 97;
	    abc(x++);
	    printf("x is %d", x);
	}

#include <conio.h>

void print( const char* s )
{
	for ( ; *s != 0; s++ )
	{
		_putch( *s );
	}
}

void read( char* buf, int maxSize )
{
	const char* const pEnd = buf + maxSize;
	for ( char c = _getch(); c != 13 && buf + 1 < pEnd; c = _getch(), buf++ )
	{
		_putch( c );
		*buf = c;
	}
	*buf = 0;
}

int str2int( const char* s )
{ // did i give up too fast before i would have figured THAT out?
	int sum = 0;
	 	for ( ; *s >= '0' && *s <= '9'; s++ )
		 	{
		 		// shift entire sum left by one decimal place
			 		sum *= 10;
		 		// add in new lowest digit
			 		sum += *s - '0';
		 	}
	 	return sum;
}

void int2str( const int num, char* string )
{
	if ( num < 10 )
	{
		string[0] = num + '0';
		string[1] = 0;
	}
	else
	{
		int swap[69];
		int i = 0;
		for ( int tmp = num; tmp >= 10; i++ )
		{
			swap[i] = tmp % 10;
			tmp /= 10;
			if ( tmp < 10 )
			{
				swap[i + 1] = tmp;
			}
		}
		for ( int j = 0; j <= i; j++ )
		{
			string[j] = swap[i - j] + '0';
		}
		string[i + 1] = 0;
	}
}

int nfib( const int n )
{
	if ( n < 3 )
	{
		return n == 2 ? 1 : n;
	}
	int x[4] = { 1, 1, 0, 0 };
	for ( int i = 2; i <= n; i++ )
	{
		x[3]++;
		if ( x[3] == 1 )
		{
			x[2] = x[0] + x[1];
		}
		else if ( x[3] == 2 )
		{
			x[1] = x[0] + x[2];
			x[3] = -1;
		}
		else
		{
			x[0] = x[1] + x[2];
		}
	}
	return x[1 - x[3]];
}

int main()
{
	print( "Input Nth Fibonacci number to be found: " );
	char answer[69];
	read( answer, 69 );

	const int fibnum = nfib( str2int( answer ) );
	char string[69];
	int2str( fibnum, string );

	print( "\nNth Fibonacci is: " );
	print( string );

	while ( !_kbhit() );
	return 0;
}
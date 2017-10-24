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
{
	// scan to start point
	const char* p = s;
	for ( ; *p >= '0' && *p <= '9'; p++ );
		p--;

	int val = 0;
	int place = 1;

	// convert place values and accumulate
	for ( ; p >= s; p-- )
	{
		val += (*p - '0') * place;
		place *= 10;
	}
	return val;
}

void int2str( const int num, char* string )
{
	if ( num < 10 )
	{
		string[0] = num;
		string[1] = 0;
	}
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

int nfib( const int n )
{
	if ( n < 2 )
	{
		return n;
	}
	int x1 = n - 1;
	int x2 = n - 2;
	for ( int i = 2; i <= n; i++, x1++, x2++ )
	{
		x1 += x2;
	}
	return x1;
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
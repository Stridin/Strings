#include <conio.h>

void print( const char* s )
{
	for ( ; *s != 0; s++ )
	{
		_putch( *s );
	}
}

int main()
{
	const char msg[] = { 'P', 'u', 'b', 'e', 's', '!', 0 };
	print( msg );

	while ( !_kbhit() );
	return 0;
}
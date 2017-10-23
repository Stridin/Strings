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
	const char msg[7] = { 'P', 'u', 'b', 'e', 's', '!', 0 };
	const char msg2[7] = { "Pubes!" }; // never forget the size
	print( msg );
	print( msg2 );

	while ( !_kbhit() );
	return 0;
}
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
	char msg[] = { 'P', 'u', 'b', 'e', 's', '!', 0 };
	char msg2[] = { "Pubes!" };
	msg[0] = '#';

	const char* waifu = "MYWIFE"; // aint gonna work

	print( msg );
	print( msg2 );
	print( waifu );

	while ( !_kbhit() );
	return 0;
}
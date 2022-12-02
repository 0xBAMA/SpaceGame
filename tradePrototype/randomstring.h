#include <string>
using std::string;

string RandomString ( const int length ) {
	static const char alphanumerics[] =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string temp;
	temp.reserve( length );
	for ( int i = 0; i < length; ++i )
		temp += alphanumerics[ rand() % ( sizeof( alphanumerics ) - 1 ) ];

	return temp;
}

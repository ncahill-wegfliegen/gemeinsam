#include "crypt.h"

using namespace std;

// https://kylewbanks.com/blog/Simple-XOR-Encryption-Decryption-in-Cpp

namespace
{
constexpr const char* const key{ "Gu=" };
constexpr size_t key_length{ 3 };
}

string nhill::crypt::encrypt( string_view s )
{
	string output{ s };

	for( int i = 0; i < s.length(); i++ )
	{
		output[i] = s[i] ^ key[i % key_length];
	}

	return output;
}

string nhill::crypt::decrypt( string_view s )
{
	// To decrypt it, just run it through the encrypter.
	return encrypt( s );
}

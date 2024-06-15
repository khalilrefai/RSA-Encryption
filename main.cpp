#include <iostream>
#include <cmath>
#include <string>

int gcd(int a, int b)
{
	int t;
	while (1)
	{
		t = a % b;

		if (t == 0)
			return b;

		a = b;
		b = t;
	}
}

long long modExp(long long base, long long exponent, long long mod)
{
	long long result = 1;
	base = base % mod;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % mod;

		exponent = exponent >> 1;
		base = (base * base) % mod;
	}

	return result;
}

int main()
{
	// Random prime numbers
	long long p = 13;
	long long q = 11;

	// Compute n
	long long n = p * q;

	// Compute phi
	long long phi = (p - 1) * (q - 1);

	// Public key (e stands for encryption)
	long long e = 7;

	// For checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
	while (e < phi)
	{
		if (gcd(e, phi) == 1)
			break;
		else
			e++;
	}

	// Private key (d stands for decryption)
	// Choosing d such that it satisfies d * e ≡ 1 (mod phi)
	long long d = 0;
	for (long long k = 1; ; k++)
	{
		if ((k * phi + 1) % e == 0)
		{
			d = (k * phi + 1) / e;
			break;
		}
	}

	// Original message
	std::string message = "HELLO";
	std::cout << "Original Message = " << message << std::endl;

	// Encrypt the message
	std::string encrypted_message = "";
	for (char c : message)
	{
		long long m = static_cast<long long>(c);
		long long encrypted_char = modExp(m, e, n);
		encrypted_message += std::to_string(encrypted_char) + " ";
	}

	std::cout << "Encrypted message = " << encrypted_message << std::endl;

	// Decrypt the message
	std::string decrypted_message = "";
	size_t pos = 0;
	while ((pos = encrypted_message.find(' ')) != std::string::npos)
	{
		long long encrypted_char = stoll(encrypted_message.substr(0, pos));
		long long decrypted_char = modExp(encrypted_char, d, n);
		decrypted_message += static_cast<char>(decrypted_char);
		encrypted_message.erase(0, pos + 1);
	}

	std::cout << "Decrypted message = " << decrypted_message << std::endl;

	// Display RSA parameters
	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q << std::endl;
	std::cout << "n = pq = " << n << std::endl;
	std::cout << "phi = " << phi << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "d = " << d << std::endl;

	return 0;
}

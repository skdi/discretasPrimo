int createPrime(unsigned int n,int it_count){
	assert(it_count>0);
	BigInt res=createOddNum(n);
	while(!isPrime(res,it_count))
	{
		res.add(BigInt::Two);
	}
	return res;
}


unsigned int RandomNumber( unsigned int min, unsigned int max )
{
	return ( rand( ) % ( max - ( min - 1 ) ) ) + min;
}

bool RandomPrime( LargeInteger & p_Prime )
{
	// Error check the param value
	if( p_Prime.GetSize( ) == 0 )
	{
		return false;
	}

	// Randomize the first component, The last bit should be 1 and therefore,
	// we use the value 128 as the start value
	// We use the end value 254 because we don't want to overflow
	p_Prime.SetComponent( 0, RandomNumber( 128, 254 ) );

	// Randomly set the other ones
	for( unsigned int i = 1; i < p_Prime.GetSize( ); i++ )
	{
		p_Prime.SetComponent( i, RandomNumber( 0, 255 ) );
	}

	// Make the large integer odd
	if( p_Prime % (unsigned short)( 2 ) )
	{
		p_Prime++;
	}

	// Keep on looping until we find a prime
	// NOT SAFE
	while( 1 )
	{
		if( IsPrime( p_Prime ) )
		{
			return true;
		}

		p_Prime += 2;
	}

	// We did not find any prime.
	return false;
}


long Rsa::produce_prime()
{
	long prime = 0;
	srand(time(0));
	while (true)
	{
		prime = rand() % 100 + 100;
		if (is_prime(prime))
			break;
	}
	return prime;
}

bignum & Prime::generate_prime(const integer & length) {
	Numbers numbers;
	bignum * number = new BigUnsigned( numbers.random(length) );

	while ( !primality_test(*number, 4) )
		* number = numbers.random( length ); // or sth like: numbers.try_upgrading_to_prime( const bignum & number )

	return * number;
}

void GenPrime(BigInt& n, int digNum)
{
    int i = 0;
    BigInt divisor;
    const int length = sizeof(prime) / sizeof(int);
    while (i != length)
    {
        n.Random(digNum);
        while (!n.IsOdd())
            n.Random(digNum);
        i = 0;
        for ( ; i < length; i++)
        {
            divisor = prime[i];
            if ((n % divisor) == 0)
                break;
        }
    }
}

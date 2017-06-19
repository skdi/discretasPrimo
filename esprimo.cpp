

bool IsPrime( LargeInteger & p_Number )
{

	// Resource:
	// http://holmezideas.com/programming/optimization-techniques/fastest-algorithm-to-check-if-a-given-number-is-prime/

	if( p_Number <= (unsigned short)( 1 ) )
	{
		return false;
	}
	else if( p_Number == (unsigned short)( 2 ) )
	{
		return true;
	}
	else if( ( p_Number % (unsigned short)( 2 ) ) == 0 )
	{
		return false;
	}
	else
	{
		//float square_root = sqrt( static_cast< float >( number ) );
		LargeInteger square_root( p_Number.GetSize( ) / 2 );
		square_root = p_Number.Sqrt( );

		// Let's loop sqrt( number ) times and check if the number isn't a prime
		for( unsigned int i = 3; i <= square_root; i+=2 )
		{
			if( ( p_Number % (unsigned short)( i ) ) == 0 )
			{
				return false;
			}
		}
	}

	return true;
}

bool Rsa::is_prime(const long digit)
{
	int tmp = 2;
	while (tmp < digit)
		if (!(digit % tmp++))
			break;

	if (tmp == digit)
		return true;
	return false;
}

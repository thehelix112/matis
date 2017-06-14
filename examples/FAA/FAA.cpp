#if !defined(WIN32) && !defined(VXWORKS) && !defined(__KCC) && (__SUNPRO_CC_COMPAT != 5)
#  include <stream.h>
#else
#  include <iostream.h>
#endif

#include <string>
#include <stdlib.h>

#if !defined(WIN32) && !defined(VXWORKS)
#  include <unistd.h>
#endif


#include <RTI.hh>
#include <fedtime.hh>
#include "FAAFederateAmbassador.h"

// Statics
static std::string federationName = "XA";
static std::string federateName = "FAA";
static std::string federationFile = "MA.fed";

static int joinTries = 20;

void outputMessage( const char * msg );
void suspendExecution( const char * msg );
int federateProc( void * lpData );


int main( int argc, char *argv[] )
{
	if (argc > 1)
	{
		if (argc >= 2)
			federateName = argv[1];
		if (argc >= 3)
			federationName = argv[2];
		if (argc >= 4)
			federationFile = argv[3];
	}

	return federateProc(NULL);
}

void outputMessage( const char * msg )
{
	cout << "[" << federateName.c_str() << "]: " << msg << endl;
}

void suspendExecution( const char * msg )
{
	cout << "[FAA][suspend] " << msg << endl;
	char tempChar;
	cin >> tempChar;
}

int federateProc( void * lpData )
{
	// lookahead & timestep
	const RTIfedTime lookaheadTime(1);
	const RTIfedTime timestep(3);

	// ambassadors
	RTI::RTIambassador		rtiAmb;
	FAAFederateAmbassador	fedAmb;


	// Try and join federation execution
	std::string attempt = "ATTEMPT: Attempting to join federation ";
	attempt += federationName + " as: " + federateName;
	outputMessage( attempt.c_str() );

	bool joined = false;
	int numTries = 0;

	while(!joined && numTries < joinTries)
	{
		try
		{
			rtiAmb.joinFederationExecution( federateName.c_str(), federationName.c_str(), &fedAmb );
			joined = true;
			outputMessage( "SUCCESS: Join successful" );
		}
		catch (RTI::FederateAlreadyExecutionMember& e)
		{
			std::string msg = "ERROR: Federate ";
			msg += federateName;
			msg += " already  exists in Federation Execution";
			outputMessage( msg.c_str() );
			outputMessage( e._reason );
			return 1;
		}
		catch (RTI::FederationExecutionDoesNotExist&)
		{
			std::string msg = "ERROR: Federation Execution ";
			msg += federationName;
			msg += " does not exist.";
			outputMessage( msg.c_str() );
			rtiAmb.tick(2.0, 2.0);
		}
		catch( RTI::Exception & e )
		{
			outputMessage( "ERROR: Unable to join federation, exiting: ERROR >" );
			outputMessage( e._reason );
			return 1;
		}
		numTries++;
	}

	//wait here until we get ENTER from the harness
	outputMessage( "WAIT: Press enter to continue" );
	cin.get();

	// Try and resign from federation
	try
	{
		std::string attempt = "ATTEMPT: Attempting to resign from federation ";
		attempt += federationName + " as: " + federateName;
		outputMessage( attempt.c_str() );
		rtiAmb.resignFederationExecution(RTI::DELETE_OBJECTS_AND_RELEASE_ATTRIBUTES);
		outputMessage( "SUCCESS: Resign successful" );
	}
	catch( RTI::Exception & e )
	{
		outputMessage( "ERROR: Unable to resign from federation, exiting: ERROR >" );
		outputMessage( e._reason );
		return 1;
	}


	return 0;
}

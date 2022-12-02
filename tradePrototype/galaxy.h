#include <vector>
using std::vector;

#include <string>
using std::string;
#include "randomstring.h"

#include <iostream>
using std::cout;

// a single type of resource
struct resource {
	string identifier( "rice" );
	float globalValue = 0.0f;
};

// managing stocks held by whatever entity
struct store {
	// global value per resources * some modifier on each resource per planet
	// also functions for interaction with the store ( buy / sell / etc menus )
};

// a location, node in the galaxy graph
struct planet {
	string identifier;
	planet( string id ) : identifier( id ) {}
	// position
	// conditions on the planet? maybe some status modifiers that affect how much
		// resources they produce... food / fuel / etc

	// what about space stations? would they be distinct from planets? all tbd
};

// link between two planets
struct road {
	planet * endpoints[ 2 ];
	// float distance? something - position stuff with all come later
};

// the galaxy consists of a simple graph of planets and "roads" between them
struct galaxy {
	vector<planet> planets;
	vector<road> roads;

	galaxy () {

		// generate some number of planets
		const int numPlanets = 10;
		for ( int i = 0; i < numPlanets; i++ ) {
			planet temp( RandomString( 10 ) );
			planets.push_back( temp );
		}

	// revisit this : want to make sure there is a minimum spanning tree, no
		// isolated subgraphs, have to be able to each planet from any other
		// planet - maybe use the spanning tree to inform trade routes? tbd

		// for now, fully connected graph
		for ( int o = 0; o < numPlanets; o++ ) {
			for ( int i = o + 1; i < numPlanets; i++ ) {
				road temp;
				temp.endpoints[ 0 ] = &planets[ o ];
				temp.endpoints[ 1 ] = &planets[ i ];
				roads.push_back( temp );
			}
		}
	}

	void DebugReportState () {

		cout << "Planets are ( " << planets.size() << " total ):\n";
		for ( auto& p : planets ) {
			cout << '\t' << p.identifier << '\n';
		}

		cout << "\n\nRoads are ( " << roads.size() << " total ):\n";
		for ( auto& r : roads ) {
			cout << '\t' << "Between " << r.endpoints[ 0 ]->identifier << " and " << r.endpoints[ 1 ]->identifier << '\n';
		}

	}

};

#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"


typedef unsigned int uint;

enum orientation { empty_o, orthogonal, isometric, staggered, hexagonal };
enum renderorder { empty_r, right_down, right_up, left_down, left_up };

// TODO 2: Create a struct to hold information for a TileSet


struct TileSet
{
	uint firstgid = 0;
	p2SString name = nullptr;
	uint tilewidth = 0;
	uint tileheight = 0;
	uint spacing = 0;
	uint margin = 0;
};
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------


// TODO 1: Create a struct needed to hold the information to Map node

struct Map
{
	orientation O = empty_o;
	renderorder R = empty_r;
	uint width = 0;
	uint height = 0;
	uint tilewidth = 0;
	uint tileheight = 0;
	uint nextobjectid = 0;
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	bool LoadMap();

	bool LoadTileSet();



private:


public:

	// TODO 1: Add your struct for map info as public for now
	Map Map;
	TileSet TileSet;


private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__
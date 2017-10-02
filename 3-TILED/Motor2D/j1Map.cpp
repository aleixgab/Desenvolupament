#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");


	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if (result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if (ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data

		LoadMap();

		// TODO 4: Create and call a private function to load a tileset
		// remember to support more any number of tilesets!

		LoadTileSet();

		if (ret == true)
		{
			// TODO 5: LOG all the data loaded
			// iterate all tilesets and LOG everything

			LOG("Successfully parsed map XML file: %s", file_name);
			LOG("width: %i height: %i", Map.width, Map.height);
			LOG("tile_width: %i tile_height: %i", Map.tilewidth, Map.tileheight);
			LOG("name: %s firstgid : %i", TileSet.name, TileSet.firstgid);
			LOG("tile width : %i tile height : %i", TileSet.tilewidth, TileSet.tileheight);
			LOG("spacing : %i margin : %i", TileSet.spacing, TileSet.margin);
		}

		map_loaded = ret;

		return ret;
	}
}

bool j1Map::LoadMap() {
	bool ret = true;

	pugi::xml_node map = map_file.child("map");

	p2SString Orientation = map.attribute("orietation").as_string();

	if (Orientation == "orthogonal")
		Map.O = orthogonal;
	else if (Orientation == "isometric")
		Map.O = isometric;
	else if (Orientation == "staggered")
		Map.O = staggered;
	else if (Orientation == "hexagonal")
		Map.O = hexagonal;

	p2SString Renderorder = map.attribute("renderorder").as_string();

	if (Orientation == "right_down")
		Map.R = right_down;
	else if (Orientation == "right_up")
		Map.R = right_up;
	else if (Orientation == "left_down")
		Map.R = left_down;
	else if (Orientation == "left_up")
		Map.R = left_up;

	Map.width = map.attribute("width").as_uint();
	Map.height = map.attribute("height").as_uint();
	Map.tileheight = map.attribute("tileheight").as_uint();
	Map.tilewidth = map.attribute("tilewidth").as_uint();
	Map.nextobjectid = map.attribute("nextobjectid").as_uint();

		return ret;
}

bool j1Map::LoadTileSet() {
	bool ret = true;
	pugi::xml_node tile = map_file.child("map");

	TileSet.firstgid = tile.attribute("firstgid").as_uint();
	TileSet.name = tile.attribute("Desert").as_string();
	TileSet.tilewidth = tile.attribute("tilewidth").as_uint();
	TileSet.tileheight = tile.attribute("tileheight").as_uint();
	TileSet.spacing = tile.attribute("spacing").as_uint();
	TileSet.margin = tile.attribute("margin").as_uint();


	return ret;
}

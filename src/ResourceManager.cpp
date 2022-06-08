#include "ResourceManager.h"


//makes an instance and is created only once
ResourceManager& ResourceManager::instance()
{
	static ResourceManager instance;
	return instance;
}


sf::Texture* ResourceManager::getTexture(const Type_t name)
{
	return &(m_textures[name]);
}

sf::Font* ResourceManager::getFont(const Type_f name)
{
	return &(m_fonts[name]);
}

sf::SoundBuffer& ResourceManager::getSound(const Type_s name)
{
	return m_soundBuff[name];
}

//Constructor
ResourceManager::ResourceManager()
{
	/* Load Textures */
	loadTexture("dragons.png", Type_t::dragons);
	loadTexture("gameWin.png", Type_t::gameWin);
	loadTexture("gameOver.png", Type_t::gameOver);
	loadTexture("levelUp.png", Type_t::LevelUp);

	/* Load Fonts */
	loadFont("ALGER.TTF", Type_f::algertxt);

	///* load Sounds */
	loadSound("mainTrack.ogg", Type_s::mainTrack);

	m_song = Sound(getSound(Type_s::mainTrack));
	
}

void ResourceManager::loadTexture(const std::string path, const Type_t name)
{
	sf::Texture temp;
	temp.loadFromFile(path);
	m_textures[name] = temp;
}

void ResourceManager::loadFont(const std::string path, const Type_f name)
{
	sf::Font temp;
	temp.loadFromFile(path);
	m_fonts[name] = temp;
}

void ResourceManager::loadSound(const std::string path, const Type_s name)
{
	sf::SoundBuffer temp;
	temp.loadFromFile(path);
	m_soundBuff[name] = temp;
}

void ResourceManager::playSong()
{
	//stopAllSongs();
	m_song.play();
	m_song.setVolume(30);
}
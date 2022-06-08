//this class is singleton class
#pragma once


#include "macros.h"


class ResourceManager
{
public:
	//make the static event so we wont load the textures multiple times
	static ResourceManager& instance();
	sf::Texture* getTexture(const Type_t name);
	sf::Font* getFont (const Type_f name);
	sf::SoundBuffer& getSound(const Type_s name);
	void playSong();
	
private:

	ResourceManager(); //private ctor for singleton
	void loadTexture(const std::string, const Type_t);
	void loadFont(const std::string path, const Type_f name);
	void loadSound(const std::string path, const Type_s name);
	void stopAllSongs();
	

	std::unordered_map<Type_t, sf::Texture> m_textures;
	std::unordered_map<Type_f, sf::Font> m_fonts;
	std::unordered_map<Type_s, sf::SoundBuffer> m_soundBuff;
	
	sf::Sound m_song;
	Type_s m_playing;
};
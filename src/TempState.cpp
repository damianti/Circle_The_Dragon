#include "TempState.h"


TempState::TempState(Type_t texture, RenderWindow* window)
{
	auto text = ResourceManager::instance().getTexture(texture);
	Sprite image(*text);
	image.setOrigin((float)text->getSize().x / 2, (float)text->getSize().y / 2);
	image.setPosition(centerWindow);
	Clock clock;
	
	window->draw(image);
	window->display();
	sleep(seconds(0.8f));
	

}

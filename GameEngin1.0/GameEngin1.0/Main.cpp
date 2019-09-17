#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "It's UP");
	window.setFramerateLimit(60);


	window.setKeyRepeatEnabled(false);

	bool play = true;
	sf::Event event;
	//Game Loop
	while (play)
	{
		//EVENTS

		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) 
			{
				std::cout << "key has been pressed" << std::endl;
			}

			if (event.type == sf::Event::Closed) 
			{
				play = false;
			}
		}

		//LOGIC

		//RENDERING
		window.clear();


		window.display();
	}

	//clean

	window.close();
	return 0;
}
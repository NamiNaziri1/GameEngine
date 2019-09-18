#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "It's UP");
	window.setFramerateLimit(60);


	window.setKeyRepeatEnabled(false);

	//var
	bool play = true;
	sf::Event event;
	bool leftClick = false;
	int mouseX = 0, mouseY = 0;
	int rectXPosition = 0;

	//Render shapes

	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(100,100));
	rect.setPosition(350, 250);
	rect.setFillColor(sf::Color::Blue);


	sf::CircleShape circle;
	circle.setRadius(50);
	circle.setPosition(350, 250);
	circle.setFillColor(sf::Color::Yellow);


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

			if (event.type == sf::Event::MouseButtonPressed &&
				event.mouseButton.button == sf::Mouse::Left) 
			{
				leftClick = true;
			}


			if (event.type == sf::Event::MouseMoved)
			{
				mouseY = event.mouseMove.y;
				mouseX = event.mouseMove.x;
			}


		}


		//LOGIC
		if (leftClick)
		{
			std::cout << "Left Click Pressed" << std::endl;
			leftClick = false;
		}
		
		std::cout << "X: " << mouseX  << "Y: " << mouseY << std::endl;
		rectXPosition++;
		rect.setPosition(rectXPosition,rectXPosition);

		//RENDERING
		window.clear();

		window.draw(rect);
		window.draw(circle);

		window.display();
	}

	//clean

	window.close();
	return 0;
}
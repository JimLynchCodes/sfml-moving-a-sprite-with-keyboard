#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1000.0f * screenScalingFactor, 800.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());

	sf::CircleShape shape(window.getSize().x / 8);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	sf::Event event;

	// sf::Texture t1,t2;
	sf::Texture t1;
	t1.loadFromFile("content/sfml.png");

	// sf::Sprite s1,background;
	sf::Sprite s1;
	s1.setTexture(t1);

	int stepSize = 30;
	while (window.isOpen())
	{
		int changeX = 0;
		int changeY = 0;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					std::cout << "Pressing Left!!" << std::endl;
					changeX -= stepSize;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					std::cout << "Pressing Right!!" << std::endl;
					changeX += stepSize;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					std::cout << "Pressing Up!!" << std::endl;
					changeY -= stepSize;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					std::cout << "Pressing Down!!" << std::endl;
					changeY += stepSize;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					std::cout << "Released Left!!" << std::endl;
					changeX = 0;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					std::cout << "Released Right!!" << std::endl;
					changeX = 0;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					std::cout << "Released Up!!" << std::endl;
					changeY = 0;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					std::cout << "Released Down!!" << std::endl;
					changeY = 0;
				}
			}
		}

		window.clear();
		window.draw(s1);
		s1.move(changeX, changeY);
		window.display();
	}

	return 0;
}

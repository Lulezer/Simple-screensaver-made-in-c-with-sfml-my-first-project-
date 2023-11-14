#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "ScreenSaver");
	window.setFramerateLimit(60);

	sf::RectangleShape rect;

	sf::Vector2f rectanglePostion(600, 350);

	rect.setPosition(rectanglePostion);
	rect.setSize(sf::Vector2f(100, 100));

	float xVelocity = 3;
	float yVelocity = 3;


	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event));
		{
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}
        //Physics

		if (rectanglePostion.x < 0 || rectanglePostion.x > 1280 - 100) xVelocity *= -1;
		if (rectanglePostion.y < 0 || rectanglePostion.y > 720 - 100) yVelocity *= -1;

		rectanglePostion.x += xVelocity;
		rectanglePostion.y += yVelocity;
		rect.setPosition(rectanglePostion);




		//Render
		window.clear();



		window.draw(rect);



		window.display();

	}

	
	return 0;
}
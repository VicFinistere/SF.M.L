#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// Intro
int intro()
{
	// Position de la fenêtre
	int x = 800;
	int y = 400;

	// Titre
	const char* title = "Magnetic Shoes";

	// Fenêtre
  	sf::RenderWindow window( sf::VideoMode(x, y), title);
  	
	// Police
	sf::Font font;
  
	// Fichier de police absent
 	if( !font.loadFromFile( "KGHAPPYSolid.ttf" ) )
  	{

    		// Fermeture du programme 
		// (On indique qu'il y a eu une erreur)
		return EXIT_FAILURE;
  	}
	
	// Fichier de police présent
  	else
  	{
		// Background
        	sf::Texture background;	
		background.loadFromFile("title_image.jpg");
		sf::Vector2u bg_size = background.getSize();
		
		// Sprite
		sf::Sprite bg_sprite;
        	bg_sprite.setTexture(background);
        	bg_sprite.setOrigin(bg_size.x / 2, bg_size.y / 2);
		bg_sprite.setPosition(sf::Vector2f(x/2.0f, y/2.0f));
		//bg_sprite.setScale(x/bg_size.x, y/bg_size.y);

		// Texte
    		sf::Text text(title, font, 50);
    		sf::FloatRect text_rect = text.getLocalBounds();
		text.setOrigin(text_rect.left + text_rect.width/2.0f, text_rect.top  + text_rect.height/2.0f);
		text.setPosition(sf::Vector2f(x/1.60f,y/3.70f));
		sf::Color color(190,190,190); 
		text.setColor(color);

		// Tant que la fenêtre est ouverte
  		while( window.isOpen() )
  		{
			// Instanciation de l'évenement
    			sf::Event event;

			// Tant que la fenêtre reçoit des actions
    			while( window.pollEvent( event ) )
    			{
				// Si l'action est une tentative de fermeture
      				if( event.type == sf::Event::Closed )
      				{
					// Fermeture de la fenêtre
        				window.close();
      				}
				else if(event.type == sf::Event::MouseButtonPressed)
				{
					return 2;
				}
   	 		}
			// Mise à zéro de la fenêtre
    			window.clear();

			// Paramétrage du texte
			text.setCharacterSize(30);
			
			// En gras ?
			//text.setStyle(sf::Text::Bold);
			
			// Afficahge du texte
    			window.draw(bg_sprite);
			window.draw(text);
			window.display();
  		}
  		
		// Affichage de la fenêtre
		window.display();

		// Fermeture correcte du programme
  		return EXIT_SUCCESS;
	}
}

int level1()
{
	// Position de la fenêtre
	int x = 800;
	int y = 400;

	// Titre
	const char* title = "Level 1";

	// Fenêtre
  	sf::RenderWindow window( sf::VideoMode(x, y), title);
  	
	// Player
       	sf::Texture player;	
	player.loadFromFile("player.png");
	sf::Vector2u player_size = player.getSize();		
	
	// Sprite
	sf::Sprite player_sprite;
        player_sprite.setTexture(player);
        player_sprite.setOrigin(player_size.x / 2, player_size.y / 2);
	float quater_player = (float)player_size.y/4;
	player_sprite.setPosition(sf::Vector2f(x/2.0f, y - quater_player));
	player_sprite.setScale(0.5, 0.5);

	// Tant que la fenêtre est ouverte
  	while( window.isOpen() )
  	{
		// Instanciation de l'évenement
    		sf::Event event;

		// Tant que la fenêtre reçoit des actions
    		while( window.pollEvent( event ) )
    		{
			// Si l'action est une tentative de fermeture
      		
			if( event.type == sf::Event::Closed )	
			{
				// Fermeture de la fenêtre
        			window.close();
      			}
		}
		// Mise à zéro de la fenêtre
	    	window.clear();	
    		window.draw(player_sprite);
		window.display();
  	}
  		
	// Affichage de la fenêtre
	window.display();

	// Fermeture correcte du programme
  	return EXIT_SUCCESS;

}

// Main program
int main()
{
	if(intro() == 2)
	{
		level1();
	}
}


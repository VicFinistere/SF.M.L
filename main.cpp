#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

// Main : C'est par ici que l'application démarre
int main()
{
	// Position de la fenêtre
	int x = 800;
	int y = 600;

	// Titre
	const char* title = "Hello World !";

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
		// Texte
    		sf::Text text( "Hello World !", font, 50 );
    		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
		text.setPosition(sf::Vector2f(x/2.0f,y/2.0f));
		
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

			// Paramétrage du texte
			text.setCharacterSize(30);
			
			// En gras ?
			//text.setStyle(sf::Text::Bold);
			
			// Afficahge du texte
			window.draw(text);
    			window.display();
  		}
  		
		// Affichage de la fenêtre
		window.display();

		// Fermeture correcte du programme
  		return EXIT_SUCCESS;
	}
}

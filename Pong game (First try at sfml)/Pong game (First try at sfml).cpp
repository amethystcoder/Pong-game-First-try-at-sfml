// Pong game (First try at sfml).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifndef WINDOWHEIGHT
#define WINDOWHEIGHT 500
#endif // !WINDOWHEIGHT 500

#ifndef WINDOWWIDTH 
#define WINDOWWIDTH 1000
#endif // !WINDOWWIDTH 1000

//page definitions
#define MAIN_PAGE 0
#define PLAY_WITH_COMPUTER_PAGE 1
#define PLAY_WITH_HUMAN_PAGE 2
#define HOW_TO_PLAY_PAGE 3


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main()
{
    sf::RenderWindow optionswindow(sf::VideoMode(WINDOWWIDTH,WINDOWHEIGHT),"Pong game");
    optionswindow.setFramerateLimit(50);


    //For all the text on the screen
    sf::Font optionsfont;
    optionsfont.loadFromFile("C:\\Users\\USER\\source\\repos\\Pong game (First try at sfml)\\resources\\LucidaSansDemiBold.ttf");


    sf::Text header;
    header.setFont(optionsfont);
    header.setString("Pong Game");
    header.setFillColor(sf::Color::White);
    header.setScale(3,3);
    header.setPosition(sf::Vector2f(250, 80));

    sf::Text Back;
    Back.setFont(optionsfont);
    Back.setString("Back(B)");
    Back.setFillColor(sf::Color::White);
    Back.setPosition(sf::Vector2f(0,0));

    sf::Text optionone;
    optionone.setFont(optionsfont);
    optionone.setString("Play with Computer(A)");
    optionone.setFillColor(sf::Color::White);
    optionone.setPosition(sf::Vector2f(320, 200));

    sf::Text optiontwo;
    optiontwo.setFont(optionsfont);
    optiontwo.setString("Play with Human(Y)");
    optiontwo.setFillColor(sf::Color::White);
    optiontwo.setPosition(sf::Vector2f(320, 250));

    sf::Text optionthree;
    optionthree.setFont(optionsfont);
    optionthree.setString("Sound on/off(L)");
    optionthree.setFillColor(sf::Color::White);
    optionthree.setPosition(sf::Vector2f(320, 300));

    sf::Text optionfour;
    optionfour.setFont(optionsfont);
    optionfour.setString("How to play(H)");
    optionfour.setFillColor(sf::Color::White);
    optionfour.setPosition(sf::Vector2f(320, 350));

    sf::Text optionfive;
    optionfive.setFont(optionsfont);
    optionfive.setString("Quit(Q)");
    optionfive.setFillColor(sf::Color::White);
    optionfive.setPosition(sf::Vector2f(320, 400));

    sf::Text Playeronescore;
    Playeronescore.setFont(optionsfont);
    Playeronescore.setString("0");
    int playeronescore = 0;
    Playeronescore.setFillColor(sf::Color::White);
    Playeronescore.setPosition(sf::Vector2f(450, 210));

    sf::Text Playertwoscore;
    Playertwoscore.setFont(optionsfont);
    Playertwoscore.setString("0");
    int playertwoscore = 0;
    Playertwoscore.setFillColor(sf::Color::White);
    Playertwoscore.setPosition(sf::Vector2f(500, 210));

    sf::Text Computerscore;
    Computerscore.setFont(optionsfont);
    int computerscore = 0;
    Computerscore.setString("0");
    Computerscore.setFillColor(sf::Color::White);
    Computerscore.setPosition(sf::Vector2f(500, 210));

    //Text in the how to play Section
    sf::Text HowtoplayMain;
    HowtoplayMain.setFont(optionsfont);
    HowtoplayMain.setString("HOW TO PLAY");
    HowtoplayMain.setFillColor(sf::Color::White);
    HowtoplayMain.setPosition(sf::Vector2f(320, 100));

    sf::Text Howtoplayone;
    Howtoplayone.setFont(optionsfont);
    Howtoplayone.setString("Score points by getting the ball in your opponents net");
    Howtoplayone.setFillColor(sf::Color::White);
    Howtoplayone.setPosition(sf::Vector2f(20, 200));

    sf::Text Howtoplaytwo;
    Howtoplaytwo.setFont(optionsfont);
    Howtoplaytwo.setString("player 1 paddle up: W and paddle down: S");
    Howtoplaytwo.setFillColor(sf::Color::White);
    Howtoplaytwo.setPosition(sf::Vector2f(20, 300));

    sf::Text Howtoplaythree;
    Howtoplaythree.setFont(optionsfont);
    Howtoplaythree.setString("player 2 paddle up: Pgup and paddle down: Pgdown");
    Howtoplaythree.setFillColor(sf::Color::White);
    Howtoplaythree.setPosition(sf::Vector2f(20, 400));


    //For boards
    sf::Texture firstboard;
    firstboard.loadFromFile("C:\\Users\\USER\\source\\repos\\Pong game (First try at sfml)\\resources\\board1.jpg");
    sf::Texture mainboard;
    mainboard.loadFromFile("C:\\Users\\USER\\source\\repos\\Pong game (First try at sfml)\\resources\\board2.jpg");

    sf::RectangleShape boardone;
    boardone.setTexture(&firstboard);
    boardone.setSize(sf::Vector2f(1000, 500));
    boardone.setPosition(0, 0);

    sf::RectangleShape boardtwo;
    boardtwo.setTexture(&mainboard);
    boardtwo.setSize(sf::Vector2f(1000, 500));
    boardtwo.setPosition(0, 0);

    //For Paddles
    sf::Texture paddles;
    paddles.loadFromFile("C:\\Users\\USER\\source\\repos\\Pong game (First try at sfml)\\resources\\paddles.jpg");

    sf::RectangleShape useronepaddle;
    useronepaddle.setTexture(&paddles);
    int useronemotion = 200;
    sf::Vector2f useronepaddleposition(20, useronemotion);
    useronepaddle.setPosition(useronepaddleposition);
    useronepaddle.setSize(sf::Vector2f(20,150));

    sf::RectangleShape usertwopaddle;
    usertwopaddle.setTexture(&paddles);
    int usertwomotion = 200;
    sf::Vector2f usertwopaddleposition(950,usertwomotion);
    usertwopaddle.setPosition(usertwopaddleposition);
    usertwopaddle.setSize(sf::Vector2f(20, 150));

    sf::RectangleShape computerpaddle;
    computerpaddle.setTexture(&paddles);
    int computermotion = 200;
    sf::Vector2f computerpaddleposition(950,computermotion);
    computerpaddle.setPosition(computerpaddleposition);
    computerpaddle.setSize(sf::Vector2f(20, 150));

    //For ball
    sf::Texture balltexture;
    balltexture.loadFromFile("C:\\Users\\USER\\source\\repos\\Pong game (First try at sfml)\\resources\\ball.jpg");

    sf::CircleShape ball(20.f);
    ball.setTexture(&balltexture);
    sf::Vector2f ballposition(250, 250);
    ball.setPosition(ballposition);
    int movex = 4, movey = 4;

    //Relating to time
    sf::Clock timepass;
    sf::Time getgameduration;

    //For Sound
    bool ismusicplaying = true;
    sf::Music music;
    music.openFromFile("C:\\Users\\USER\\source\\repos\\Pong game (First try at sfml)\\resources\\the-rhythm-of-the-africa-wav-8837.ogg");
    music.setVolume(60);

    //the navigation flag
    int gamepage = 0;

    if (optionswindow.isOpen())
        music.play();
    while (optionswindow.isOpen()) {
        sf::Event options;
        while (optionswindow.pollEvent(options))
        {
            if (options.type == sf::Event::Closed)
                optionswindow.close();

            //Keyboard navigation controls
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                gamepage = PLAY_WITH_COMPUTER_PAGE;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                gamepage = PLAY_WITH_HUMAN_PAGE;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                computerscore = 0;
                Computerscore.setString(std::to_string(computerscore));
                playeronescore = 0;
                Playeronescore.setString(std::to_string(playeronescore));
                playertwoscore = 0;
                Playertwoscore.setString(std::to_string(playertwoscore));
                ballposition.x = 250;
                ballposition.y = 250;
                ball.setPosition(ballposition);
                gamepage = MAIN_PAGE;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                optionswindow.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
                gamepage = HOW_TO_PLAY_PAGE;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                if (music.Paused)
                    music.play();
                if (music.Playing)
                    music.pause();
            }
     
            //mouse navigation controls
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                if (sf::Mouse::getPosition(optionswindow).x < optionone.getPosition().x && sf::Mouse::getPosition(optionswindow).x > optionone.getPosition().x + optionone.getScale().x
                    && sf::Mouse::getPosition(optionswindow).y < optionone.getPosition().y && sf::Mouse::getPosition(optionswindow).y > optionone.getPosition().y + optionone.getScale().y)
                {
                    gamepage = PLAY_WITH_COMPUTER_PAGE;
                }
            }
            //paddle motion
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                useronemotion += 10;
                useronepaddle.setPosition(sf::Vector2f(20, useronemotion));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                useronemotion -= 10;
                useronepaddle.setPosition(sf::Vector2f(20, useronemotion));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
                usertwomotion -= 10;
                usertwopaddle.setPosition(sf::Vector2f(950, usertwomotion));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {
                usertwomotion += 10;
                usertwopaddle.setPosition(sf::Vector2f(950, usertwomotion));
            }

        }
        if (gamepage == MAIN_PAGE) {
            optionswindow.clear();
            optionswindow.draw(boardone);
            optionswindow.draw(header);
            optionswindow.draw(Back);
            optionswindow.draw(optionone);
            optionswindow.draw(optiontwo);
            optionswindow.draw(optionthree);
            optionswindow.draw(optionfour);
            optionswindow.draw(optionfive);
            optionswindow.display();
        }
        if (gamepage == PLAY_WITH_COMPUTER_PAGE) {
            ballposition.x += movex;
            ballposition.y += movey;
            ball.setPosition(ballposition);
            if (ballposition.y < 0 || ballposition.y > WINDOWHEIGHT-40)
                movey *= -1;
            if (ballposition.x < 0 || ballposition.x > WINDOWWIDTH - 40) {
                if (ballposition.x > 0) {
                    playeronescore += 1;
                    Playeronescore.setString(std::to_string(playeronescore));
                }
                if (ballposition.x < WINDOWWIDTH - 40) {
                    computerscore += 1;
                    Computerscore.setString(std::to_string(computerscore));
                }
                ballposition.x = 250;
                ballposition.y = 250;
                ball.setPosition(ballposition);
            }
            if (ballposition.x > 950 - 50 || ballposition.x < 40) {
                if (ballposition.y > computerpaddle.getPosition().y || ballposition.y < computerpaddle.getPosition().y + 150) {
                    movex *= -1;
                }
                if (ballposition.y > useronepaddle.getPosition().y || ballposition.y < useronepaddle.getPosition().y + 150) {
                    movex *= -1;
                }
            }
            optionswindow.clear();
            optionswindow.draw(boardtwo);
            optionswindow.draw(Playeronescore);
            optionswindow.draw(Computerscore);
            optionswindow.draw(ball);
            optionswindow.draw(Back);
            optionswindow.draw(useronepaddle);
            optionswindow.draw(computerpaddle);
            optionswindow.display();
        }
        if (gamepage == HOW_TO_PLAY_PAGE) {
            optionswindow.clear();
            optionswindow.draw(boardone);
            optionswindow.draw(HowtoplayMain);
            optionswindow.draw(Back);
            optionswindow.draw(Howtoplayone);
            optionswindow.draw(Howtoplaytwo);
            optionswindow.draw(Howtoplaythree);
            optionswindow.display();
        }
        if (gamepage == PLAY_WITH_HUMAN_PAGE) {
            /*getgameduration = timepass.getElapsedTime();
            sf::Int64 timer = getgameduration.asSeconds();
            if (timer % 10 == 0) {
                movex += 1;
                movey += 1;
            }*/
            ballposition.x += movex;
            ballposition.y += movey;
            ball.setPosition(ballposition);
            if (ballposition.y < 0 || ballposition.y > WINDOWHEIGHT - 40)
                movey *= -1;
            if (ballposition.x < 0 || ballposition.x > WINDOWWIDTH - 40) {
                if (ballposition.x > 0) {
                    playeronescore += 1;
                    Playeronescore.setString(std::to_string(playeronescore));
                }
                if (ballposition.x < WINDOWWIDTH - 40) {
                    playertwoscore += 1;
                    Playertwoscore.setString(std::to_string(playertwoscore));
                }
                ballposition.x = 250;
                ballposition.y = 250;
                ball.setPosition(ballposition);
            }
            if (ballposition.x > 950 - 40 || ballposition.x < 40) {
                if (ballposition.y > usertwomotion && ballposition.y < usertwomotion + 150) {
                    movex *= -1;
                }
                if (ballposition.y > useronemotion && ballposition.y < useronemotion + 150) {
                    movex *= -1;
                }
            }
            optionswindow.clear();
            optionswindow.draw(boardtwo);
            optionswindow.draw(Playeronescore);
            optionswindow.draw(Playertwoscore);
            optionswindow.draw(ball);
            optionswindow.draw(Back);
            optionswindow.draw(useronepaddle);
            optionswindow.draw(usertwopaddle);
            optionswindow.display();
        }
        
    }
}



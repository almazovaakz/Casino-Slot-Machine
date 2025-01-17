#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <string>

#define WIDTH 700
#define HEIGHT 350

#define ICONW 140.0f
#define ICONH 110.0f

struct IconIndexes {
    int first, second, third;
};

struct Icons {
    sf::Texture texture1, texture2, texture3;
    sf::Sprite first, second, third;
};

IconIndexes setIndexes(int iteration, IconIndexes ind) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 9);

    if (iteration <= 6)
        ind.first = dis(gen);
    if (iteration <= 12)
        ind.second = dis(gen);
    if (iteration <= 18)
        ind.third = dis(gen);

    return ind;
}

Icons setIcons(IconIndexes ind) {
    Icons ret;

    ret.texture1.loadFromFile("icons/" + std::to_string(ind.first) + ".png");
    ret.first.setTexture(ret.texture1);
    ret.first.setPosition(135, 140);

    sf::Vector2u textureSize = ret.texture1.getSize();
    float scaleX = ICONW / textureSize.x;
    float scaleY = ICONH / textureSize.y;
    ret.first.setScale(scaleX, scaleY);

    ret.texture2.loadFromFile("icons/" + std::to_string(ind.second) + ".png");
    ret.second.setTexture(ret.texture2);
    ret.second.setPosition(282, 140);
    ret.second.setScale(scaleX, scaleY);

    ret.texture3.loadFromFile("icons/" + std::to_string(ind.third) + ".png");
    ret.third.setTexture(ret.texture3);
    ret.third.setPosition(430, 140);
    ret.third.setScale(scaleX, scaleY);

    return ret;
}

void drawIcons(sf::RenderWindow &win, Icons icons) {
    win.draw(icons.first);
    win.draw(icons.second);
    win.draw(icons.third);
}

sf::Sprite setBG(sf::Texture &bg_texture) {
    bg_texture.loadFromFile("automat.jpg");
    sf::Sprite automat(bg_texture);
    automat.setPosition(0, 0);
    sf::Vector2u textureSizebg = bg_texture.getSize();
    float scaleXbg = WIDTH / (textureSizebg.x + 0.1f);
    float scaleYbg = HEIGHT / (textureSizebg.y + 0.1f);
    automat.setScale(scaleXbg, scaleYbg);
    return automat;
}

sf::Text setText(sf::Font &font, int score){
    font.loadFromFile("casinofont.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("balance: " + std::to_string(score));
    text.setCharacterSize(42);
    text.setFillColor(sf::Color::Yellow);
    return text;
}

int main() {
    int price = 25;
    int score = 1000;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "BALKHAN OVOCKO!");

    sf::Font font;
    font.loadFromFile("casinofont.ttf");
    sf::Text text = setText(font, score);

    sf::Texture bg_texture;
    sf::Sprite automat = setBG(bg_texture);

    int cnt = 0;
    IconIndexes iconInd = {1, 1, 1};
    iconInd = setIndexes(cnt, iconInd);
    Icons icons = setIcons(iconInd);

    while (window.isOpen()) {
        if (cnt < 18) {
            iconInd = setIndexes(cnt++, iconInd);
        }
        icons = setIcons(iconInd);

        if (cnt == 18) {
            if (iconInd.first == iconInd.second && iconInd.first == iconInd.third) {
                score += iconInd.first * 100;
                text.setString("balance: " + std::to_string(score));
                cnt += 1;
            }
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && cnt >= 18) {
                if (event.key.code == sf::Keyboard::Space) {
                    std::cout << "Space key was pressed!" << std::endl;
                    score -= price;
                    if (score >= 0) {
                        text.setString("balance: " + std::to_string(score));
                        cnt = 0;
                    } else {
                        text.setString("GAME OVER");
                        score = 1000;
                    }
                    std::cout << score << std::endl;
                }
            }
        }

        window.clear();
        window.draw(automat);
        window.draw(text);
        drawIcons(window, icons);

        sf::sleep(sf::milliseconds(75));
        window.display();
    }

    return 0;
}


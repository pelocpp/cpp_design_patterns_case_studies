// ===========================================================================
// Semigraphics.cpp
// ===========================================================================

//https://medium.com/@sawomirkowalski/design-patterns-flyweight-dd49d3138e31
//https://medium.com/@mlbors/the-flyweight-pattern-ff4ef2a8f377

#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
#include <random>

class Character
{
private:
    std::string m_color;
    std::string m_font;

public:
    Character() = default;
    Character(std::string color, std::string font) : m_color(color), m_font(font) {}
    virtual ~Character() = default;

    // getter
    std::string getColor() const { return m_color; }
    std::string getFont() const { return m_font; }

    friend std::ostream& operator<<(std::ostream& os, const Character& ch);
};

std::ostream& operator<<(std::ostream& os, const Character& ch)
{
    return os << "[ Color: " << ch.m_color << " - Font: " << ch.m_font << "]";
}

class AConcreteCharacter
{
private:
    std::shared_ptr<Character> m_sharedState;

public:
    AConcreteCharacter() = default;

    AConcreteCharacter(const Character& state)
    {
        m_sharedState = std::make_shared<Character>(state);
    }

    ~AConcreteCharacter() = default;

    void render(int x, int y) const noexcept {
        std::cout << "Character: Position (" << x << ", " << y << ") with shared state " << *m_sharedState << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const AConcreteCharacter& acc);
};

std::ostream& operator<<(std::ostream& os, const AConcreteCharacter& acc)
{
    return os << "[AConcreteCharacter: " << *acc.m_sharedState << "]";
}

class CharacterFactory {
private:
    std::unordered_map<std::string, Character> m_characterMap;

public:
    void addCharacter(const Character& ch);
    Character getCharacter(const Character& ch);
    std::string getKey(const Character& ch) const;  // returns a Character's hash for a given state
    void listCharacters() const;
};

Character CharacterFactory::getCharacter(const Character& ch) {

    std::string key = getKey(ch);

    if (m_characterMap.find(key) == m_characterMap.end())
    {
        std::cout << "CharacterFactory: Can't find this character, creating new one." << std::endl;
        m_characterMap[key] = ch;
    }
    else
    {
        std::cout << "CharacterFactory: Reusing existing character." << std::endl;
    }

    return m_characterMap.at(key);
}


std::string CharacterFactory::getKey(const Character& ch) const
{
    // returns a Character's hash for a given state
    return ch.getColor() + "_" + ch.getFont();
}

void CharacterFactory::listCharacters() const {

    size_t count = m_characterMap.size();
    std::cout << "FlyweightFactory: " << count << " flyweights:" << std::endl;

    for (std::pair<std::string, AConcreteCharacter> ch : m_characterMap)
    {
        std::cout << ch.first << ", " << ch.second << std::endl;
    }
}

void CharacterFactory::addCharacter(const Character& ch)
{
    std::string key = getKey(ch);  // returns a Character's hash for a given state
    m_characterMap[key] = ch;
}

class CharacterClient {
private:
    std::array<std::string, 7> m_colors;
    std::default_random_engine m_engine{};
    std::uniform_int_distribution<int> m_distribution{ 0, m_colors.size() - 1 };

public:

    CharacterClient() : m_colors{
        std::string("Red"),
        std::string("Green"),
        std::string("Blue"),
        std::string("White"),
        std::string("Black"),
        std::string("Yellow"),
        std::string("Magenta")
    }
    {}

    std::string getRandomColor() {
        int index = m_distribution(m_engine);
        return m_colors[index];
    }

    int getRandomX() {
        return (m_distribution(m_engine) * 100);
    }

    int getRandomY() {
        return (m_distribution(m_engine) * 100);
    }
};


void fillFactory(CharacterFactory& factory, std::initializer_list<Character> characters) {
    for (const Character& character : characters)
    {
        factory.addCharacter(character);
    }
}

void testSemigraphics01() {

    CharacterFactory factory;

    fillFactory(factory, {
            { "Red", "Arial" },
            { "Green", "Arial" },
            { "Blue", "Arial" },
            { "White", "Fixedsys" },
            { "Black", "Fixedsys" }
        }
    );

    factory.listCharacters();
}

void testSemigraphics02() {

    CharacterClient client;

    for (int i = 0; i < 100; i++) {
        std::string color = client.getRandomColor();
        std::cout << color << std::endl;
    }
}

void testSemigraphics03() {

    CharacterClient client;

    CharacterFactory factory;

    fillFactory(factory, {
        {"Red", "Arial" },
        {"Green", "Arial" },
        {"Blue", "Arial" }
        }
    );

    for (int i = 0; i < 15; i++) {

        std::string color = client.getRandomColor();
        Character ch(color, std::string("Arial"));
        AConcreteCharacter acc = factory.getCharacter(ch);
        acc.render(client.getRandomX(), client.getRandomY());
    }
}

// ===========================================================================
// End-of-File
// ===========================================================================

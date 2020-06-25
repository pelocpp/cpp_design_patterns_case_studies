// ===========================================================================
// GeneratingPasswords.cpp
// ===========================================================================

#include <iostream>
#include <string>
#include <array>
#include <random>
#include <cassert>

class PasswordGenerator
{
public:
    virtual std::string generate() = 0;
    virtual std::string allowed_chars() const = 0;
    virtual size_t length() const = 0;
    virtual void add(std::unique_ptr<PasswordGenerator>) = 0;
    virtual void clear() = 0;
    virtual ~PasswordGenerator() {}
};

class BasicPasswordGenerator : public PasswordGenerator
{
private:
    size_t len;

public:
    explicit BasicPasswordGenerator(size_t const len) noexcept : len(len)
    {}

    virtual std::string generate() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual void add(std::unique_ptr<PasswordGenerator>) override
    {
        throw std::runtime_error("not implemented");
    }

    virtual void clear() override
    {
        throw std::runtime_error("not implemented");
    }

    virtual size_t length() const override final
    {
        return len;
    }
};

class DigitGenerator : public BasicPasswordGenerator
{
public:
    explicit DigitGenerator(size_t const len) noexcept
        : BasicPasswordGenerator(len) {}

    virtual std::string allowed_chars() const override
    {
        return std::string("0123456789");
    }
};

class SymbolGenerator : public BasicPasswordGenerator
{
public:
    explicit SymbolGenerator(size_t const len) noexcept
        : BasicPasswordGenerator(len) {}

    virtual std::string allowed_chars() const override
    {
        return std::string("!@#$%^&*(){}[]?<>");
    }
};

class UpperLetterGenerator : public BasicPasswordGenerator
{
public:
    explicit UpperLetterGenerator(size_t const len) noexcept
        : BasicPasswordGenerator(len) {}

    virtual std::string allowed_chars() const override
    {
        return std::string("ABCDEFGHIJKLMNOPQRSTUVXYWZ");
    }
};

class LowerLetterGenerator : public BasicPasswordGenerator
{
public:
    explicit LowerLetterGenerator(size_t const len) noexcept
        : BasicPasswordGenerator(len) {}
    virtual std::string allowed_chars() const override
    {
        return std::string("abcdefghijklmnopqrstuvxywz");
    }
};

class CompositePasswordGenerator : public PasswordGenerator
{
private:
    std::random_device rd;
    std::mt19937 eng;
    std::vector<std::unique_ptr<PasswordGenerator>> generators;

private:
    virtual std::string allowed_chars() const override
    {
        throw std::runtime_error("not implemented");
    };
    virtual size_t length() const override
    {
        throw std::runtime_error("not implemented");
    };

public:
    CompositePasswordGenerator()
    {
        auto seed_data = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        eng.seed(seq);
    }

    virtual std::string generate() override
    {
        std::string password;
        for (auto& generator : generators)
        {
            std::string chars = generator->allowed_chars();
            std::uniform_int_distribution<> ud(0, static_cast<int>(chars.length() - 1));

            for (size_t i = 0; i < generator->length(); ++i)
                password += chars[ud(eng)];
        }
        std::shuffle(std::begin(password), std::end(password), eng);
        return password;
    }

    virtual void add(std::unique_ptr<PasswordGenerator> generator) override
    {
        generators.push_back(std::move(generator));
    }

    virtual void clear() override
    {
        generators.clear();
    }
};

void generating_passwords() {

    CompositePasswordGenerator generator;
    generator.add(std::make_unique<UpperLetterGenerator>(8));
    //generator.add(std::make_unique<LowerLetterGenerator>(4));
    std::string  password = generator.generate();
    generator.clear();
    std::cout << "Generated: " << password << std::endl;

    generator.add(std::make_unique<SymbolGenerator>(2));
    generator.add(std::make_unique<DigitGenerator>(2));
    generator.add(std::make_unique<UpperLetterGenerator>(2));
    generator.add(std::make_unique<LowerLetterGenerator>(4));

    password = generator.generate();
    std::cout << "Generated: " << password << std::endl;
}

// ===========================================================================
// End-of-File
// ===========================================================================

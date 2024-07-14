#include <iostream>
#include <string>
#include <vector>

class Talent
{
public:
    virtual void setTalent() = 0;
};

class Swimming : public Talent
{
public:
    virtual void setTalent() override
    {
        std::cout << "It can \"Swim\"" << std::endl;
    }
};

class Dancing : public Talent
{
public:
    virtual void setTalent() override
    {
        std::cout << "It can \"Dance\"" << std::endl;
    }
};

class Counting : public Talent
{
public:
    virtual void setTalent() override
    {
        std::cout << "It can \"Count\"" << std::endl;
    }
};

class Dog
{
private:
    std::string name = "unknow";
    std::vector <Talent*> talents;
public:
    Dog(std::string inName)
    {
        name = inName;
    }

    std::string getName()
    {
        return name;
    }

    void addTalents()
    {
        std::string answer;
        std::cout << "If the dog can swimming, then enter \"yes\": ";
        std::cin >> answer;
        if (answer == "yes")
        {
            Swimming swim;            
            talents.push_back(&swim);
        }
        std::cout << "If the dog can dancing, then enter \"yes\": ";
        std::cin >> answer;
        if (answer == "yes")
        {
            Dancing dance;
            talents.push_back(&dance);
        }
        std::cout << "If the dog can counting, then enter \"yes\": ";
        std::cin >> answer;
        if (answer == "yes")
        {
            Counting counting;
            talents.push_back(&counting);
        }
    }
    void show_talents()
    {
        for (int i = 0; i < talents.size(); ++i)
        {
            talents[i]->setTalent();
        }
    }
};

int main()
{
   
    Dog dog("Steve");
    std::cout << dog.getName() << std::endl;

    dog.addTalents();
    dog.show_talents();

    return 0;
}
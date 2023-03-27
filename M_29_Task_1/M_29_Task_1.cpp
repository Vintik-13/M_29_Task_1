/*Задача 1. Суперпёс
Возьмём решение из видео. Все наши животные могут мяукать и гавкать, то есть издавать
звуки в соответствии со своим классом. Но что, если нужно добавить им новое поведение,
например, научить плавать или стоять на задних лапах. Рассмотрим класс Dog: все собаки
умеют лаять и бегать, а некоторые собаки умеют хорошо плавать. Чтобы добавить эти качества
классу Dog, мы можем создать ещё один класс «плавающих» животных и наследовать от него
наш класс. Но что, если не все собаки умеют хорошо плавать, а некоторые из них совсем
не умеют плавать.Наша задача — построить класс Dog таким образом, чтобы к его объектам
можно было выборочно добавлять новые умения, но при этом не менять поведение основного
класса. Список умений будет вызываться с помощью метода show_talents().
Что нужно сделать
Создайте класс Dog, к которому можно добавлять новые способности.
Создайте абстрактный класс «Талант» (Talent), от которого будут наследоваться все
добавляемые способности. Пока таких способностей три: умение плавать (Swimming), умение
танцевать (Dancing), умение считать (Counting), но можете добавить и другие.
Создайте у класса Dog метод show_talents() для показа всех способностей, которыми
обладает собака.
Требования к реализации
Класс Talent должен быть абстрактным. Это значит, что объекты такого класса мы создать
не сможем, так как одна из его функций объявлена как «чисто» виртуальная (pure virtual).
Каждая способность, наследуемая от абстрактного класса Talent, должна быть представлена
в виде отдельного класса.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

class Talent {
public:

    Talent() {}

    virtual ~Talent() {}

    virtual void showTalent() const = 0;
};

class Swimming : public Talent {
public:

    Swimming() {}

    ~Swimming() {}

    void showTalent() const override {

        std::cout << "Swimming\n";
    }
};

class Dancing : public Talent {
public:

    Dancing() {}

    ~Dancing() {}

    void showTalent() const override {

        std::cout << "Dancing\n";
    }
};

class Counting : public Talent {
public:

    Counting() {}

    ~Counting() {}

    void showTalent() const override {

        std::cout << "Counting\n";
    }
};

class Dog {

    std::string _name;
    std::vector<Talent*> _talents;

public:

    Dog(const std::string& name = "No name") : _name(name) {}

    ~Dog() {

        for (auto p : _talents) {

            if (p != nullptr)
                delete p;
        }
    }

    void setTalent(Talent* t) {

        for (auto p : _talents) {            

            if (typeid(*p) == typeid(*t))
                return;
        }

        if (t != nullptr) {

            this->_talents.push_back(t);                            
        }
    }

    std::string getName() const { return _name; }

    void getTalents() const {

        for (auto p : _talents) {

            p->showTalent();
        }
    }
};

int main()
{
    Dog* dog1 = new Dog("Steve");       

    dog1->setTalent(new Swimming());

    dog1->setTalent(new Dancing());

    dog1->setTalent(new Swimming());

    dog1->setTalent(new Counting());

    std::cout << "This is " << dog1->getName() << " and it has some talents:\n";

    dog1->getTalents();
    
}


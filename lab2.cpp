#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>
#include <assert.h>

using namespace std;

class Card {
    string   _name_of_app;
    string   _category;
    double   _cost;
    uint32_t _sizeapp;
    uint32_t _number_of_install;
    double   _mark;
public:
    Card(const string& name_of_app, const string& category, double cost, uint32_t sizeapp, uint32_t number_of_install, double mark)
        : _name_of_app(name_of_app), _category(category), _cost(cost), _sizeapp(sizeapp), _number_of_install(number_of_install), _mark(mark)
    {}

    const string& getNameOfApp() const { return _name_of_app; }
    const string& getCategory() const { return _category; }
    double         getCost() const { return _cost; }
    uint32_t      getSizeApp() const { return _sizeapp; }
    uint32_t      getNumberOfInstall() const { return _number_of_install; }
    double        getMark() const { return _mark; }
};

class IComposite {
public:
    virtual void addCard(Card* c) {}
    virtual void outputIndex(int c)const{}
    virtual void outputAll()const = 0;
};
class CompositeCard : public IComposite {
    vector<Card*> cd;
public:
    void addCard(Card* c) {
        cd.push_back(c);
    }
    void outputIndex(int iter) const{
        cout << cd[iter]->getNameOfApp() << " " << cd[iter]->getCategory() << " " << cd[iter]->getCost()
             << " " << cd[iter]->getSizeApp() << " " << cd[iter]->getNumberOfInstall() << " " << cd[iter]->getMark() << endl;
        /*cout << iter->getNameOfApp() << " " << iter->getCategory() << " " << iter->getCost()
                << " " << iter->getSizeApp() << " " << iter->getNumberOfInstall() << " " << iter->getMark() << endl;   */
    }
    void outputAll()const {
        /*for (vector<Card*>::const_iterator iter = cd.begin(); iter != cd.end(); ++iter) {
            outputIndex(*iter);        
        }*/
        for (int iter=0; iter<cd.size(); ++iter) {
            outputIndex(iter);
        }
    }
    ~CompositeCard() {
        for (vector<Card*>::const_iterator iter = cd.begin(); iter != cd.end(); ++iter)
            delete *iter;
    }
};

int main(int argc, char** argv) {
    try {
        vector<string>  arguments(argv + 1, argv + argc);
        IComposite* composite = new CompositeCard();
        composite->addCard(new Card("FireFox", "Связь", 0, 72000000, 123456789, 4.5));
        composite->addCard(new Card("Озон", "Покупки", 0, 97000000, 10345195, 4.8));
        composite->addCard(new Card("TouchRetouch", "Фотография", 119, 16000000, 1843212, 4.6));
        composite->addCard(new Card("Stepik", "Образование", 0, 12000000, 1056732, 4.9));

        if (arguments.empty()) {
            composite->outputAll();
            return 0;
        }

        if (arguments.size() == 1) {
            int i = stoi(arguments[0]);
            composite->outputIndex(i);
            return 0;
        }

        cout << "*** Недопустимое количество аргументов" << endl;
        return 1;
    }
    catch (exception& e) {
        cout << "*** " << e.what() << endl;
        return 1;
    }
}
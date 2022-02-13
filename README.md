## Описание задания

Задание: Шаблон проектирования Composite (компоновщик).

Разработать программу командной строки, в которой вывод содержимого коллекции карточек Person осуществлялся бы через задаваемый интерфейс с применением шаблона проектирования Composite (компоновщик). Итоговый вариант программы должен быть сохранён в вузовский репозиторий, скомпилирован и проверен с помощью сценария непрерывной интеграции.

## Функция main

```cpp
    int main(int argc, char** argv) {
        try {
            vector<string>  arguments(argv + 1, argv + argc);
            CompositeCard* composite;
            composite->addCard(new Card("FireFox", "Связь", 0, 72000000, 123456789, 4.5));
            composite->addCard(new Card("Озон", "Покупки", 0, 97000000, 10345195, 4.8));
            composite->addCard(new Card("TouchRetouch", "Фотография", 119, 16000000, 1843212, 4.6));
            composite->addCard(new Card("Stepik", "Образование", 0, 12000000, 1056732, 4.9));
        
            if (arguments.empty()) {
                composite->outputAll();
                delete composite;
                return 0;
            }

            if (arguments.size() == 1) {
                int i = stoi(arguments[0]);
                composite->outputIndex(i);
                delete composite;
                return 0;
            }

            cout << "*** Недопустимое количество аргументов" << endl;
            delete composite;
            return 1;
        }
        catch(exception &e) {
            cout << "*** " << e.what() << endl;
            return 1;
        }
    }
```

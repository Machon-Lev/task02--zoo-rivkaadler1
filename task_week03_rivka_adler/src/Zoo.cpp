#include "Zoo.h"

Zoo::Zoo()
{
    // Create some animals and add them to the zoo
    animals.push_back(new Lion("Simba", Location(rand() % 20, rand() % 40)));
    animals.push_back(new Lion("Mufasa", Location(rand() % 20, rand() % 40)));
    animals.push_back(new Monkey("Rafiki", Location(rand() % 20, rand() % 40)));
    animals.push_back(new Clownfish("Nemo", Location(rand() % 20, rand() % 40)));
}

Zoo::~Zoo()
{
    // Free memory for each ZooAnimal object in the animals vector
    for (ZooAnimal* animal : animals)
    {
        delete animal;
    }

    // Clear the vector to avoid dangling pointers
    animals.clear();
}

void Zoo::printHelp() {
    cout << "commands:\n";
    cout << "stop - stop a specified animal from moving\n";
    cout << "move - start a specified animal moving again\n";
    cout << "create - create a new animal\n";
    cout << "del - delete a specified animal\n";
    cout << "delAll - delete all animals of a specified type\n";
    cout << "help - display this help text\n";
    cout << "exit - exit the program\n";
    cout << ". - advance to the next step\n";
    cout << "\n";
}

void Zoo::printZooState() {
    printMap();
    printList();
}

void Zoo::run() {
    cout << "Welcome to the zoo!\n\n";
    printZooState();

    while (true) {
        try {
            string command;
            cout << "Enter command (type 'help' for a list of commands): ";
            getline(cin, command);

            if (command == "stop") {
                int index = getAnimalIndex();
                stop(index);
            }
            else if (command == "move") {
                int index = getAnimalIndex();
                move(index);
            }
            else if (command == "create") {
                char type = getAnimalType();
                string name = getAnimalName();
                create(type, name);
            }
            else if (command == "del") {
                int index = getAnimalIndex();
                del(index);
            }
            else if (command == "delAll") {
                char type = getAnimalType();
                delAll(type);
            }
            else if (command == "help") {
                printHelp();
            }
            else if (command == "exit") {
                break;
            }
            else if (command == ".") {
                // Do nothing for now
            }
            else {
                cout << "Invalid command. Type 'help' for a list of commands.\n";
            }

            stepAll();
            printZooState();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
}

// Helper functions for getting user input
int Zoo::getAnimalIndex() {
    int index;
    cout << "Enter the index of the animal: ";
    cin >> index;
    cin.ignore(); // Ignore any leftover newlines
    return index;
}

char Zoo::getAnimalType() {
    char type;
    cout << "Enter the first letter of the type of the animal: ";
    cin >> type;
    cin.ignore(); // Ignore any leftover newlines
    return type;
}

string Zoo::getAnimalName() {
    string name;
    cout << "Enter the name of the animal: ";
    getline(cin, name);
    return name;
}


void Zoo::stop(int num)
{
    if (num >= 0 && num < animals.size())
    {
        if (animals[num])
            animals[num]->stop();
    }
}

void Zoo::move(int num)
{
    if (num >= 0 && num < animals.size())
    {
        if (animals[num])
            animals[num]->move();
    }
}

void Zoo::create(char type, string name)
{
    if (type == 'L')
    {
        animals.push_back(new Lion(name, Location(rand() % 20, rand() % 40)));
    }
    else if (type == 'M')
    {
        animals.push_back(new Monkey(name, Location(rand() % 20, rand() % 40)));
    }
    else if (type == 'C')
    {
        animals.push_back(new Clownfish(name, Location(rand() % 20, rand() % 40)));
    }

}

void Zoo::del(int num)
{
    if (num >= 0 && num < animals.size())
    {
        if (animals[num])
        {
            delete animals[num];
            animals.erase(animals.begin() + num);
        }
    }
}

void Zoo::delAll(char type)
{
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i]->getInitial() == type)
        {
            delete animals[i];
            animals.erase(animals.begin() + i);
            i--;
        }
    }
}

void Zoo::printMap()
{
    cout << "Map:\n";
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            bool found_animal = false;
            for (ZooAnimal* a : animals)
            {
                if (a->getLocation() == Location(i, j))
                {
                    cout << a->getInitial() << " ";
                    found_animal = true;
                    break;
                }
            }
            if (!found_animal)
            {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void Zoo::printList()
{
    cout << "\nList of animals:\n";
    for (int i = 0; i < animals.size(); i++)
    {
        std::cout << i << ".";
        animals[i]->printDetails();
    }
}

void Zoo::stepAll()
{
    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->step();
    }
}
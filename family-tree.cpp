/*Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
descendants <name>: return number of descendants of the given <name>
generation <name>: return the number of generations of the descendants of the given <name>

Note that: the total number of people in the family is less than or equal to 10
4
Input
Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
Output
Each line is the result of a corresponding query.
Example
Input
Peter Newman
Michael Thomas
John David
Paul Mark
Stephan Mark
Pierre Thomas
Mark Newman
Bill David
David Newman
Thomas Mark
***
descendants Newman
descendants Mark
descendants David
generation Mark
***
Output
10
5
2
2
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Person {
    string name;
    vector<Person*> children;
    int descendantCount = -1; // for memoization
    int generationCount = -1; // for memoization

    Person(const string& name)
        : name(name)
    {
    }
};

unordered_map<string, Person*> people;

int countDescendants(Person* person)
{
    if (person->descendantCount != -1)
        return person->descendantCount;

    person->descendantCount = 0;
    for (auto child : person->children) {
        person->descendantCount += 1 + countDescendants(child);
    }
    return person->descendantCount;
}

int countGenerations(Person* person)
{
    if (person->generationCount != -1) {
        return person->generationCount;
    }

    int maxGen = 0; // Start with 0, meaning no additional generations beyond the current person
    for (auto child : person->children) {
        maxGen = max(maxGen, countGenerations(child));
    }

    person->generationCount = 1 + maxGen; // Include the current generation
    return person->generationCount;
}
int main()
{
    string childName, parentName;
    while (true) {
        cin >> childName;
        if (childName == "***")
            break;
        cin >> parentName;

        // cout << "Reading relationship: " << childName << " is child of " << parentName << endl; // Debug output

        if (people.find(childName) == people.end()) {
            people[childName] = new Person(childName);
        }
        if (people.find(parentName) == people.end()) {
            people[parentName] = new Person(parentName);
        }
        people[parentName]->children.push_back(people[childName]);
    }

    string cmd, paramName;
    while (true) {
        cin >> cmd;
        if (cmd == "***")
            break;
        cin >> paramName;

        // cout << "Processing command: " << cmd << " " << paramName << endl; // Debug output

        if (cmd == "descendants") {
            cout << countDescendants(people[paramName]) << endl;
        } else if (cmd == "generation") {
            cout << countGenerations(people[paramName]) - 1 << endl;
        }
    }

    // Free memory
    for (auto& p : people) {
        delete p.second;
    }

    return 0;
}

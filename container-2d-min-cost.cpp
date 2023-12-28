/*
Problem: Container 2D Loading Minimize Cost - Larrge
Description
There are K trucks 1,2,…,K to transport N items (2D shape) 1, 2, …, N. Truck k  has the container size W[k] x  L[k]. Item i has size w[i] x  l[i] .  Items loaded in a truck can not overlap. The cost of using truck k is c[k]. Find a solution that load N items into K trucks such that the total cost of trucks used is minimal.
A solution is represented by t[i], x[i], y[i], and o[i] in which (x[i], y[i]) is the coordinate of item i loaded in truck t[i], o[i] = 1, if the item i is rotated 90 degree.
Input
Line 1: contains N and K (1 <= N, K <= 1000)
Line i+1 (i = 1,2,…,N) contains 2 integers  w[i] and l[i]  (1 <= w[i], l[i] <= 1000)
Line  1+N+k (k = 1,…, K) contains W[k], L[k] and c[k] (1 <= W[k], L[k] <= 1000, 1 <= c[k] <= 1000)
Output
Line i (i = 1, 2, . . ., N): write 4 integers i, t[i], x[i], y[i], o[i]

Example
Input
5 5
90 70
10 70
80 30
100 60
20 90
180 120 8
20 100 10
160 50 6
120 140 11
180 30 7

Output
1 1 0 0 0
2 1 0 70 1
3 1 0 80 0
4 1 90 0 1
5 1 150 0 0
*/
#include <algorithm>
#include <iostream>
#include <vector>

#define NMAX 10000
#define KMAX 10000

using namespace std;

struct Item {
    uint32_t id, width, height;
    uint32_t truck_id, corner_x, corner_y;
    bool rotated = false;
};

struct Free_Rectangle {
    uint32_t corner_x, corner_y, width, height;
};

struct Suitable_Free_Rec_Result {
    Free_Rectangle suitable_rec;
    uint32_t rec_id;
    bool isRotated;
    bool isExist;
};

struct Truck {
    uint32_t id, width, height;
    uint32_t cost;
    vector<Free_Rectangle> list_free_rectangles;
    vector<Item> list_items;
};

uint32_t n_items, n_trucks;
Item item[NMAX];
Truck truck[KMAX];

bool compareItem(Item a, Item b)
{
    if (a.height == b.height)
        return a.width > b.width;
    return a.height > b.height;
}

bool compareItemByID(Item a, Item b)
{
    return a.id < b.id;
}

void rotateItem(Item& item)
{
    item.rotated = 1 - item.rotated;
    uint32_t temp = item.width;
    item.width = item.height;
    item.height = temp;
}

bool compareTruck(Truck a, Truck b)
{
    float value_a = (a.width * a.height) / (a.cost);
    float value_b = (b.width * b.height) / (b.cost);
    if (value_a == value_b)
        return (a.width * a.height) / (a.width + a.height) > (b.width * b.height) / (b.width + b.height);
    return value_a > value_b;
}

bool isFitToFreeRectangle(Free_Rectangle rec, Item item, bool rotated)
{
    if (rotated)
        return (item.width <= rec.height) && (item.height <= rec.width);
    return (item.width <= rec.width) && (item.height <= rec.height);
}

pair<uint32_t, uint32_t> getFreeRectangleScore(Free_Rectangle rec, Item item, bool rotated)
{
    pair<uint32_t, uint32_t> score;
    uint32_t remain_width = rec.width - (rotated ? item.height : item.width);
    uint32_t remain_height = rec.height - (rotated ? item.width : item.height);
    score.first = min(remain_width, remain_height);
    score.second = max(remain_width, remain_height);
    return score;
}

bool compareFreeRectangleScore(pair<uint32_t, uint32_t> a, pair<uint32_t, uint32_t> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

Suitable_Free_Rec_Result findSuitableFreeRectangle(Truck truck, Item item)
{
    Suitable_Free_Rec_Result suitable_rec;
    suitable_rec.isRotated = false;
    suitable_rec.isExist = false;
    suitable_rec.rec_id = 0;

    pair<uint32_t, uint32_t> best_score = { UINT32_MAX, UINT32_MAX };

    const uint32_t n_rectangles = truck.list_free_rectangles.size();
    pair<uint32_t, uint32_t> rec_score;
    for (uint32_t i = 0; i < n_rectangles; ++i) {
        Free_Rectangle rec = truck.list_free_rectangles[i];

        // Not rotate case
        rec_score = getFreeRectangleScore(rec, item, 0);
        if (isFitToFreeRectangle(rec, item, 0) && compareFreeRectangleScore(rec_score, best_score)) {
            best_score = rec_score;
            suitable_rec.suitable_rec = move(rec);
            suitable_rec.rec_id = i;
            suitable_rec.isRotated = false;
            suitable_rec.isExist = true;
        }

        // Rotate case
        rec_score = getFreeRectangleScore(rec, item, 1);
        if (isFitToFreeRectangle(rec, item, 1) && compareFreeRectangleScore(rec_score, best_score)) {
            best_score = rec_score;
            suitable_rec.suitable_rec = move(rec);
            suitable_rec.rec_id = i;
            suitable_rec.isRotated = true;
            suitable_rec.isExist = true;
        }
    }

    return suitable_rec;
}

vector<Free_Rectangle> splitFreeRectangle(bool isHorizontalSplit, Free_Rectangle rec, Item item)
{
    vector<Free_Rectangle> list_free_rectangles;

    Free_Rectangle right_rec;
    right_rec.width = rec.width - item.width;
    if (right_rec.width > 0) {
        right_rec.corner_x = rec.corner_x + item.width;
        right_rec.corner_y = rec.corner_y;
        right_rec.height = isHorizontalSplit ? item.height : rec.height;
        list_free_rectangles.push_back(right_rec);
    }

    Free_Rectangle top_rec;
    top_rec.height = rec.height - item.height;
    if (top_rec.height > 0) {
        top_rec.corner_x = rec.corner_x;
        top_rec.corner_y = rec.corner_y + item.height;
        top_rec.width = isHorizontalSplit ? rec.width : item.width;
        list_free_rectangles.push_back(top_rec);
    }

    return list_free_rectangles;
}

void mergeFreeRectangles(Truck& truck)
{
    bool isChanged = true;
    while (isChanged) {
        isChanged = false;
        for (uint32_t i = 0; i < truck.list_free_rectangles.size(); ++i) {
            Free_Rectangle& first = truck.list_free_rectangles[i];

            // Loop to find a mergable free_rec for the rec i
            for (uint32_t j = 0; j < truck.list_free_rectangles.size(); ++j) {
                Free_Rectangle& second = truck.list_free_rectangles[j];
                if (j == i)
                    continue;

                // Find the mergable free_rec with the same width
                if ((first.width == second.width) && (first.corner_x == second.corner_x) && (second.corner_y == first.corner_y + first.height)) {
                    isChanged = true;
                    first.height = first.height + second.height;
                    // Remove the two second free_rec
                    truck.list_free_rectangles.erase(truck.list_free_rectangles.begin() + j);
                    break;
                }

                // Find the mergable free_rec with the same height
                if ((first.height == second.height) && (first.corner_y == second.corner_y) && (second.corner_x == first.corner_x + first.width)) {
                    isChanged = true;
                    first.width = first.width + second.width;
                    // Remove the second free_rec
                    truck.list_free_rectangles.erase(truck.list_free_rectangles.begin() + j);
                    break;
                }
            }
        }
    }
}

// Check if item find a possible free_rec in the truck for inserting process
bool tryPlaceItemToTruck(Truck& truck, Item& item)
{
    Suitable_Free_Rec_Result suitable_rec = findSuitableFreeRectangle(truck, item);

    if (!suitable_rec.isExist)
        return false;
    Free_Rectangle best_rec = suitable_rec.suitable_rec;

    // Add the item into the choosen free_rec
    item.truck_id = truck.id;
    item.corner_x = best_rec.corner_x;
    item.corner_y = best_rec.corner_y;
    if (suitable_rec.isRotated)
        rotateItem(item);

    truck.list_items.push_back(item);

    // Replace the used free_rec by the new splited rec(s)
    truck.list_free_rectangles.erase(truck.list_free_rectangles.begin() + suitable_rec.rec_id);
    vector<Free_Rectangle> new_recs = splitFreeRectangle(best_rec.width <= best_rec.height, best_rec, item);
    for (Free_Rectangle rec : new_recs) {
        truck.list_free_rectangles.push_back(rec);
    }

    mergeFreeRectangles(truck);

    return true;
}

void solve()
{
    for (uint32_t i = 1; i <= n_items; ++i) {
        for (uint32_t j = 1; j <= n_trucks; ++j) {
            if (tryPlaceItemToTruck(truck[j], item[i]))
                break;
        }
    }
}

void readInput()
{
    cin >> n_items >> n_trucks;
    for (uint32_t i = 1; i <= n_items; ++i) {
        cin >> item[i].width >> item[i].height;
        item[i].id = i;
        if (item[i].width > item[i].height)
            rotateItem(item[i]);
    }

    for (uint32_t i = 1; i <= n_trucks; ++i) {
        cin >> truck[i].width >> truck[i].height >> truck[i].cost;
        truck[i].id = i;

        Free_Rectangle first_rec;
        first_rec.width = truck[i].width;
        first_rec.height = truck[i].height;
        first_rec.corner_x = 0;
        first_rec.corner_y = 0;
        truck[i].list_free_rectangles.push_back(first_rec);
    }

    sort(item + 1, item + n_items + 1, compareItem);
    sort(truck + 1, truck + n_trucks + 1, compareTruck);
}

void printSolution()
{
    sort(item + 1, item + n_items + 1, compareItemByID);
    for (uint32_t i = 1; i <= n_items; ++i) {
        cout << item[i].id << ' ' << item[i].truck_id << ' ' << item[i].corner_x << ' ' << item[i].corner_y << ' ' << item[i].rotated << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    readInput();
    solve();
    printSolution();
    return 0;
}

class Point {
public:
    int x;
    int y;
    Point();
    Point(int x, int y);

    bool operator==(const Point &other);
    bool operator!=(const Point &other);
};

class Node {
public:
    Node *prev;
    Point *position;

    Node(int x, int y);
    Node(int x, int y, Node *prev);
};

enum Direction {EAST, WEST, NORTH, SOUTH};

class Snake {
public:
    Direction direction;
    Node *head;

    Snake(int x, int y, Direction direction);
    void Move();
    void Grow();
};

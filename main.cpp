#include <iostream>
#include <vector>

enum class Direction {
    N, S, E, W, Up, Down
};

class Spacecraft {
private:
    int x;
    int y;
    int z;
    Direction direction;

public:
    Spacecraft(int x, int y, int z, Direction direction)
        : x(x), y(y), z(z), direction(direction) {}

    void moveForward() {
        switch (direction) {
            case Direction::N:
                y++;
                break;
            case Direction::S:
                y--;
                break;
            case Direction::E:
                x++;
                break;
            case Direction::W:
                x--;
                break;
            case Direction::Up:
                z++;
                break;
            case Direction::Down:
                z--;
                break;
        }
    }

    void moveBackward() {
        switch (direction) {
            case Direction::N:
                y--;
                break;
            case Direction::S:
                y++;
                break;
            case Direction::E:
                x--;
                break;
            case Direction::W:
                x++;
                break;
            case Direction::Up:
                z--;
                break;
            case Direction::Down:
                z++;
                break;
        }
    }

    void turnLeft() {
        switch (direction) {
            case Direction::N:
                direction = Direction::W;
                break;
            case Direction::S:
                direction = Direction::E;
                break;
            case Direction::E:
                direction = Direction::N;
                break;
            case Direction::W:
                direction = Direction::S;
                break;
            case Direction::Up:
            case Direction::Down:
                // No change in direction
                break;
        }
    }

    void turnRight() {
        switch (direction) {
            case Direction::N:
                direction = Direction::E;
                break;
            case Direction::S:
                direction = Direction::W;
                break;
            case Direction::E:
                direction = Direction::S;
                break;
            case Direction::W:
                direction = Direction::N;
                break;
            case Direction::Up:
            case Direction::Down:
                // No change in direction
                break;
        }
    }

    void turnUp() {
        switch (direction) {
            case Direction::N:
            case Direction::S:
            case Direction::E:
            case Direction::W:
                direction = Direction::Up;
                break;
            case Direction::Up:
            case Direction::Down:
                // No change in direction
                break;
        }
    }

    void turnDown() {
        switch (direction) {
            case Direction::N:
            case Direction::S:
            case Direction::E:
            case Direction::W:
                direction = Direction::Down;
                break;
            case Direction::Up:
            case Direction::Down:
                // No change in direction
                break;
        }
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    int getZ() const {
        return z;
    }

    Direction getDirection() const {
        return direction;
    }
};

int main() {
    Spacecraft spacecraft(0, 0, 0, Direction::N);

    std::vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands) {
        switch (command) {
            case 'f':
                spacecraft.moveForward();
                break;
            case 'b':
                spacecraft.moveBackward();
                break;
            case 'l':
                spacecraft.turnLeft();
                break;
            case 'r':
                spacecraft.turnRight();
                break;
            case 'u':
                spacecraft.turnUp();
                break;
            case 'd':
                spacecraft.turnDown();
                break;
            default:
                std::cout << "Invalid command: " << command << std::endl;
        }
    }

    std::cout << "Final Position: (" << spacecraft.getX() << ", " << spacecraft.getY() << ", " << spacecraft.getZ() << ")" << std::endl;
    std::cout << "Final Direction: " << static_cast<int>(spacecraft.getDirection()) << std::endl;

    return 0;
}
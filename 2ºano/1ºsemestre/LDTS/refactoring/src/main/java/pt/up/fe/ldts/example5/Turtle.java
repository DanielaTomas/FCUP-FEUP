package pt.up.fe.ldts.example5;

public class Turtle {
    private int row;
    private int column;
    private char direction;

    public Turtle(int row, int column, char direction) {
        this.row = row;
        this.column = column;
        this.direction = direction;
    }

    public int getRow() {
        return row;
    }

    public int getColumn() {
        return column;
    }

    public char getDirection() {
        return direction;
    }

    public void execute(char command) {
        if (command == 'L') { // ROTATE LEFT
            if (direction == 'N') direction = 'W';
            else if (direction == 'W') direction = 'S';
            else if (direction == 'S') direction = 'E';
            else if (direction == 'E') direction = 'N';
        } else if (command == 'R') { // ROTATE RIGHT
            if (direction == 'N') direction = 'E';
            else if (direction == 'E') direction = 'S';
            else if (direction == 'S') direction = 'W';
            else if (direction == 'W') direction = 'N';
        } else if (command == 'F'){ // MOVE FORWARD
            if (direction == 'N') row--;
            if (direction == 'S') row++;
            if (direction == 'W') column--;
            if (direction == 'E') column++;
        }
    }
}

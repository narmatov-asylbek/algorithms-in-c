

class Rectangle {
    private:
        int length;
        int breath;
    public:
        Rectangle() {length = breath = 1;}
        Rectangle(int a, int b);
        int area();
        int perimeter();
        int getLength() {return length;}
        int setLength(int l);
};

Rectangle::Rectangle(int a, int b) {
    length = a;
    breath = b;
}

int Rectangle::area() {
    return length * breath;
}

int Rectangle::perimeter() {
    return 2 * (length + breath);
}

void Rectangle::setLength(int l) {
    length = l;
}
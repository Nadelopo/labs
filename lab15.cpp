#include <iostream> 
#include <string>

using namespace std;

class Circle {
private:
	int radius = 0;
	int x = 0;
	int y = 0;
public:
	void setRadius(int _radius) {
		radius = _radius;
	}
	void set�oordinates(int _x, int _y) {
		x += _x; y += _y;
	}
	void get�oordinates() {
		cout << "(" + to_string(x) + ";" + to_string(y) + ")" << endl;
	}
	void getRadius() {
		cout << radius << endl;
	}
};

class Square {
protected:
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;
	int x4 = 0;
	int y4 = 0;
public:
	void set�oordinates(int _x, int _y) {
		x1 += _x; y1 += _y;
	}
	void update�oordinates(int _x, int _y) {
		x1 += _x; y1 += _y;
		x2 += _x; y2 += _y;
		x3 += _x; y3 += _y;
		x4 += _x; y4 += _y;
	}
	void setSides(int _width) {
		y2 = _width + y1;
		x2 = x1;
		x3 = _width + x1;
		y3 = _width + y1;
		x4 = _width + x1;
		y4 = y1;
		get�oordinates();
	}
	void get�oordinates() {
		cout << "(" + to_string(x1) + ";" + to_string(y1) + ")" << " " << "(" + to_string(x2) + ";" + to_string(y2) + ")" << " " << "(" + to_string(x3) + ";" + to_string(y3) + ")" << " " << "(" + to_string(x4) + ";" + to_string(y4) + ")" << " " << endl;
	}
};

class Rectangle : public Square {
public:
	void setSides(int _width, int _height) {
		x2 = x1;
		y2 = y1 + _height;
		x3 = x1 + _width;
		y3 = y1 + _height;
		x4 = x1 + _width;
		y4 = y1;
		get�oordinates();
	}
};

int main() {
	setlocale(LC_ALL, "Ru");

	do {
		int figure;

		Circle c1;
		Square s1;
		Rectangle r1;

		do {
			system("cls");
			cout << "������� ������: \n";
			cout << "1 - ���� \n";
			cout << "2 - ������� \n";
			cout << "3 - ������������� \n";
			cin >> figure;
			system("cls");
		} while (figure < 1 || figure > 3);

		switch (figure) {
			int r, x, y, width, height;
		case 1:
			cout << "������� ������: "; cin >> r; c1.setRadius(r);
			cout << "������� ���������� x: "; cin >> x;
			cout << "������� ���������� y: "; cin >> y; c1.set�oordinates(x, y);
			c1.getRadius();
			c1.get�oordinates();
			break;
		case 2:
			cout << "������� ��������� ���������� x: "; cin >> x;
			cout << "������� ��������� ���������� y: "; cin >> y;
			s1.set�oordinates(x, y);
			cout << "������� ������ �������: "; cin >> width;
			s1.setSides(width);
			break;
		case 3:
			cout << "������� ��������� ���������� x: "; cin >> x;
			cout << "������� ��������� ���������� y: "; cin >> y;
			r1.set�oordinates(x, y);
			cout << "������� ������: "; cin >> width;
			cout << "������� ������: "; cin >> height;
			r1.setSides(width, height);
			break;
		default:
			break;
		}

		int method;
		do {
			cout << "1 - ����������� \n";
			cout << "2 - ��������� �������� \n";
			cin >> method;
		} while (method < 1 || method > 2);


		if (method == 1) {
			int x, y;
			cout << "����������� x ��: "; cin >> x;
			cout << "����������� y ��: "; cin >> y;

			if (figure == 1) {
				c1.set�oordinates(x, y);
				c1.get�oordinates();
			}
			if (figure == 2) {
				s1.update�oordinates(x, y);
				s1.get�oordinates();
			}
			if (figure == 3) {
				r1.update�oordinates(x, y);
				r1.get�oordinates();
			}
		}
		if (method == 2) {
			if (figure == 1) {
				int r;
				cout << "�������� ������ ��: "; cin >> r;
				c1.setRadius(r);
				c1.getRadius();
			}
			if (figure == 2) {
				int side;
				cout << "�������� ������� ��: "; cin >> side;
				s1.setSides(side);
			}
			if (figure == 3) {
				int width, height;
				cout << "�������� ������ ��: "; cin >> width;
				cout << "�������� ������ ��: "; cin >> height;
				r1.setSides(width, height);
			}

		}

		do {
			cout << "��� ������ � ���� ������� 0 \n";
			cin >> figure;
			method = 0;
		} while (figure != 0);

	} while (true);
}
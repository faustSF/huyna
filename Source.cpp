#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"


#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;
using namespace ImGui;
const int W = 800;
const int H = 600;
/*#define W 800
#define H 600
using namespace sf;

void print(int& p1, int& i, float& c, int& scal,int& x0, int& y0, RenderWindow* window, CircleShape& point,float& q1, float& l1, float& q2, float& l2)
{	
	float x = p1 + i / c;
	
	float y = (q2*sin((q1*x)+l1))+l2;

	float x1 = x0 + x * scal;
	float y1 = y0 - y * scal;

	point.setPosition(x1, y1);
	window->draw(point);
}*/


int main()
{
	const float z{1.02f};
	float q1, l1, q2, l2;
	q1 = 1;
	l1 = 1;
	q2 = 1;
	l2=0;
	float& a = q1;
	float& b = l1;
	float& k = q2;
	float& d = l2;
	int x0 = (W / 2)-100;
	int y0 = (H / 2);
	RenderWindow window(sf::VideoMode(800, 600), "Grafik");
	SFML::Init(window);
	int o1 = -10;
	int o2 = 15;
	float c = 100;
	int mass = (((o1) * (-1) + o2) * 1000);
	int sc = 45;
	bool circleExists = false;
	float circleRadius = 1.5f;
	//int j = 3;
	//int circleSegments = 100;
	//float circleColor[3] = { (float)204 / 255, (float)77 / 255, (float)5 / 255 };
	CircleShape point(circleRadius);
	point.setFillColor(Color::Green);
	//point.setFillColor(sf::Color
	//(
	//	(int)(circleColor[0] * 255),
	//	(int)(circleColor[1] * 255),
	//	(int)(circleColor[2] * 255)
	//)); // Color circle
	//shape.setOrigin(circleRadius, circleRadius);
	//shape.setPosition(400, 400); // Center circle
	
	RectangleShape* OsX = new RectangleShape(Vector2f(W, 1));
	OsX->setFillColor(Color::Blue);
	OsX->setPosition(0,x0);

	RectangleShape* OsY = new RectangleShape(Vector2f(1, H));
	OsY->setFillColor(Color::Blue);
	OsY->setPosition(y0+95, 0);
	int anim = 0;
	View zoom(Vector2f(0,0), Vector2f(W, H));
	zoom.move(Vector2f(W / 2, H / 2));
	Clock deltaClock;
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			SFML::ProcessEvent(event);
			//if (event.type == Event::Closed)
			//	window.close();
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::MouseWheelScrolled:
				if (event.mouseWheelScroll.delta >= 1)
				{
					zoom.zoom(1.f / z);
				}
				if (event.mouseWheelScroll.delta <= -1)
				{
					zoom.zoom(1.02f);
				}
				break;
			
			}
		}
		SFML::Update(window, deltaClock.restart());
		if (anim < mass)
			anim += 15;
		Begin("Parametrs");
		ImGui::Text("Input in this shit");
		Checkbox("just fo fun", &circleExists);
		InputFloat("A", &a);
		InputFloat("B", &b);
		InputFloat("K", &k);
		InputFloat("D", &d);
		InputFloat("C", &c);
		InputInt("Scal", &sc);
		//InputInt("w", &j);
		InputInt("o1", &o1);
		InputInt("02", &o2);
		//SliderInt("Sides", &circleSegments, 3, 150);
		//ColorEdit3("Color Circle", circleColor);
		End();
		//OsY->setPosition(y0 + sc*j, 0);
		point.setRadius(circleRadius);
		point.setOrigin(circleRadius, circleRadius);
		//shape.setPointCount(circleSegments);
		//point.setFillColor(sf::Color
		//(
		//	(int)(circleColor[0] * 255),
		//	(int)(circleColor[1] * 255),
		//	(int)(circleColor[2] * 255)
		//)); // Color circle
		RectangleShape line[40];
		for (int i = 0; i < 40; i++) {
			line[i].setSize(Vector2f(1, 20));
			line[i].setFillColor(Color::Black);

			if (i < 20) {
				if (i < 10)
					line[i].setPosition(x0+95 - (i + 1) * sc, y0 - 10);
				else
					line[i].setPosition(x0+95 + (i -9) * sc, y0 - 10);
			}
			else {
				line[i].setRotation(90);
				if (i < 30)
					line[i].setPosition(x0 + 105, y0 + (i - 30) * (-1)*sc);
				else
					line[i].setPosition(x0 + 105, y0 + (i - 29) * (-1)*sc);
			}
		}
		window.clear(sf::Color(18, 33, 43)); // Color background
		if (circleExists)
			for (int i = 0; i < anim; i++) {
				float x = o1 + i / c;
				//float y = x;
				float y = (k*sin((a*x) + b)) + d;
			

				float x1 = x0 + x * (sc);
				float y1 = y0 - y * (sc)+5;

				point.setPosition(x1, y1);
				window.draw(point);
			}
		    
	        window.draw(*OsX);
		    window.draw(*OsY);
			for (int i = 0; i < 40; i++)
				if (i != 19 && i != 20)
					window.draw(line[i]);
			window.setView(zoom);
		    SFML::Render(window);
		    window.display();
	}

	SFML::Shutdown();
	/*float q1, l1, q2, l2;
	std::cout << "Dlya operaciy nad grafikom\n";
	std::cout << "q1 defolt 1\n";
	std::cin >> q1;
	std::cout << "l1 defolt 0\n";
	std::cin >> l1;
	std::cout << "q2 defolt 1\n";
	std::cin >> q2;
	std::cout << "l2 defolt 0\n";
	std::cin >> l2;
	VideoMode sz(W,H);
	RenderWindow* window=new RenderWindow(sz,"Grafik");


	int x0 = (W / 2)-100;
	int y0 = H / 2;

	CircleShape point(1.f);
	point.setFillColor(Color::Green);

	int p1 = -10;
	int p2 = 10;
	float c = 100;
	int prom = (((p1) * (-1) + p2) * c + 1000);
	int scal = 30;


	RectangleShape* OsX=new RectangleShape(Vector2f(W, 1));
	OsX->setFillColor(Color::Blue);
	OsX->setPosition(0, y0);

	RectangleShape* OsY=new RectangleShape(Vector2f(1, H));
	OsY->setFillColor(Color::Blue);
	OsY->setPosition(x0, 0);

	

	int anim = 0;

	while (window->isOpen() and window!=NULL)
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		if (anim < prom)
			anim += 5;

		window->clear(Color::Black);
		window->draw(*OsX);
		window->draw(*OsY);
		
		for (int i = 0; i < anim; i++) {
			print(p1, i, c, scal, x0, y0, window,point,q1,l1,q2,l2);

		}
		window->display();
	}
	delete window;
	delete OsX;
	delete OsY;*/



	return 0;
}
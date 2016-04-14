#include "../libraries/headers/Window.hpp"
#include "../libraries/headers/Boid.hpp"
#include "../libraries/headers/Checkbox.hpp"
#include "../libraries/headers/Button.hpp"
#include "../libraries/headers/Slider.hpp"

#include <iostream>
#include <ctime>

using namespace std;

#define FRAMERATE 60
#define NUMBER_OF_START_BOIDS 5
#define NUMBER_OF_START_OBJECTS 0

#define BORDER_LIMIT 150

#define OBJECT_RADIUS 10
#define OBJECT_COLOR Gray

// Windows
#define MAIN_WINDOW_POS Vector(0, 0)
#define MAIN_WINDOW_SIZE Vector(1920 - 200, 1000)
#define MAIN_WINDOW_TITLE "BoidSimulator-9000 PreAlpha v0.0.0.3 unstable"

#define OPTION_WINDOW_POS Vector(1920 - 200, 0)
#define OPTION_WINDOW_SIZE Vector(200, 525)
#define OPTION_WINDOW_TITLE "BoidSimulator-9000 PreAlpha v0.0.0.3 unstable (options)"

// Buttons
#define BUTTON_PRESSED_COLOR Green
#define BUTTON_IDLE_COLOR Gray

#define ADD_BOID_BUTTON_TEXT "Add boid"
#define ADD_BOID_BUTTON_POS Vector(25, 25)
#define ADD_BOID_BUTTON_SIZE Vector(150, 20)

#define REMOVE_BOID_BUTTON_TEXT "Remove boid"
#define REMOVE_BOID_BUTTON_POS Vector(25, 60)
#define REMOVE_BOID_BUTTON_SIZE Vector(150, 20)

// Checkboxes
#define CHECKBOX_CHECKED_COLOR Green
#define CHECKBOX_IDLE_COLOR Gray

#define ACC_VECTOR_CHECKBOX_TEXT "Acc vector"
#define ACC_VECTOR_CHECKBOX_POS Vector(25, 95)
#define ACC_VECTOR_CHECKBOX_SIZE Vector(150, 20)

#define SPEED_VECTOR_CHECKBOX_TEXT "Vel vector"
#define SPEED_VECTOR_CHECKBOX_POS Vector(25, 130)
#define SPEED_VECTOR_CHECKBOX_SIZE Vector(150, 20)

#define ALIGNMENT_VECTOR_CHECKBOX_TEXT "Ali vector"
#define ALIGNMENT_VECTOR_CHECKBOX_POS Vector(25, 165)
#define ALIGNMENT_VECTOR_CHECKBOX_SIZE Vector(150, 20)

#define COHESION_VECTOR_CHECKBOX_TEXT "Coh vector"
#define COHESION_VECTOR_CHECKBOX_POS Vector(25, 200)
#define COHESION_VECTOR_CHECKBOX_SIZE Vector(150, 20)

#define SEPARATION_VECTOR_CHECKBOX_TEXT "Sep vector"
#define SEPARATION_VECTOR_CHECKBOX_POS Vector(25, 235)
#define SEPARATION_VECTOR_CHECKBOX_SIZE Vector(150, 20)

#define BORDER_REPULSION_VECTOR_CHECKBOX_TEXT "Bor vector"
#define BORDER_REPULSION_VECTOR_CHECKBOX_POS Vector(25, 270)
#define BORDER_REPULSION_VECTOR_CHECKBOX_SIZE Vector(150, 20)

#define MOUSE_ATTRACTION_VECTOR_CHECKBOX_TEXT "Mou vector"
#define MOUSE_ATTRACTION_VECTOR_CHECKBOX_POS Vector(25, 305)
#define MOUSE_ATTRACTION_VECTOR_CHECKBOX_SIZE Vector(150, 20)

// Sliders
#define ALIGNMENT_SLIDER_POS Vector(25, 340)
#define ALIGNMENT_SLIDER_SIZE Vector(150, 20)
#define ALIGNMENT_SLIDER_MIN 0
#define ALIGNMENT_SLIDER_MAX 1
#define ALIGNMENT_SLIDER_VALUE 0.5
#define ALIGNMENT_SLIDER_COLOR Red

#define COHESION_SLIDER_POS Vector(25, 375)
#define COHESION_SLIDER_SIZE Vector(150, 20)
#define COHESION_SLIDER_MIN 0
#define COHESION_SLIDER_MAX 100
#define COHESION_SLIDER_VALUE 0.5
#define COHESION_SLIDER_COLOR Green

#define SEPARATION_SLIDER_POS Vector(25, 410)
#define SEPARATION_SLIDER_SIZE Vector(150, 20)
#define SEPARATION_SLIDER_MIN 0
#define SEPARATION_SLIDER_MAX 2000
#define SEPARATION_SLIDER_VALUE 500
#define SEPARATION_SLIDER_COLOR Blue

#define BORDER_REPULSION_SLIDER_POS Vector(25, 445)
#define BORDER_REPULSION_SLIDER_SIZE Vector(150, 20)
#define BORDER_REPULSION_SLIDER_MIN 0
#define BORDER_REPULSION_SLIDER_MAX 1
#define BORDER_REPULSION_SLIDER_VALUE 0.5
#define BORDER_REPULSION_SLIDER_COLOR Magenta

#define MOUSE_ATTRACTION_SLIDER_POS Vector(25, 480)
#define MOUSE_ATTRACTION_SLIDER_SIZE Vector(150, 20)
#define MOUSE_ATTRACTION_SLIDER_MIN 0
#define MOUSE_ATTRACTION_SLIDER_MAX 100
#define MOUSE_ATTRACTION_SLIDER_VALUE 0.5
#define MOUSE_ATTRACTION_SLIDER_COLOR Yellow

void addBoid(std::vector<Boid> &boids){
	boids.push_back(Boid(Vector(rand() % int(MAIN_WINDOW_SIZE.x), rand() % int(MAIN_WINDOW_SIZE.y)), Vector(rand() % 20 - 10, rand() % 20 - 10)));
}

void removeBoid(std::vector<Boid> &boids){
	if (boids.size()) boids.pop_back();
}

void addObject(std::vector<Vector> &objects){
	objects.push_back(Vector(rand() % int(MAIN_WINDOW_SIZE.x), rand() % int(MAIN_WINDOW_SIZE.y)));
}

void removeObject(std::vector<Vector> &objects){
	objects.pop_back();
}

void addObject(std::vector<Vector> &objects, Vector pos){
	objects.push_back(pos);
}

void removeObject(std::vector<Vector> &objects, int index){
	objects.erase(objects.begin() + index);
}

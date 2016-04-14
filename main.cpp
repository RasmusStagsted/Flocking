#include "main.hpp"

int main(int argc, char **argv){

	// Windows
	Window mainWindow(MAIN_WINDOW_POS, MAIN_WINDOW_SIZE, MAIN_WINDOW_TITLE);
	Window optionWindow(OPTION_WINDOW_POS, OPTION_WINDOW_SIZE, OPTION_WINDOW_TITLE);

	// Checkboxes
	Checkbox velCheckbox(SPEED_VECTOR_CHECKBOX_POS, SPEED_VECTOR_CHECKBOX_SIZE, SPEED_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);
	Checkbox accCheckbox(ACC_VECTOR_CHECKBOX_POS, ACC_VECTOR_CHECKBOX_SIZE, ACC_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);
	Checkbox alignmentCheckbox(ALIGNMENT_VECTOR_CHECKBOX_POS, ALIGNMENT_VECTOR_CHECKBOX_SIZE, ALIGNMENT_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);
	Checkbox cohesionCheckbox(COHESION_VECTOR_CHECKBOX_POS, COHESION_VECTOR_CHECKBOX_SIZE, COHESION_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);
	Checkbox separationCheckbox(SEPARATION_VECTOR_CHECKBOX_POS, SEPARATION_VECTOR_CHECKBOX_SIZE, SEPARATION_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);
	Checkbox borderRepulsionCheckbox(BORDER_REPULSION_VECTOR_CHECKBOX_POS, BORDER_REPULSION_VECTOR_CHECKBOX_SIZE, BORDER_REPULSION_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);
	Checkbox mouseAttractionCheckbox(MOUSE_ATTRACTION_VECTOR_CHECKBOX_POS, MOUSE_ATTRACTION_VECTOR_CHECKBOX_SIZE, MOUSE_ATTRACTION_VECTOR_CHECKBOX_TEXT, Black, CHECKBOX_CHECKED_COLOR, CHECKBOX_IDLE_COLOR, Black);

	// Buttons
	Button addBoidButton(ADD_BOID_BUTTON_POS, ADD_BOID_BUTTON_SIZE, ADD_BOID_BUTTON_TEXT, Black, BUTTON_PRESSED_COLOR, BUTTON_IDLE_COLOR, Black);
	Button removeBoidButton(REMOVE_BOID_BUTTON_POS, REMOVE_BOID_BUTTON_SIZE, REMOVE_BOID_BUTTON_TEXT, Black, BUTTON_PRESSED_COLOR, BUTTON_IDLE_COLOR, Black);

	// Sliders
	Slider alignmentSlider(ALIGNMENT_SLIDER_POS, ALIGNMENT_SLIDER_SIZE, ALIGNMENT_SLIDER_MIN, ALIGNMENT_SLIDER_MAX, ALIGNMENT_SLIDER_VALUE, ALIGNMENT_SLIDER_COLOR);
	Slider cohesionSlider(COHESION_SLIDER_POS, COHESION_SLIDER_SIZE, COHESION_SLIDER_MIN, COHESION_SLIDER_MAX, COHESION_SLIDER_VALUE, COHESION_SLIDER_COLOR);
	Slider separationSlider(SEPARATION_SLIDER_POS, SEPARATION_SLIDER_SIZE, SEPARATION_SLIDER_MIN, SEPARATION_SLIDER_MAX, SEPARATION_SLIDER_VALUE, SEPARATION_SLIDER_COLOR);
	Slider borderRepulsionSlider(BORDER_REPULSION_SLIDER_POS, BORDER_REPULSION_SLIDER_SIZE, BORDER_REPULSION_SLIDER_MIN, BORDER_REPULSION_SLIDER_MAX, BORDER_REPULSION_SLIDER_VALUE, BORDER_REPULSION_SLIDER_COLOR);
	Slider mouseAttractionSlider(MOUSE_ATTRACTION_SLIDER_POS, MOUSE_ATTRACTION_SLIDER_SIZE, MOUSE_ATTRACTION_SLIDER_MIN, MOUSE_ATTRACTION_SLIDER_MAX, MOUSE_ATTRACTION_SLIDER_VALUE, MOUSE_ATTRACTION_SLIDER_COLOR);

	// Boids
	vector<Boid> boids;
	for (int i = 0; i < NUMBER_OF_START_BOIDS; i++) addBoid(boids);

	// Objects
	vector<Vector> objects;
	for (int i = 0; i < NUMBER_OF_START_OBJECTS; i++) addObject(objects);

	// Mouse position
	Vector mouse(0, 0);
	int mouseWindowID = 0;

	// Options
	double alignmentFactor = alignmentSlider.getValue();
	double cohesionFactor = cohesionSlider.getValue();
	double separationFactor = separationSlider.getValue();
	double borderRepulsionFactor = borderRepulsionSlider.getValue();
	double mouseAttractionFactor = mouseAttractionSlider.getValue();

	bool quit = false;

	while (!quit){
		SDL_Event event;
		while (SDL_PollEvent(&event)){

			// ESCAPE key exit
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE){
				quit = true;
				break;
			}

			// Mouse motion
			else if (event.type == SDL_MOUSEMOTION){
				mouse = Vector(event.motion.x, event.motion.y);
				if (event.motion.state & SDL_BUTTON_LMASK){
					if (alignmentSlider.update(mouse)) alignmentFactor = alignmentSlider.getValue();
					if (cohesionSlider.update(mouse)) cohesionFactor = cohesionSlider.getValue();
					if (separationSlider.update(mouse)) separationFactor = separationSlider.getValue();
					if (borderRepulsionSlider.update(mouse)) borderRepulsionFactor = borderRepulsionSlider.getValue();
					if (mouseAttractionSlider.update(mouse)) mouseAttractionFactor = mouseAttractionSlider.getValue();
				}
			}

			// Mouse press
			else if (event.type == SDL_MOUSEBUTTONDOWN){
				if (event.button.windowID == mainWindow.id){
					if (event.button.button == SDL_BUTTON_LEFT) addObject(objects, mouse);
					else if (event.button.button == SDL_BUTTON_RIGHT){
						for (int i = 0; i < objects.size(); i++){
							if ((objects[i] - mouse).getLength() < OBJECT_RADIUS) removeObject(objects, i);
						}
					}
				}
				else if (event.button.windowID == optionWindow.id){
					accCheckbox.update(mouse);
					velCheckbox.update(mouse);
					alignmentCheckbox.update(mouse);
					cohesionCheckbox.update(mouse);
					separationCheckbox.update(mouse);
					borderRepulsionCheckbox.update(mouse);
					mouseAttractionCheckbox.update(mouse);
					if (addBoidButton.update(mouse, true)) addBoid(boids);
					if (removeBoidButton.update(mouse, true)) removeBoid(boids);
					if (alignmentSlider.update(mouse)) alignmentFactor = alignmentSlider.getValue();
					if (cohesionSlider.update(mouse)) cohesionFactor = cohesionSlider.getValue();
					if (separationSlider.update(mouse)) separationFactor = separationSlider.getValue();
					if (borderRepulsionSlider.update(mouse)) borderRepulsionFactor = borderRepulsionSlider.getValue();
					if (mouseAttractionSlider.update(mouse)) mouseAttractionFactor = mouseAttractionSlider.getValue();
				}
			}

			// Mouse release
			else if (event.type == SDL_MOUSEBUTTONUP){
				if (event.button.windowID == mainWindow.id){

				}
				else if (event.button.windowID == optionWindow.id){
					addBoidButton.update(mouse, false);
					removeBoidButton.update(mouse, false);
				}
			}
		}

		mainWindow.background(Black);
		optionWindow.background(Gray);

		// Draw objects
		for (int i = 0; i < objects.size(); i++){
			mainWindow.circle(objects[i], OBJECT_RADIUS, OBJECT_COLOR);
		}

		// Update and draw boids
		for (int i = 0; i < boids.size(); i++){
			boids[i].update(boids, objects, *mainWindow.size, BORDER_LIMIT, mouse, FRAMERATE, alignmentFactor, cohesionFactor, separationFactor, borderRepulsionFactor, mouseAttractionFactor);
			boids[i].draw(mainWindow, velCheckbox.checked(), accCheckbox.checked(), alignmentCheckbox.checked(), cohesionCheckbox.checked(), separationCheckbox.checked(), borderRepulsionCheckbox.checked(), mouseAttractionCheckbox.checked());
		}

		mainWindow.line(Vector(BORDER_LIMIT, BORDER_LIMIT), Vector(mainWindow.size->x - BORDER_LIMIT, BORDER_LIMIT));
		mainWindow.line(Vector(BORDER_LIMIT, BORDER_LIMIT), Vector(BORDER_LIMIT, mainWindow.size->y - BORDER_LIMIT));
		mainWindow.line(Vector(mainWindow.size->x - BORDER_LIMIT, mainWindow.size->y - BORDER_LIMIT), Vector(mainWindow.size->x - BORDER_LIMIT, BORDER_LIMIT));
		mainWindow.line(Vector(mainWindow.size->x - BORDER_LIMIT, mainWindow.size->y - BORDER_LIMIT), Vector(BORDER_LIMIT, mainWindow.size->y - BORDER_LIMIT));

		for (int i = 0; i < boids.size(); i++){
			mainWindow.text(boids[i].pos, i, White);
		}

		// Draw checkboxes
		accCheckbox.draw(optionWindow);
		velCheckbox.draw(optionWindow);
		alignmentCheckbox.draw(optionWindow);
		cohesionCheckbox.draw(optionWindow);
		separationCheckbox.draw(optionWindow);
		borderRepulsionCheckbox.draw(optionWindow);
		mouseAttractionCheckbox.draw(optionWindow);

		// Draw buttons
		addBoidButton.draw(optionWindow);
		removeBoidButton.draw(optionWindow);

		// Draw sliders
		alignmentSlider.draw(optionWindow);
		cohesionSlider.draw(optionWindow);
		separationSlider.draw(optionWindow);
		borderRepulsionSlider.draw(optionWindow);
		mouseAttractionSlider.draw(optionWindow);

		// Update windows
		mainWindow.draw();
		optionWindow.draw();

		SDL_Delay(20);
	}

	return 0;
}

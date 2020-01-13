#ifndef CELL_PHONE_H
#define CELL_PHONE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

Font cellFont;

const int cell_size_x = 300;
const int cell_size_y = 675;
const int button_size_x = cell_size_x/3;
const int button_size_y = cell_size_y/9;
const int textBox_size_x = cell_size_x*0.9;
const int textBox_size_y = cell_size_y*0.4;

class CellButton{
    public:
    CellButton(int top_left_x, int top_left_y, string text, int letters_capitacy);
    RectangleShape& getButton() {return cell_button;};
    void draw_button(RenderWindow* phone_window);
    void set_on_press(RenderWindow* phone_window) {cell_button.setFillColor(Color(30,30,200)); buttonText.setFillColor(Color::White); draw_button(phone_window);};
    void set_on_release(RenderWindow* phone_window) {cell_button.setFillColor(Color::White); buttonText.setFillColor(Color::Black); draw_button(phone_window);};
    int get_top_left_x() {return top_left_x;};
    int get_top_left_y() {return top_left_y;};
    string text_as_string;
    private:
    int top_left_x;
    int top_left_y;
    int letters_capitacy;
    Text buttonText;
    
    RectangleShape cell_button;
};

CellButton::CellButton(int top_left_x, int top_left_y, string text, int letters_capitacy): top_left_x(top_left_x), top_left_y(top_left_y), letters_capitacy(letters_capitacy){
    cell_button.setSize(Vector2f(button_size_x,button_size_y));
    cell_button.setFillColor(Color::White);
    cell_button.setOutlineThickness(1);
    cell_button.setOutlineColor(Color::Black);
    cell_button.setPosition(Vector2f(top_left_x,top_left_y));

    buttonText.setFont(cellFont);
    buttonText.setCharacterSize(16);
    buttonText.setStyle(Text::Regular);
    buttonText.setString(text);
    buttonText.setFillColor(Color::Black);
    buttonText.setPosition(Vector2f(top_left_x+(button_size_x/2)-16,top_left_y+(button_size_y/2)-16));
    text_as_string = text;
    cout<<text<<" range: "<<endl<<"x: "<<top_left_x<<" -> "<<top_left_x+button_size_x<<endl<<"y: "<<top_left_y<<" -> "<<top_left_y+button_size_y<<endl;
}
void CellButton::draw_button(RenderWindow* phone_window){
    cout<<phone_window<<endl;
    phone_window->draw(cell_button);
    phone_window->draw(buttonText);
    
   
}

class CellKeyboard{
    public:
        CellKeyboard(int top_left_x = 0, int top_left_y = cell_size_y/2);
        void draw_keyboard(RenderWindow* phone_window);
        int get_top_left_x() {return top_left_x;};
        int get_top_left_y() {return top_left_y;};
        void set_button_on_press(int mouse_x, int mouse_y, RenderWindow* phone_window);
        void set_button_on_release(int mouse_x, int mouse_y, RenderWindow* phone_window);
    private:
        int top_left_x;
        int top_left_y;
        vector<CellButton> buttons;
};

CellKeyboard::CellKeyboard(int top_left_x , int top_left_y ): top_left_x(top_left_x), top_left_y(top_left_y){
    int current_x = top_left_x;
    int current_y = top_left_y;
    string current_letters = "";
    int letters_capitacy = 0;
    for(int i = 1; i < 13; i++){
        switch(i){
            case 1: current_letters = "1 ";letters_capitacy = 1;break;
            case 2: current_letters = "2 ABC"; letters_capitacy = 3; break;
            case 3: current_letters = "3 DEF"; letters_capitacy = 3; break;
            case 4: current_letters = "4 GHI"; letters_capitacy = 3; break;
            case 5: current_letters = "5 JKL"; letters_capitacy = 3; break;
            case 6: current_letters = "6 MNO"; letters_capitacy = 3; break;
            case 7: current_letters = "7 PQRS"; letters_capitacy = 4; break;
            case 8: current_letters = "8 TUV"; letters_capitacy = 3; break;
            case 9: current_letters = "9 WXYZ"; letters_capitacy = 4; break;
            case 10: current_letters = "&'";letters_capitacy = 2; break;
            case 11:current_letters = "0"; letters_capitacy = 1; break;
            case 12:current_letters = "_";break;
        }
            
        CellButton newButton = CellButton(current_x,current_y,current_letters,letters_capitacy);
        buttons.push_back(newButton); 
        if(i%3==0){
            current_x = 0;
            current_y+=75;
        }
        else current_x+=100;
    }
    cout<<"keyboard range: "<<endl<<"x: "<<top_left_x<<" -> "<<top_left_x+button_size_x*3<<endl<<"y: "<<top_left_y<<" -> "<<top_left_y+button_size_y*4<<endl;
}

void CellKeyboard::draw_keyboard(RenderWindow* phone_window){
    cout<<phone_window<<endl;
    for(auto button: buttons) button.draw_button(phone_window);
    phone_window->display();
}

void CellKeyboard::set_button_on_press(int mouse_x, int mouse_y,RenderWindow* phone_window){
    for(int x = 0; x < buttons.size(); x++){
        if(mouse_x>=buttons[x].get_top_left_x() && mouse_x<=buttons[x].get_top_left_x()+button_size_x && mouse_y >= buttons[x].get_top_left_y() && mouse_y<=buttons[x].get_top_left_y()+button_size_y){
            buttons[x].set_on_press(phone_window); 
            break;
        }
        
    }
    phone_window->display();
}

void CellKeyboard::set_button_on_release(int mouse_x, int mouse_y, RenderWindow* phone_window){
    for(int x = 0; x < buttons.size(); x++){
        if(mouse_x>=buttons[x].get_top_left_x() && mouse_x<=buttons[x].get_top_left_x()+button_size_x && mouse_y >= buttons[x].get_top_left_y() && mouse_y<=buttons[x].get_top_left_y()+button_size_y){
            buttons[x].set_on_release(phone_window); 
            break;
        }
    }
    phone_window->display();
}

class CellTextBox{
    public:
    CellTextBox(int top_left_x = 50, int top_left_y = 50);
    void updateText(string appednigText) {textToPrint_as_string+=appednigText;textToPrint.setString(textToPrint_as_string);};
    void draw_textBox(RenderWindow* phone_window);
    private:
    int top_left_x;
    int top_left_y;
    RectangleShape textBox;
    string textToPrint_as_string = "";
    Text textToPrint;
};

CellTextBox::CellTextBox(int top_left_x, int top_left_y): top_left_x(top_left_x), top_left_y(top_left_y){
    textBox.setPosition(Vector2f(top_left_x,top_left_y));
    textBox.setSize(Vector2f(textBox_size_x,textBox_size_y));
    textBox.setFillColor(Color::White);
    textBox.setOutlineThickness(5);
    textBox.setOutlineColor(Color::Black);
    textToPrint.setFont(cellFont);
    textToPrint.setCharacterSize(24);
    textToPrint.setFillColor(Color::Black);
    textToPrint.setPosition(Vector2f(top_left_x,top_left_y));
}

void CellTextBox::draw_textBox(RenderWindow* phone_window){
    cout<<phone_window<<endl;
    phone_window->draw(textBox);
    phone_window->draw(textToPrint);
    phone_window->display();
    
}

class CellPhone{
    public:
    CellPhone(RenderWindow& givenPhoneWindow);
    void draw_self();
    CellKeyboard keyboard;
    CellTextBox  textBox;
    private:
    RenderWindow* phoneWindow;
};

CellPhone::CellPhone(RenderWindow& givenPhoneWindow){
    phoneWindow = &givenPhoneWindow;
    phoneWindow->setSize(Vector2u(cell_size_x,cell_size_y));
    cellFont.loadFromFile("./tiff/PoiretOne-Regular.ttf");
}

void CellPhone::draw_self(){
    cout<<phoneWindow<<endl;
    phoneWindow->clear(Color(130,130,160));
    keyboard.draw_keyboard(phoneWindow);
    textBox.draw_textBox(phoneWindow);
    phoneWindow->display();
}



#endif//CELL_PHONE_H
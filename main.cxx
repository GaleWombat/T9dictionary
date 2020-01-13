// g++ -O4 -c main.cxx  && g++ main.o -o run.x -lsfml-graphics -lsfml-window -lsfml-system && ./run.x

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "CellComponents.hxx"
#include "DictionaryComponents.hxx"

using namespace std;
using namespace sf;

vector<string> convertNumbersToStrings(string numbers, DictionaryEngine& dict_eng){
    vector<string> foundedWords;
    vector<string> helperVector;
    string helperString="";
    for(int i = 0; i < numbers.size(); i++){
        switch(numbers[i]){
            case '0':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"0");
                } 
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"0");
                    }
                }
                break;
            case '1':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"1");
                } 
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"1");
                    }
                }
                break;
            case '2':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"a");
                    helperVector.push_back(helperString+"b");
                    helperVector.push_back(helperString+"c");
                    helperVector.push_back(helperString+"2");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"a");
                    helperVector.push_back(helperString+"b");
                    helperVector.push_back(helperString+"c");
                    helperVector.push_back(helperString+"2");
                    }
                }
                break;
            case '3':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"d");
                    helperVector.push_back(helperString+"e");
                    helperVector.push_back(helperString+"f");
                    helperVector.push_back(helperString+"3");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"d");
                    helperVector.push_back(helperString+"e");
                    helperVector.push_back(helperString+"f");
                    helperVector.push_back(helperString+"3");
                    }
                
                }
                break;
                
            case '4':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"g");
                    helperVector.push_back(helperString+"h");
                    helperVector.push_back(helperString+"i");
                    helperVector.push_back(helperString+"4");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"g");
                    helperVector.push_back(helperString+"h");
                    helperVector.push_back(helperString+"i");
                    helperVector.push_back(helperString+"4");
                    }
                }
                break;
            case '5':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"j");
                    helperVector.push_back(helperString+"k");
                    helperVector.push_back(helperString+"l");
                    helperVector.push_back(helperString+"5");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"j");
                    helperVector.push_back(helperString+"k");
                    helperVector.push_back(helperString+"l");
                    helperVector.push_back(helperString+"5");
                    }
                }
                
                break;
            case '6':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"m");
                    helperVector.push_back(helperString+"n");
                    helperVector.push_back(helperString+"o");
                    helperVector.push_back(helperString+"6");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"m");
                    helperVector.push_back(helperString+"n");
                    helperVector.push_back(helperString+"o");
                    helperVector.push_back(helperString+"6");
                    }
                }
                break;
            case '7':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"p");
                    helperVector.push_back(helperString+"q");
                    helperVector.push_back(helperString+"r");
                    helperVector.push_back(helperString+"s");
                    helperVector.push_back(helperString+"7");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"p");
                    helperVector.push_back(helperString+"q");
                    helperVector.push_back(helperString+"r");
                    helperVector.push_back(helperString+"s");
                    helperVector.push_back(helperString+"7");
                    }
                }
                break;
            case '8':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"t");
                    helperVector.push_back(helperString+"u");
                    helperVector.push_back(helperString+"v");
                    helperVector.push_back(helperString+"8");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"t");
                    helperVector.push_back(helperString+"u");
                    helperVector.push_back(helperString+"v");
                    helperVector.push_back(helperString+"8");
                    }
                }
                break;
            case '9':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"w");
                    helperVector.push_back(helperString+"x");
                    helperVector.push_back(helperString+"y");
                    helperVector.push_back(helperString+"z");
                    helperVector.push_back(helperString+"9");
                }
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                    helperString = foundedWords[n];
                    helperVector.push_back(helperString+"w");
                    helperVector.push_back(helperString+"x");
                    helperVector.push_back(helperString+"y");
                    helperVector.push_back(helperString+"z");
                    helperVector.push_back(helperString+"9");
                    }
                }
                break;
            case '*':
                if(foundedWords.size()==0){
                    helperVector.push_back(helperString+"\'");
                    helperVector.push_back(helperString+"&");
                } 
                else{
                    for(int n = 0; n < foundedWords.size(); n++){
                        helperString = foundedWords[n];
                        helperVector.push_back(helperString+"\'");
                        helperVector.push_back(helperString+"&");
                    }
                }
                break;
        }
        foundedWords.clear();

        for(auto copy : helperVector){
            foundedWords.push_back(copy);
        }
        helperVector.clear();
    }
    return foundedWords;
}

void updateDictionary(CellGraphics &cell_graph, DictionaryGraphics &dict_graph, DictionaryEngine& dict_eng, RenderWindow &dictionary){
    string getFromCell;
    getFromCell = cell_graph.getTextAsNumbers();
    auto all_words = convertNumbersToStrings(getFromCell, dict_eng);
    vector<string> good_words;
    for(int i = 0; i < all_words.size(); i++){
        if(dict_eng.isInDictionary(all_words[i])) good_words.push_back(all_words[i]);
    }
    if(good_words.size()>0){
        dict_graph.update_text(good_words);
        dict_graph.draw_self(dictionary);
    }
}

int main(){
    RenderWindow cell_phone(VideoMode(cell_size_x,cell_size_y), "Nukja");
    cellFont.loadFromFile("./tiff/PoiretOne-Regular.ttf");
    RenderWindow dictionary(VideoMode(300,cell_size_y), "Dictionary");
    CellGraphics cell_graph;
    DictionaryEngine dict_eng;
    DictionaryGraphics dict_graph;
    Event event;
    string getFromCell;
    bool isShiftPressed = false;
    bool wasShift8 = false;
    bool wasShift3 = false;
    while(cell_phone.isOpen()){
        while (cell_phone.pollEvent(event)){
            if (event.type == Event::Closed) cell_phone.close();
            if (event.type == Event::MouseButtonPressed){
                if(event.mouseButton.button == Mouse::Left){
                    int mouse_x = event.mouseButton.x;
                    int mouse_y = event.mouseButton.y;
                    cell_graph.setButtonPressed(mouse_x,mouse_y,cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                    
            }
            if(event.type == Event::MouseButtonReleased){
                if(event.mouseButton.button == Mouse::Left){
                    int mouse_x = event.mouseButton.x;
                    int mouse_y = event.mouseButton.y;
                    cell_graph.setButtonReleased(mouse_x,mouse_y,cell_phone);
                }
            }
            if(event.type ==Event::KeyPressed){
                if(event.key.code == Keyboard::Num1){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num2){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+button_size_x+5,cell_graph.getKeyboardTopLeftY()+5, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num3){
                    if(!isShiftPressed){
                        cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+button_size_x*2+5,cell_graph.getKeyboardTopLeftY()+5, cell_phone);
                        updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                    }
                    else{
                        isShiftPressed=false;
                        wasShift3 = true;
                        cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+button_size_x*2+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                        updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                    }
                    
                }
                if(event.key.code == Keyboard::Num4){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num5){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5+button_size_y, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num6){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5+button_size_y, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num7){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y*2, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num8){
                    if(!isShiftPressed){
                        cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5+button_size_y*2, cell_phone);
                        updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                    }
                    else{
                        isShiftPressed=false;
                        wasShift8 = true;
                        cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                        updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                    }
                   
                }
                if(event.key.code == Keyboard::Num9){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5+button_size_y*2, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::Num0){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
                if(event.key.code == Keyboard::LShift || event.key.code == Keyboard::RShift){
                    isShiftPressed=true;
                }
                if(event.key.code == Keyboard::BackSpace){
                    cell_graph.setButtonPressed(cell_graph.getKeyboardTopLeftX()+button_size_x*2+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                    updateDictionary(cell_graph,dict_graph,dict_eng,dictionary);
                }
            }
            if(event.type == Event::KeyReleased){
                if(event.key.code == Keyboard::Num1) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5, cell_phone);
                if(event.key.code == Keyboard::Num2) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5, cell_phone);
                if(event.key.code == Keyboard::Num3){
                    if(!wasShift3)cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5, cell_phone);
                    else{
                        wasShift3 = false;
                        cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                    }
                }
                if(event.key.code == Keyboard::Num4) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y, cell_phone);
                if(event.key.code == Keyboard::Num5) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5+button_size_y, cell_phone);
                if(event.key.code == Keyboard::Num6) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5+button_size_y, cell_phone);
                if(event.key.code == Keyboard::Num7) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y*2, cell_phone);
                if(event.key.code == Keyboard::Num8){
                    if(!wasShift8)cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5+button_size_y*2, cell_phone);
                    else{
                        wasShift8 = false;
                        cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                    }
                }
                if(event.key.code == Keyboard::Num9) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5+button_size_y*2, cell_phone);
                if(event.key.code == Keyboard::Num0) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);
                if(event.key.code == Keyboard::BackSpace) cell_graph.setButtonReleased(cell_graph.getKeyboardTopLeftX()+5+button_size_x*2,cell_graph.getKeyboardTopLeftY()+5+button_size_y*3, cell_phone);

            }
        }
        while (dictionary.pollEvent(event)){
            if (event.type == Event::Closed) dictionary.close();
        }
        cell_phone.clear(Color(130,130,160));
        cell_graph.draw_cell(cell_phone);
        dict_graph.draw_self(dictionary);
    }
}
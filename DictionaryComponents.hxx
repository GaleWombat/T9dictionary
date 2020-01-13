#ifndef DICTIONARYCOMPONENTS_H
#define DICTIONARYCOMPONENTS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace std;
using namespace sf;

Font dictionaryFont;

class TreeNode{
    public:
    TreeNode(char text ='\0'){content = text;};
    void addChild(TreeNode* child) {children.push_back(child);};
    vector<TreeNode*> children;
    char content;
};
class Tree{
    public:
    // Tree();
    void addToTree(string text);
    vector<string> searchInTree(string toSearch);
    bool isInTree(string toFind);
    void getEveryFromGivenNode(TreeNode* node, vector<string> &toAppend, string currentPath);
    private:
    TreeNode root;
};

void Tree::addToTree(string text){
    TreeNode* current = &root;
    int letter_count = 0;
    bool isFound = false;
    while(letter_count!=text.size()){
        for(int i = 0; i < current->children.size(); i++){
            if(current->children[i]->content==text[letter_count]){
                isFound  = true;
                current = current->children[i];
                break;
            }
        }
        if(!isFound){
            TreeNode* newNode = new TreeNode(text[letter_count]);
            current->children.push_back(newNode);
            current = newNode;
        }
        letter_count++;
        isFound = false;
    }
    TreeNode* finalNode = new TreeNode('\0');
    current->children.push_back(finalNode);
}

bool Tree::isInTree(string toFind){
    toFind+='\0';
    TreeNode* current = &root;
    int letter_count = 0;
    bool isFound = false;
    while(letter_count!=toFind.size()){
        // cout<<"current letter"<<toFind[letter_count]<<endl;
        for(int i = 0; i < current->children.size(); i++){
            if(current->children[i]->content==toFind[letter_count]){
                current = current->children[i];
                // path+=current->content;
                isFound = true;
                letter_count++;
                break;
            }
        }
        if(!isFound) return false;
        isFound = false;
    }
    return true;
}

vector<string> Tree::searchInTree(string toSearch){
    TreeNode* current = &root;
    string path;
    vector<string> founded;
    int letter_count = 0;
    bool isFound = false;
    while(letter_count!=toSearch.size()){
        for(int i = 0; i < current->children.size(); i++){
            if(current->children[i]->content==toSearch[letter_count]){
                current = current->children[i];
                path+=current->content;
                isFound = true;
                letter_count++;
                break;
            }
        }
        if(!isFound) return founded;
        bool isFound = false;
    }
    // getEveryFromGivenNode(current,founded,path);
    founded.push_back(path);
    return founded;
}

void Tree::getEveryFromGivenNode(TreeNode* node, vector<string> &toAppend, string currentPath){
    for(int i = 0; i < node->children.size(); i++){
        string next = currentPath;
        if(node->children[i]->content=='\0') toAppend.push_back(next);
        else{
            next+= node->children[i]->content;
            getEveryFromGivenNode(node->children[i],toAppend,next);
        }
    }
}

class Input{
    public:
    Input();
    ~Input();
    string readWord();
    private:
    ifstream fileStream;
};
Input::Input(){
    fileStream.open("./txt/words6.txt");
    if(!fileStream) cerr<<"Could not open file words6.txt"<<endl;
    else cerr<<"File opened succesfully"<<endl;
}
Input::~Input(){
    fileStream.close();
}
string Input::readWord(){
    string returning;
    if(getline(fileStream,returning)) return returning;
    else return "EOF";
}

class DictionaryEngine{
    public:
    DictionaryEngine();
    ~DictionaryEngine()  {input.~Input();};
    vector<string> findAllWords(string toFind);
    bool isInDictionary(string toFind);
    private:
    Input input;
    Tree tree;
};

DictionaryEngine::DictionaryEngine(){
    string build;
    build = input.readWord();
    while(build!="EOF"){
        tree.addToTree(build);
        build = input.readWord();
    }
}

vector<string> DictionaryEngine::findAllWords(string toFind){
    // cout<<"im in findAllWords"<<endl;
    return tree.searchInTree(toFind);
}

bool DictionaryEngine::isInDictionary(string toFind){
    return tree.isInTree(toFind);
}

class DictionaryGraphics{
    public:
    DictionaryGraphics();
    void draw_self(RenderWindow& dictWindow);
    void update_text(vector<string>& allWords);
    private:
    Text current_words;
    string all_words_as_string;
};

DictionaryGraphics::DictionaryGraphics(){
    dictionaryFont.loadFromFile("./tiff/PoiretOne-Regular.ttf");
    current_words.setFont(dictionaryFont);
    current_words.setCharacterSize(24);
    current_words.setStyle(Text::Regular);
    current_words.setFillColor(Color::Black);
}

void DictionaryGraphics::draw_self(RenderWindow& dictWindow){
    dictWindow.clear(Color::White);
    dictWindow.draw(current_words);
    dictWindow.display();
}

void DictionaryGraphics::update_text(vector<string>& allWords){
    all_words_as_string.clear();
    // cout<<"im in update text"<<endl;
    for(int i = 0; i < allWords.size(); i++){
        all_words_as_string+=allWords[i];
        all_words_as_string+="\n";
        // cout<<all_words_as_string;
    }
    current_words.setString(all_words_as_string);
}

#endif//DICTIONARYCOMPONENTS_H

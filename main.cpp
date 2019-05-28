#include <bits/stdc++.h>

using namespace std;

struct canvas{  //galutine nuotrauka
    int R;
    int G;
    int B;
};
struct rect{ //staciakampio info
    int x;
    int y;
    int xLenth;
    int yLenth;
    int R;
    int G;
    int B;
};

void putRectangle(canvas Canvas[99][99], rect rectangle); // deda staciakampius ant nuotraukos
void watchMaxSize(int x, int & maxWidth, int y, int & maxHeight); // tikrina ar neprasiplete nuotrauka

int main()
{
    ifstream in("U2.txt");
    ofstream out("U2rez.txt");
    canvas Canvas[99][99]; //99*99 langeliu bus nuotraukoje
    rect rectangle[100]; // masyvas staciakampiu
    int rows;
    int maxWidth = 0; //nuotraukos dydis
    int maxHeight = 0;

    for(int i=0; i<99; i++){ // visa nuotrauka nuspalvinama baltai
        for(int j=0; j<99; j++){
            Canvas[i][j].R = 255;
            Canvas[i][j].G = 255;
            Canvas[i][j].B = 255;
        }
    }

    in>>rows;
    for(int i= 0; i<rows; i++){
        in>>rectangle[i].x; //apibūdinamas naujas staciakampis
        in>>rectangle[i].y;
        in>>rectangle[i].xLenth;
        in>>rectangle[i].yLenth;
        in>>rectangle[i].R;
        in>>rectangle[i].G;
        in>>rectangle[i].B;

        putRectangle(Canvas, rectangle[i]); // staciakampis uzdedamas ant nuotraukos
        watchMaxSize(rectangle[i].x+rectangle[i].xLenth,  //palygina staciakampio ilgi
                        maxWidth, // su esamu ilgiu
                        rectangle[i].y + rectangle[i].yLenth, // palygina staciakampio auksti
                        maxHeight); // su esamu auksciu, ir jei didesni skaiciai, tai pataiso i didesni
    }

    out<<maxHeight<<" "<<maxWidth<<endl; //iraso duomenis
    for(int y = 0; y<maxHeight; y++){
        for(int x = 0; x<maxWidth; x++){
            out<<"["<<x<<","<<y<<"] "<<Canvas[x][y].R<<" ";
            out<<Canvas[x][y].G<<" ";
            out<<Canvas[x][y].B<<" "<<endl;
        }
    }
    in.close();
    out.close();
    return 0;
}

void putRectangle(canvas Canvas[99][99], rect rectangle){
    for(int x = rectangle.x; x<rectangle.xLenth+rectangle.x; x++){ // spalvint pradeda nuo kairiojo virsutinio kampo, iki to kampo + staciakampio ilgis
        for(int y = rectangle.y; y<rectangle.yLenth+rectangle.y; y++){ // tas pats, tik su auksciu
            Canvas[x][y].R = rectangle.R; //spalvinama
            Canvas[x][y].G = rectangle.G;
            Canvas[x][y].B = rectangle.B;
        }
    }
}

void watchMaxSize(int x, int & maxWidth, int y, int & maxHeight){ //jei randa didesni skaiciu, tai prilygina
    if(x>maxWidth){
        maxWidth=x;
    }
    if(y>maxHeight){
        maxHeight = y;
    }
}

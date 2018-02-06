/**
* @ProgramName: Program-1
* @Author: Anna Danh 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 05 02 2018
*/


#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};

/**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and swaps the rows vertically.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void flipVert(rgb** image,int width,int height){
  rgb temp;
    for(int i=0; i<height/2; i++){
      for(int j=0; j<width; j++){
        temp = image[i][j];
        image[i][j] = image[height - 1 - i][j];
        image[height -1 - i][j] = temp;
        
      }
    }
}

/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and swaps the columns horizontally.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void flipHorz(rgb** image,int width,int height){
  rgb temp;
    for(int i=0; i<height; i++){
      for(int j=0; j<width/2; j++){
        temp = image[i][j];
        image[i][j] = image[i][width - 1 - j];
        image[i][width - 1 - j] = temp;
      }
    }
}

/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void grayScale(rgb** image,int width, int height){
    int r,g,b,gray;
    for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
        r = image[i][j].r;
        g = image[i][j].g;
        b = image[i][j].b;
            
        gray = (r+g+b)/3;
        
        image[i][j].r = gray;
        image[i][j].g = gray;
        image[i][j].b = gray;
        
      }
    }
  }
  
int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");   
    int r,g,b,gray;
    
    int width;               //width of image
    int height;              //height of image
    
    rgb **imgArray;         //Pointer var for our 2D array because we         
                            //don't know how big the image will be!

    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size. After we get these two values, we can
                            //now allocate memory for our 2D array.

    imgArray = new rgb*[height];    //This array points to every row

    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
    
    // Flip the image vertically
    flipVert(imgArray, width, height);
    
    // Flip the image horizontally
    flipHorz(imgArray, width, height);
    
    // Grayscale the image
    grayScale(imgArray, width, height);
    
    
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
      for(int j=0;j<width;j++){
        ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
    ofile<<endl;
  }
    
    
  return 0;
}

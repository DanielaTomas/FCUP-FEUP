#include "test.hpp"
define BUFFSIZE 200
struct ppmPixel {
                int R;
                int G;
                int B;
};
typedef struct ppmPixel PPMPIXEL;

struct ppmImage {
    char magicNumber[3];
    int width;
    int height;
    int maxVal;
    PPMPIXEL **mat;
};
typedef struct ppmImage PPMIMAGE;

// additional functions
void failMessage (char *m);
char* read_word(FILE *f);
PPMIMAGE readPPM(FILE *f);
PPMPIXEL readNextPixel (FILE *f);

int main (....) {

    FILE *f1, *f2;
    PPMIMAGE imgA, imgB;
    Read Files....

    imgA = readPPM(f1);
    imgB = rotateImage(imgA);
    writeNewImage(imgB,f2);

    fclose(f1);
    fclose(f2);

    return 0;
}

PPMIMAGE readPPM(FILE *f) {
    char *word;
    PPMIMAGE img;
    int i, j;

    // read magic number
    word = read_word(f);
    if ((word = read_word (f)) == NULL || strcmp(word, "P3") !=0 ) {
        failMessage("error")
    }
    strcpy(img.MagicNumber, word);

    // read width
    // allocate memory for image
    // read pixel
    for(i=0; i<img.height; i++) {
      for(j=0; j<img.width; j++) {
        img.mat[i][j] = readNextPixel(f);
      }
    }
    return img;
}

char* read_word(FILE* f) {
    static char buffer[BUFFSIZE]
    int n;
    n = fscanf(f, "%s", buffer);
    while (n==1 && buffer[0] == '#')  {// discard rest of the line
        while (fgetc(f) !='\n') // continue discarding chars
        n = fscanf(f,"%s",buffer);
    }
    if (n==1) return buffer;  // new word
    return NULL; //failed to read the file
}

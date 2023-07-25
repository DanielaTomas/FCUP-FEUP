// flip horizontal
PPMIMAGE ppm_h_flip(PPMIMAGE img1){
int i,j;
PPMIMAGE img2;
img2 = img1;

 // allocate space for image
if ((img2.mat = (PPMPIXEL **) malloc(img2.height * sizeof(PPMPIXEL *))) == NULL){
 failMessage("Memory allocation failed!!\n");
}
for(i=0; i< img2.height; i++){
if ((img2.mat[i] = (PPMPIXEL *) malloc(img2.width * sizeof(PPMPIXEL))) == NULL){
 failMessage("Memory allocation failed!!\n");
}
}

for(i=0; i< img1.height; i++){
for(j= 0; j<img1.width; j++){
img2.mat[i][j] = img1.mat[i][img1.width-1-j];
}
}
return img2;
}
// write pixels
for(i=0; i< img.height; i++){​​​​​​​​
for(j=0; j<img.width; j++){​​​​​​​​
  fprintf(f,"%d %d %d\n", img.mat[i][j].R, img.mat[i][j].G, img.mat[i][j].B);
}​​​​​​​​
}​​​​​​​
PPMPIXEL readNextPixel(FILE *f){
PPMPIXEL pixel;
char* word;
 // read R
if ((word = read_word(f)) == NULL || sscanf(word, "%d", &pixel.R) !=1 ){
 failMessage("Invalid file format!!\n");
}
 // read G
if ((word = read_word(f)) == NULL || sscanf(word, "%d", &pixel.G) !=1 ){
 failMessage("Invalid file format!!\n");
}
 // read B
if ((word = read_word(f)) == NULL || sscanf(word, "%d", &pixel.B) !=1 ){
 failMessage("Invalid file format!!\n");
}
return pixel;

}

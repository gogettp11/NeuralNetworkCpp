#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
typedef struct Layer{
    float **wieghts;
    float *(*fun)(float);
    int dimx;
    int dimy;
}TypeLay;
float linear(float x){
    return x;
}
float *predict(float*,TypeLay*);
void init(TypeLay *layer);
int main(){
    //int *dim = [2,4,5,6,1];
    int len = 5;

    srand(time(NULL));
    //generating graph
    TypeLay l1;   l1.dimx=2; l1.dimy=4;   l1.wieghts = (float**)malloc(sizeof(float)*4);
    TypeLay l2;   l2.dimx=4; l2.dimy=5;   l2.wieghts = (float**)malloc(sizeof(float)*5);
    TypeLay l3;   l3.dimx=5; l3.dimy=6;   l3.wieghts = (float**)malloc(sizeof(float)*6);
    TypeLay l4;   l4.dimx=6; l4.dimy=1;   l4.wieghts = (float**)malloc(sizeof(float)*1);
    //init
    init(&l1);
    init(&l2);
    init(&l3);
    init(&l4);
    //predict
    float* input = (float*)malloc(2*sizeof(float));
    input[0] = 1.0f;
    input[1] = 2.0f;
    float *values = predict(input,&l1);
    std::cout << values[0] << " " << values[1];
    
    return 0;
}
void init(TypeLay *layer){
    for(int i=0; i<layer->dimy;i++)
        layer->wieghts[i] = (float*) malloc(sizeof(float)*layer->dimx);
    for(int i=0;i<layer->dimx;i++)
        for(int j=0;j<layer->dimy;j++)
            layer->wieghts[j][i] = (float)(rand()%13)/12;
}
float *predict(float *input, TypeLay *layer){

    int outsize = layer->dimx;
    int insize = layer->dimy;
    float *output = (float*) malloc(sizeof(float)*outsize);

    for(int i=0;i<outsize;i++){
        float temp=0;
        for(int j=0;j<insize;j++){
            temp += input[i]*layer->wieghts[i][j];
        }
        output[i] = temp;
    }
    return output;
}   
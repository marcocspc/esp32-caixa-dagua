#define echoPin 14 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 2 //attach pin D3 Arduino to pin Trig of HC-SR04

#define PI 3.14

// Constantes de recipientes que sao troncos de cone
// !!! TODOS OS VALORES SAO EM CENTIMETROS !!!
//h (le-se hzinho) e a altura do recipiente (sem a tampa, se houver)
#define h 58
//R (le-se Rzao) e o raio da parte mais larga do recipiente, comumente a parte de cima
#define R 61
//r (le-se Rzinho) e o raio da parte menor do recipiente, comumente a parte de baixo
#define r 42.5
//ht e a distancia do sensor ultrassonico ate o topo do recipiente + a altura do recipiente.
//Comumente seu valor e o mesmo de h, mas caso o recipiente tenha tampa o sensor pode estar fixado nela.
//Neste caso, pode estar alguns cm acima do topo do recipiente.
// Em outras palavras, pode ser floaterpretado como a altura do recipente com a tampa.
#define ht 58

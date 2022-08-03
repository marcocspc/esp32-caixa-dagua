// defines variables
long duration = 0; // variable for the duration of sound wave travel
float distance = 0; // variable for the distance measurement

// Variaveis de recipientes que sao troncos de cone
// !!! TODOS OS VALORES SAO EM CENTIMETROS !!!
//H (le-se Hzao) eh a altura do cone virtual caso o tronco de cone fosse um cone completo
float H = (h * R) / (R - r);

//Variaveis da wifi
//ssid e senha do AP que o controlador vai usar para se conectar a internet
char* upstream_ssid = "SSID da sua rede";
char* upstream_password = "Senha da sua rede";


## Hardware utilizado:

- Placa com controlador ESP32 Wemos D1 R32.
- Sensor ultrassônico HC-SR04.

## Software Necessário (Dependências)

- Arduino IDE;
- Python3.

## Preparando a IDE Arduino

Instale a IDE Arduino [para sua plataforma](https://www.arduino.cc/en/software).

Após instalada, execute a IDE e vá em (no MAC OS 11) Arduino > Preferences. (Creio que no Windows e Linux deve ser Arquivos > Preferências).

Em "URLs Adicionais para Gerenciadores de Placas", cole a URL `https://dl.espressif.com/dl/package_esp32_index.json` e aperte em OK.

Em seguida, vá em Ferramentas > Placa "Alguma placa" > Gerenciador de Placas. Espere ele recarregar o índice.

Utilizando a barra de busca, digite "ESP32". Deverá aparecer uma entrada esp32 by Espressif Systems. Instale ela e feche o gerenciador.

Após feita a instalação, vá até Ferramentas > Placa "Alguma placa" > ESP32 Arduino e selecione ESP32 Dev Module.

Finalmente, em Ferramentas > Upload Speed, selecione a velocidade 115200. Isto foi necessário para que não haja erros de envio do código.

Quando for utilizar o monitor serial, a velocidade também deve ser 115200. A opção fica no canto inferior direito do monitor serial.

## Solução de Problemas

### Python não encontrado

Quando fui enviar o código pela primeira vez foi retornado pela IDE do arduino o erro de que o python não tinha sido encontrado. Eu estava utilizando o python instalado pelo homebrew e ele funcionava normalmente pela linha de comando, mas não na IDE. A causa do problema é que eu precisava de um executável "python" (e não python3) disponível no path. A solução descrita [aqui](https://stackoverflow.com/questions/71479069/exec-python-executable-file-not-found-in-path) resolveu meu problema.

## Referências

[Wemos R32 with Arduino - Startup Guide!](https://www.hackster.io/NYH-workshop/wemos-r32-with-arduino-startup-guide-7bc841)
[A fatal error occurred: Invalid head of packet (0x01)](https://github.com/espressif/arduino-esp32/issues/5170)
